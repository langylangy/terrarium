#include <stdio.h>
#include <dirent.h>
#include "esp_timer.h"
#include "esp_spiffs.h"
#include "esp_partition.h"

#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_touch_cst816s.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "ds18b20.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "driver/i2c.h"

#include "esp_log.h"
#include "bsp_qmi8658.h"

// #include "qmi8658.h"

#include "lvgl.h"

#include "ui/ui.h"
#include "gauge.h"
#include "demos/lv_demos.h"
#include "owb_gpio.h"

#define EXAMPLE_PIN_NUM_SCLK 39
#define EXAMPLE_PIN_NUM_MOSI 38
#define EXAMPLE_PIN_NUM_MISO 40

#define EXAMPLE_SPI_HOST SPI2_HOST

#define EXAMPLE_I2C_NUM 0 // I2C number
#define EXAMPLE_PIN_NUM_I2C_SDA 48
#define EXAMPLE_PIN_NUM_I2C_SCL 47

#define EXAMPLE_LCD_PIXEL_CLOCK_HZ (80 * 1000 * 1000)

#define EXAMPLE_PIN_NUM_LCD_DC 42
#define EXAMPLE_PIN_NUM_LCD_RST -1
#define EXAMPLE_PIN_NUM_LCD_CS 45

#define EXAMPLE_LCD_CMD_BITS 8
#define EXAMPLE_LCD_PARAM_BITS 8

#define EXAMPLE_LCD_H_RES 240
#define EXAMPLE_LCD_V_RES 320

#define EXAMPLE_PIN_NUM_BK_LIGHT 1

#define LCD_BL_LEDC_TIMER LEDC_TIMER_0
#define LCD_BL_LEDC_MODE LEDC_LOW_SPEED_MODE

#define LCD_BL_LEDC_CHANNEL LEDC_CHANNEL_0
#define LCD_BL_LEDC_DUTY_RES LEDC_TIMER_10_BIT // Set duty resolution to 13 bits
#define LCD_BL_LEDC_DUTY (1024)                // Set duty to 50%. (2 ** 13) * 50% = 4096
#define LCD_BL_LEDC_FREQUENCY (10000)          // Frequency in Hertz. Set frequency at 5 kHz

#define EXAMPLE_LVGL_TICK_PERIOD_MS 2
#define EXAMPLE_LVGL_TASK_MAX_DELAY_MS 500
#define EXAMPLE_LVGL_TASK_MIN_DELAY_MS 1

#define DS18B20_GPIO 10
#define ONE_WIRE_GPIO 10 // <-- TADY DOPLŇ MAKRO

// static owb_rmt_driver_info rmt_driver_info;
static OneWireBus *owb = NULL;
static DS18B20_Info *ds18b20_info = NULL;
lv_obj_t *ui_TempLabel = NULL; // widget pro zobrazení teploty

static const char *TAG = "lvgl_example";
static lv_indev_drv_t indev_drv; // Input device driver (Touch)
static lv_disp_drv_t disp_drv;   /*Descriptor of a display driver*/
static SemaphoreHandle_t lvgl_api_mux = NULL;

esp_lcd_panel_handle_t panel_handle;
esp_lcd_touch_handle_t tp;

SemaphoreHandle_t i2c_mutex;
SemaphoreHandle_t get_i2c_mutex(void);

// void lvgl_qmi8658_ui_init(lv_obj_t *parent);

bool lvgl_lock(int timeout_ms)
{
    // Convert timeout in milliseconds to FreeRTOS ticks
    // If `timeout_ms` is set to -1, the program will block until the condition is met
    const TickType_t timeout_ticks = (timeout_ms == -1) ? portMAX_DELAY : pdMS_TO_TICKS(timeout_ms);
    return xSemaphoreTakeRecursive(lvgl_api_mux, timeout_ticks) == pdTRUE;
}

void lvgl_unlock(void)
{
    xSemaphoreGiveRecursive(lvgl_api_mux);
}

void i2c_mutex_init(void)
{
    i2c_mutex = xSemaphoreCreateMutex();
}

SemaphoreHandle_t get_i2c_mutex(void)
{
    return i2c_mutex;
}

static bool example_notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx)
{
    lv_disp_flush_ready(&disp_drv);
    return false;
}

static void example_increase_lvgl_tick(void *arg)
{
    /* Tell LVGL how many milliseconds has elapsed */
    lv_tick_inc(EXAMPLE_LVGL_TICK_PERIOD_MS);
}

static void example_lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map)
{
    int offsetx1 = area->x1;
    int offsetx2 = area->x2;
    int offsety1 = area->y1;
    int offsety2 = area->y2;
    // copy a buffer's content to a specific area of the display

    esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, color_map);
}

static void example_lvgl_touch_cb(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    uint16_t touchpad_x[1] = {0};
    uint16_t touchpad_y[1] = {0};
    uint8_t touchpad_cnt = 0;
    esp_lcd_touch_read_data(tp);
    /* Get coordinates */
    bool touchpad_pressed = esp_lcd_touch_get_coordinates(tp, touchpad_x, touchpad_y, NULL, &touchpad_cnt, 1);

    if (touchpad_pressed && touchpad_cnt > 0)
    {
        data->point.x = touchpad_x[0];
        data->point.y = touchpad_y[0];
        data->state = LV_INDEV_STATE_PRESSED;
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void lv_port_disp_init(void)
{
    static lv_disp_draw_buf_t draw_buf;
    lv_color_t *buf1 = heap_caps_malloc(EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    assert(buf1);
    lv_color_t *buf2 = heap_caps_malloc(EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    assert(buf2);
    lv_disp_draw_buf_init(&draw_buf, buf1, buf2,
                          EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES); /*Initialize the display buffer*/

    /*-----------------------------------
     * Register the display in LVGL
     *----------------------------------*/

    lv_disp_drv_init(&disp_drv); /*Basic initialization*/

    /*Set up the functions to access to your display*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = EXAMPLE_LCD_H_RES;
    disp_drv.ver_res = EXAMPLE_LCD_V_RES;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = example_lvgl_flush_cb;

    /*Set a display buffer*/
    disp_drv.draw_buf = &draw_buf;

    /*Required for Example 3)*/
    disp_drv.full_refresh = 1;
    // disp_drv.direct_mode = 1;

    /* Fill a memory array with a color if you have GPU.
     * Note that, in lv_conf.h you can enable GPUs that has built-in support in LVGL.
     * But if you have a different GPU you can use with this callback.*/
    // disp_drv.gpu_fill_cb = gpu_fill;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}

void lv_port_indev_init(void)
{
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    // indev_drv.disp = disp;
    indev_drv.read_cb = example_lvgl_touch_cb;
    indev_drv.user_data = tp;

    lv_indev_drv_register(&indev_drv);
}

void display_init(void)
{
    ESP_LOGI(TAG, "SPI BUS init");
    spi_bus_config_t buscfg = {
        .sclk_io_num = EXAMPLE_PIN_NUM_SCLK,
        .mosi_io_num = EXAMPLE_PIN_NUM_MOSI,
        .miso_io_num = EXAMPLE_PIN_NUM_MISO,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 4000,
    };
    ESP_ERROR_CHECK(spi_bus_initialize(EXAMPLE_SPI_HOST, &buscfg, SPI_DMA_CH_AUTO));
    ESP_LOGI(TAG, "Install panel IO");

    esp_lcd_panel_io_handle_t io_handle = NULL;

    esp_lcd_panel_io_spi_config_t io_config = {
        .dc_gpio_num = EXAMPLE_PIN_NUM_LCD_DC,
        .cs_gpio_num = EXAMPLE_PIN_NUM_LCD_CS,
        .pclk_hz = EXAMPLE_LCD_PIXEL_CLOCK_HZ,
        .lcd_cmd_bits = EXAMPLE_LCD_CMD_BITS,
        .lcd_param_bits = EXAMPLE_LCD_PARAM_BITS,
        .spi_mode = 0,
        .trans_queue_depth = 10,
        .on_color_trans_done = example_notify_lvgl_flush_ready,
    };
    // Attach the LCD to the SPI bus
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)EXAMPLE_SPI_HOST, &io_config, &io_handle));

    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = EXAMPLE_PIN_NUM_LCD_RST,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_RGB,
        .bits_per_pixel = 16,
    };
    ESP_LOGI(TAG, "Install ST7789 panel driver");
    ESP_ERROR_CHECK(esp_lcd_new_panel_st7789(io_handle, &panel_config, &panel_handle));

    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_mirror(panel_handle, false, false));
    ESP_ERROR_CHECK(esp_lcd_panel_swap_xy(panel_handle, false));
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));
    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(panel_handle, true));
}

void touch_init(void)
{
    esp_lcd_panel_io_handle_t tp_io_handle = NULL;

    ESP_LOGI(TAG, "Initialize I2C");
    const i2c_config_t i2c_conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = EXAMPLE_PIN_NUM_I2C_SDA,
        .scl_io_num = EXAMPLE_PIN_NUM_I2C_SCL,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 400000,
    };

    /* Initialize I2C */
    ESP_ERROR_CHECK(i2c_param_config(EXAMPLE_I2C_NUM, &i2c_conf));
    ESP_ERROR_CHECK(i2c_driver_install(EXAMPLE_I2C_NUM, i2c_conf.mode, 0, 0, 0));

    ESP_LOGI(TAG, "Initialize touch IO (I2C)");
    esp_lcd_panel_io_i2c_config_t tp_io_config = ESP_LCD_TOUCH_IO_I2C_CST816S_CONFIG();
    tp_io_config.scl_speed_hz = 0;
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_i2c((esp_lcd_i2c_bus_handle_t)EXAMPLE_I2C_NUM, &tp_io_config, &tp_io_handle));

    esp_lcd_touch_config_t tp_cfg = {
        .x_max = EXAMPLE_LCD_V_RES,
        .y_max = EXAMPLE_LCD_H_RES,
        .rst_gpio_num = -1,
        .int_gpio_num = -1,
        .flags = {
            .swap_xy = 0,
            .mirror_x = 0,
            .mirror_y = 0,
        },
    };

    ESP_LOGI(TAG, "Initialize touch controller CST816");
    ESP_ERROR_CHECK(esp_lcd_touch_new_i2c_cst816s(tp_io_handle, &tp_cfg, &tp));
}

void bsp_brightness_init(void)
{
    gpio_set_direction(EXAMPLE_PIN_NUM_BK_LIGHT, GPIO_MODE_OUTPUT);
    gpio_set_level(EXAMPLE_PIN_NUM_BK_LIGHT, 1);

    // Prepare and then apply the LEDC PWM timer configuration
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LCD_BL_LEDC_MODE,
        .timer_num = LCD_BL_LEDC_TIMER,
        .duty_resolution = LCD_BL_LEDC_DUTY_RES,
        .freq_hz = LCD_BL_LEDC_FREQUENCY, // Set output frequency at 5 kHz
        .clk_cfg = LEDC_AUTO_CLK};
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // Prepare and then apply the LEDC PWM channel configuration
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LCD_BL_LEDC_MODE,
        .channel = LCD_BL_LEDC_CHANNEL,
        .timer_sel = LCD_BL_LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = EXAMPLE_PIN_NUM_BK_LIGHT,
        .duty = 0, // Set duty to 0%
        .hpoint = 0};
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
}

void bsp_brightness_set_level(uint8_t level)
{
    if (level > 100)
    {
        ESP_LOGE(TAG, "Brightness value out of range");
        return;
    }

    uint32_t duty = (level * (LCD_BL_LEDC_DUTY - 1)) / 100;

    ESP_ERROR_CHECK(ledc_set_duty(LCD_BL_LEDC_MODE, LCD_BL_LEDC_CHANNEL, duty));
    ESP_ERROR_CHECK(ledc_update_duty(LCD_BL_LEDC_MODE, LCD_BL_LEDC_CHANNEL));

    ESP_LOGI(TAG, "LCD brightness set to %d%%", level);
}

void lvgl_tick_timer_init(uint32_t ms)
{
    ESP_LOGI(TAG, "Install LVGL tick timer");
    // Tick interface for LVGL (using esp_timer to generate 2ms periodic event)
    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &example_increase_lvgl_tick,
        .name = "lvgl_tick"};
    esp_timer_handle_t lvgl_tick_timer = NULL;
    ESP_ERROR_CHECK(esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(lvgl_tick_timer, ms * 1000));
}

static void task(void *param)
{
    // ESP_LOGI(TAG, "run");
    while (1)
    {
        uint32_t task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
        while (1)
        {
            // Lock the mutex due to the LVGL APIs are not thread-safe
            if (lvgl_lock(-1))
            {
                task_delay_ms = lv_timer_handler();
                // Release the mutex
                lvgl_unlock();
            }
            if (task_delay_ms > EXAMPLE_LVGL_TASK_MAX_DELAY_MS)
            {
                task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
            }
            else if (task_delay_ms < EXAMPLE_LVGL_TASK_MIN_DELAY_MS)
            {
                task_delay_ms = EXAMPLE_LVGL_TASK_MIN_DELAY_MS;
            }
            vTaskDelay(pdMS_TO_TICKS(task_delay_ms));

            static uint32_t last_ram_check = 0;
            uint32_t current_time = esp_timer_get_time() / 1000000; // Convert to seconds
            if (current_time - last_ram_check >= 5)
            {
                ESP_LOGI(TAG, "Free RAM: %lu bytes", esp_get_free_heap_size());
                last_ram_check = current_time;
            }
        }
    }
}

static void speed_demo_cb(lv_timer_t *timer)
{
    static float speed = 0.0f;
    static bool increasing = true;

    gauge_set_speed(speed);

    if (increasing)
    {
        speed += 0.25f;
        if (speed >= GAUGE_SPEED_MAX)
        {
            increasing = false;
        }
    }
    else
    {
        speed -= 0.25f;
        if (speed <= 0)
        {
            increasing = true;
        }
    }

    // ESP_LOGI(TAG, "Speed: %.1f", speed);
}
// ------------------------
// VLOŽ TOHLE NAD app_main()
// ------------------------
void ds18b20_task(void *pvParameters)
{
    UBaseType_t watermark = uxTaskGetStackHighWaterMark(NULL);
    ESP_LOGI("STACK", "Stack min free: %u words", (unsigned int)watermark);
    while (1)
    {
        ds18b20_convert_all(owb);
        vTaskDelay(pdMS_TO_TICKS(750)); // Počkej na konverzi

        float temp = 0;
        ds18b20_read_temp(ds18b20_info, &temp);
        ESP_LOGI("DS18B20", "Teplota: %.2f °C", temp);

        if (lvgl_lock(50))
        {
            if (ui_TempLabel != NULL)
            {
                // lv_label_set_text_fmt(ui_TempLabel, "Teplota: %.2f °C", temp);
                char buf[32];
                snprintf(buf, sizeof(buf), "Teplota: %.2f °C", temp);
                lv_label_set_text(ui_TempLabel, buf);
                gauge_set_speed((int)temp);
            }
            lvgl_unlock();
        }
        vTaskDelay(pdMS_TO_TICKS(1000)); // Pauza mezi cykly
    }
}
static owb_gpio_driver_info gpio_driver_info;

void ds18b20_init_sensor()
{
    owb = owb_gpio_initialize(&gpio_driver_info, ONE_WIRE_GPIO); // ← místo owb_rmt_initialize
    owb_use_crc(owb, true);

    OneWireBus_ROMCode rom_code;
    owb_read_rom(owb, &rom_code);

    ds18b20_info = ds18b20_malloc();
    ds18b20_init(ds18b20_info, owb, rom_code);
    ds18b20_use_crc(ds18b20_info, true);
}

void app_main(void)
{

    i2c_mutex_init();
    lvgl_api_mux = xSemaphoreCreateRecursiveMutex();
    lv_init();
    display_init();
    touch_init();
    bsp_qmi8658_init();
    lv_port_disp_init();
    lv_port_indev_init();
    lvgl_tick_timer_init(EXAMPLE_LVGL_TICK_PERIOD_MS);
    xTaskCreatePinnedToCore(task, "bsp_lv_port_task", 1024 * 20, NULL, 5, NULL, 1);
    bsp_brightness_init();
    bsp_brightness_set_level(50);
    // imu_fusion_init(0.35f, 0.60f);

    if (lvgl_lock(-1))
    {
        lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), LV_PART_MAIN);
        lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, LV_PART_MAIN);
        // show_boot_gif(); /* přehraj startovní animaci */
        lv_tick_inc(EXAMPLE_LVGL_TICK_PERIOD_MS);
        lv_timer_handler();

        // lvgl_qmi8658_ui_init(lv_scr_act());
        // lv_demo_widgets();
        // lv_demo_benchmark();
        // lv_demo_keypad_encoder();
        // lv_demo_music();
        // lv_demo_stress();

        ui_init();
        ui_TempLabel = lv_label_create(lv_scr_act());
        lv_label_set_text(ui_TempLabel, "Teplota: -- °C");
        lv_obj_align(ui_TempLabel, LV_ALIGN_BOTTOM_LEFT, 10, -20);
        lvgl_unlock();
    }

    // lv_timer_create(speed_demo_cb, 50, NULL);

    // vytvoření LVGL widgetu pro teplotu
    // ui_TempLabel = lv_label_create(lv_scr_act());
    // lv_label_set_text(ui_TempLabel, "Teplota: -- °C");
    // lv_obj_align(ui_TempLabel, LV_ALIGN_BOTTOM_LEFT, 10, -20);

    // // inicializace senzoru a spuštění úlohy
    ds18b20_init_sensor();
    xTaskCreatePinnedToCore(ds18b20_task, "ds18b20_task", 8192, NULL, 5, NULL, 1);
    // }
}

lv_obj_t *label_accel_x;
lv_obj_t *label_accel_y;
lv_obj_t *label_accel_z;
lv_obj_t *label_gyro_x;
lv_obj_t *label_gyro_y;
lv_obj_t *label_gyro_z;

lv_timer_t *qmi8658_timer = NULL;

// static uint64_t last_time_us = 0;
void button11(lv_event_t *e)
{
    // todo
}
static void qmi8658_callback(lv_timer_t *timer)
{
    qmi8658_data_t data;
    bsp_qmi8658_read_data(&data);

    // uint64_t now_us = esp_timer_get_time();
    // float dt = (last_time_us == 0) ? 0.01f : (now_us - last_time_us) / 1e6f;
    // last_time_us = now_us;

    // imu_fusion_update(&data, dt);

    // imu_state_t st;
    // imu_fusion_get(&st);

    lv_bar_set_value(ui_AccelX, data.acc_x, LV_ANIM_OFF);
    lv_bar_set_value(ui_AccelY, data.acc_y, LV_ANIM_OFF);
    lv_bar_set_value(ui_AccelZ, data.acc_z, LV_ANIM_OFF);
    lv_bar_set_value(ui_GyroX, data.gyr_x, LV_ANIM_OFF);
    lv_bar_set_value(ui_GyroY, data.gyr_y, LV_ANIM_OFF);
    lv_bar_set_value(ui_GyroZ, data.gyr_z, LV_ANIM_OFF);
    // lv_bar_set_value(ui_Roll, data.roll_acc * 57.29578f, LV_ANIM_OFF);
    // lv_bar_set_value(ui_Pitch, data.pitch_acc * 57.29578f, LV_ANIM_OFF);
    // lv_bar_set_value(ui_Yaw, data.yaw_acc * 57.29578f, LV_ANIM_OFF);

    // ESP_LOGI("IMU", "Roll: %.2f, Pitch: %.2f, Yaw: %.2f",
    //          st.roll * 57.29578f,
    //          st.pitch * 57.29578f,
    //          st.yaw * 57.29578f);

    ESP_LOGI("IMU", "Accel: \tx=%.2f \ty=%.2f \tz=%.2f, gyr: \tx=%.2f \ty=%.2f \tz=%.2f, \tTemp=%.2f",

             (float)data.acc_x, (float)data.acc_y, (float)data.acc_z,
             (float)data.gyr_x, (float)data.gyr_y, (float)data.gyr_z,
             (float)data.temp);
}

void AccelScreenLoadEvent(lv_event_t *e)
{
    qmi8658_timer = lv_timer_create(qmi8658_callback, 25, NULL);
}
void AccelScreenUnloadEvent(lv_event_t *e)
{
    lv_timer_del(qmi8658_timer);
    qmi8658_timer = NULL;
}
