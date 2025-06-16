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
#include "driver/ledc.h"
#include "driver/i2c.h"

#include "esp_log.h"
#include "bsp_qmi8658.h"

// #include "qmi8658.h"

#include "lvgl.h"

#include "ui/ui.h"
// #include "gauge.h"
#include "demos/lv_demos.h"
#include "owb_gpio.h"

// Přidej tyto hlavičky
#include "esp_wifi.h"
#include "esp_event.h"
#include "freertos/event_groups.h"

#include "nvs_flash.h"
// #include "protocol_examples_common.h"
#include "esp_sntp.h"
#include "dusk2dawn.h"
#include <time.h>
#include "dht.h"
#include "esp_http_server.h"
// #include <Update.h>

#include "esp_log.h"
#include "esp_netif.h"

#include "esp_system.h"

#include "esp_partition.h"
#include "esp_ota_ops.h"
#include "nvs_lib.h"

#define OTA_BUFF_SIZE 1024

// #define WIFI_SSID "BERYKO-HOST"
// #define WIFI_PASS "beryko22"

#define WIFI_SSID "AMF"
#define WIFI_PASS "AMF130+-"

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
#define ONE_WIRE_GPIO 10  // <-- TADY DOPLŇ MAKRO
#define THERMOSTAT_GPIO 9 // výstupní pin pro relé/topení
#define LIGHT_GPIO 8      // můžeš změnit na libovolný GPIO
#define DHT_GPIO 7        // nebo libovolný použitý GPIO

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static float thermostat_threshold = 30.0f; // výchozí hodnota
#define SLEEP_TIME 40000                   // 20 sekund v milisekundách
static bool is_dimmed = false;
static int stored_brightness = 50; // výchozí jas

// static owb_rmt_driver_info rmt_driver_info;
static OneWireBus *owb = NULL;
static DS18B20_Info *ds18b20_info = NULL;
lv_obj_t *ui_TempLabel = NULL; // widget pro zobrazení teploty

static const char *TAG = "lvgl_example";
static lv_indev_drv_t indev_drv; // Input device driver (Touch)
static lv_disp_drv_t disp_drv;   /*Descriptor of a display driver*/
static SemaphoreHandle_t lvgl_api_mux = NULL;

float g_temperature_ds18b20 = 0;
float g_temperature_dht22 = 0;
float g_humidity_dht22 = 0;
bool g_light_on = false;
bool g_heating_on = false;

static const char *TAGWEB = "web";
httpd_handle_t server = NULL;

// Mutex (volitelné, doporučeno pro vícejádrové zápisy)
SemaphoreHandle_t data_mutex;

esp_lcd_panel_handle_t panel_handle;
esp_lcd_touch_handle_t tp;

SemaphoreHandle_t i2c_mutex;
SemaphoreHandle_t get_i2c_mutex(void);
int on_time_hours = 5; // délka svícení

static EventGroupHandle_t wifi_event_group;
#define WIFI_CONNECTED_BIT BIT0

static esp_err_t root_get_handler(httpd_req_t *req)
{
    const char *html =
        "<!DOCTYPE html>"
        "<html lang=\"cs\">"
        "<head>"
        "<meta charset=\"UTF-8\">"
        "<title>Aktualizace firmware (OTA)</title>"
        "<style>"
        "body { font-family: sans-serif; background: #f4f4f4; padding: 20px; }"
        "h1 { color: #333; }"
        "#status { margin-top: 15px; font-weight: bold; }"
        "button { padding: 10px 20px; font-size: 16px; }"
        "#overlay {"
        "  display: none;"
        "  position: fixed;"
        "  top: 0; left: 0; width: 100%; height: 100%;"
        "  background: rgba(0, 0, 0, 0.7);"
        "  z-index: 1000;"
        "  "
        "  justify-content: center;"
        "  align-items: center;"
        "  flex-direction: column;"
        "  color: #fff;"
        "  font-size: 18px;"
        "}"
        "#loader {"
        "  border: 8px solid #f3f3f3;"
        "  border-top: 8px solid #3498db;"
        "  border-radius: 50%;"
        "  width: 60px;"
        "  height: 60px;"
        "  animation: spin 1s linear infinite;"
        "  margin-bottom: 15px;"
        "}"
        "@keyframes spin {"
        "  0% { transform: rotate(0deg); }"
        "  100% { transform: rotate(360deg); }"
        "}"
        "</style>"
        "</head>"
        "<body>"
        "<h1>Aktualizace firmware</h1>"
        "<input type=\"file\" id=\"fileInput\"><br><br>"
        "<button onclick=\"upload()\">Nahrát firmware</button>"
        "<div id=\"status\"></div>"

        "<div id=\"overlay\">"
        "  <div id=\"loader\"></div>"
        "  <div id=\"progressText\">Nahrávání... 0 %</div>"
        "</div>"

        "<script>"
        "function upload() {"
        "  const fileInput = document.getElementById('fileInput');"
        "  const status = document.getElementById('status');"
        "  const overlay = document.getElementById('overlay');"
        "  const progressText = document.getElementById('progressText');"
        "  const file = fileInput.files[0];"
        "  if (!file) { alert('Vyberte soubor s firmwarem'); return; }"

        "  overlay.style.display = 'flex';"
        "  progressText.innerText = 'Nahrávání... 0 %';"

        "  const xhr = new XMLHttpRequest();"
        "  xhr.open('POST', '/update', true);"
        "  xhr.setRequestHeader('Content-Type', 'application/octet-stream');"

        "  xhr.upload.onprogress = function(event) {"
        "    if (event.lengthComputable) {"
        "      const percent = Math.round((event.loaded / event.total) * 100);"
        "      progressText.innerText = 'Nahrávání... ' + percent + ' %';"
        "    }"
        "  };"

        "  xhr.onload = function() {"
        "    overlay.style.display = 'none';"
        "    status.innerText = 'Úspěch: ' + xhr.responseText;"
        "  };"

        "  xhr.onerror = function() {"
        "    overlay.style.display = 'none';"
        "    status.innerText = 'Chyba při nahrávání';"
        "  };"

        "  xhr.send(file);"
        "}"
        "</script>"
        "</body>"
        "</html>";

    httpd_resp_send(req, html, HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

// POST endpoint – zatím jen potvrzení (bez OTA)
static esp_err_t update_post_handler(httpd_req_t *req)
{
    char ota_buff[OTA_BUFF_SIZE]; // buffer pro příjem dat
    int remaining = req->content_len;
    int received;
    const esp_partition_t *ota_partition = esp_ota_get_next_update_partition(NULL);
    if (!ota_partition)
    {
        ESP_LOGE(TAGWEB, "Nelze najít OTA partition");
        httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "OTA partition nenalezena");
        return ESP_FAIL;
    }

    ESP_LOGI(TAGWEB, "Zahajuji OTA zápis do partition %s", ota_partition->label);

    esp_ota_handle_t ota_handle;
    esp_err_t err = esp_ota_begin(ota_partition, OTA_SIZE_UNKNOWN, &ota_handle);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAGWEB, "esp_ota_begin chyba: %s", esp_err_to_name(err));
        httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Chyba při zahájení OTA");
        return ESP_FAIL;
    }

    while (remaining > 0)
    {
        received = httpd_req_recv(req, ota_buff, MIN(remaining, OTA_BUFF_SIZE));
        ESP_LOGI(TAGWEB, "Přijato %d bajtů, zbývá %d", received, remaining);

        if (received <= 0)
        {
            ESP_LOGE(TAGWEB, "Chyba při čtení OTA dat");
            esp_ota_end(ota_handle);
            httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Chyba při čtení dat");
            return ESP_FAIL;
        }

        err = esp_ota_write(ota_handle, ota_buff, received);
        if (err != ESP_OK)
        {
            ESP_LOGE(TAGWEB, "esp_ota_write chyba: %s (err=0x%x)", esp_err_to_name(err), err);
            esp_ota_end(ota_handle);
            httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Chyba při zápisu OTA");
            return ESP_FAIL;
        }

        remaining -= received;
    }

    err = esp_ota_end(ota_handle);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAGWEB, "esp_ota_end chyba: %s", esp_err_to_name(err));
        httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Chyba při ukončení OTA");
        return ESP_FAIL;
    }

    err = esp_ota_set_boot_partition(ota_partition);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAGWEB, "esp_ota_set_boot_partition chyba: %s", esp_err_to_name(err));
        httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Nelze nastavit boot partition");
        return ESP_FAIL;
    }

    ESP_LOGI(TAGWEB, "OTA aktualizace dokončena, restartuji...");
    httpd_resp_sendstr(req, "Update proběhl úspěšně. Zařízení se restartuje.");
    vTaskDelay(pdMS_TO_TICKS(1000));
    esp_restart();
    return ESP_OK;
}

// Spuštění serveru
void start_webserver(void)
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.max_uri_handlers = 12;
    // config.max_req_hdr_len = 1024; // Výchozí je 512, zvýšit např. na 1024
    config.max_resp_headers = 16;
    config.stack_size = 8192;

    if (httpd_start(&server, &config) == ESP_OK)
    {
        httpd_uri_t root_uri = {
            .uri = "/",
            .method = HTTP_GET,
            .handler = root_get_handler};
        httpd_register_uri_handler(server, &root_uri);

        httpd_uri_t update_uri = {
            .uri = "/update",
            .method = HTTP_POST,
            .handler = update_post_handler};
        httpd_register_uri_handler(server, &update_uri);

        ESP_LOGI(TAGWEB, "HTTP server spuštěn");
    }
}

static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
    {
        esp_wifi_connect();
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    {
        esp_wifi_connect();
    }
    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        xEventGroupSetBits(wifi_event_group, WIFI_CONNECTED_BIT);
        ESP_LOGI("WIFI", "Připojeno!");
        start_webserver();
    }
}

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

    // PWM duty = 0–1023 pro 10bit (LEDC_TIMER_10_BIT)
    uint32_t max_duty = (1 << LCD_BL_LEDC_DUTY_RES) - 1;
    uint32_t duty = (level * max_duty) / 100;

    ESP_ERROR_CHECK(ledc_set_duty(LCD_BL_LEDC_MODE, LCD_BL_LEDC_CHANNEL, duty));
    ESP_ERROR_CHECK(ledc_update_duty(LCD_BL_LEDC_MODE, LCD_BL_LEDC_CHANNEL));

    ESP_LOGI(TAG, "LCD brightness set to %d%% (duty = %lu)", level, duty);
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
void initialize_wifi(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = WIFI_SSID,
            .password = WIFI_PASS,
            .threshold.authmode = WIFI_AUTH_WPA2_PSK,
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));

    // vytvoření event group a registrace handleru
    wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &wifi_event_handler,
                                                        NULL,
                                                        NULL));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        &wifi_event_handler,
                                                        NULL,
                                                        NULL));

    ESP_ERROR_CHECK(esp_wifi_start());
    ESP_LOGI("WIFI", "Wi-Fi inicializace dokončena");
}

void initialize_sntp(void)
{
    ESP_LOGI("SNTP", "Inicializuji SNTP");
    esp_sntp_setoperatingmode(SNTP_OPMODE_POLL);
    esp_sntp_setservername(0, "pool.ntp.org");
    esp_sntp_init();
}

void obtain_time(void)
{
    initialize_sntp();
    setenv("TZ", "CET-1CEST,M3.5.0/2,M10.5.0/3", 1);
    tzset();
    time_t now = 0;
    struct tm timeinfo = {0};
    int retry = 0;
    const int retry_count = 10;

    while (timeinfo.tm_year < (2016 - 1900) && ++retry < retry_count)
    {
        ESP_LOGI("SNTP", "Čekám na čas (%d/%d)...", retry, retry_count);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        time(&now);
        localtime_r(&now, &timeinfo);
    }
    if (retry < retry_count)
    {
        ESP_LOGI("SNTP", "Čas synchronizován: %s", asctime(&timeinfo));
    }
    else
    {
        ESP_LOGW("SNTP", "Nepodařilo se synchronizovat čas");
    }
}

void print_current_time(void)
{
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);
    ESP_LOGI("TIME", "Aktuální čas: %02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);

    char time_str[6]; // hh:mm + \0
    snprintf(time_str, sizeof(time_str), "%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min);

    lv_label_set_text(ui_timeNTP, time_str);
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
void thermostat_set_threshold(float new_threshold)
{
    thermostat_threshold = new_threshold;
    ESP_LOGI("THERMOSTAT", "Nový práh: %.1f °C", new_threshold);
}
// ------------------------
// VLOŽ TOHLE NAD app_main()
void screenTouch_task(void *pvParameters)
{
    ESP_LOGI(TAG, "Spouštím task pro touch");
    while (1)
    {
        if (lv_disp_get_inactive_time(NULL) > SLEEP_TIME)
        {
            if (!is_dimmed)
            {
                bsp_brightness_set_level(0); // vypni podsvícení
                is_dimmed = true;
                ESP_LOGI("SLEEP", "Displej zhasnut po %d ms nečinnosti", SLEEP_TIME);
            }
        }
        else
        {
            if (is_dimmed)
            {
                bsp_brightness_set_level(stored_brightness); // obnov podsvícení
                is_dimmed = false;
                ESP_LOGI("SLEEP", "Displej rozsvícen");
            }
        }
        float t_ds18b20, t_dht, h_dht;
        bool heating, light;

        if (xSemaphoreTake(data_mutex, pdMS_TO_TICKS(10)))
        {
            t_ds18b20 = g_temperature_ds18b20;
            t_dht = g_temperature_dht22;
            h_dht = g_humidity_dht22;
            heating = g_heating_on;
            light = g_light_on;
            xSemaphoreGive(data_mutex);

            // Aktualizace LVGL widgetů
            char buf[32];
            snprintf(buf, sizeof(buf), "%.1f", t_ds18b20);
            lv_label_set_text(ui_temperatureTerraBoard, buf);
            lv_arc_set_value(ui_Arc1, (int16_t)t_ds18b20);
            snprintf(buf, sizeof(buf), "%.1f", t_dht);
            lv_label_set_text(ui_temperatureTerra, buf);  // přidej vlastní label
            lv_label_set_text(ui_temperatureTerra1, buf); // přidej vlastní label
            // lv_arc_set_value(ui_Arc3, (int16_t)t_dht);
            snprintf(buf, sizeof(buf), "%d", (int16_t)h_dht);
            lv_label_set_text(ui_humityTerra, buf);
            lv_label_set_text(ui_humityTerra1, buf);
            lv_arc_set_value(ui_Arc4, (int16_t)h_dht);

            if (heating)
                lv_obj_clear_flag(ui_labelPHBicoHeating, LV_OBJ_FLAG_HIDDEN);
            else
                lv_obj_add_flag(ui_labelPHBicoHeating, LV_OBJ_FLAG_HIDDEN);
        }
        // if (light)
        //     lv_obj_clear_flag(ui_labelPHBicoSun, LV_OBJ_FLAG_HIDDEN);
        // else
        //     lv_obj_add_flag(ui_labelPHBicoSun, LV_OBJ_FLAG_HIDDEN);
        vTaskDelay(pdMS_TO_TICKS(100)); // Pauza mezi cykly
    }
}
// ------------------------

void dask2down_task(void *pvParameters)
{
    Dusk2Dawn praha;
    Dusk2Dawn_init(&praha, 50.0755, 14.4378, 2.0); // latitude, longitude, timezone

    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << LIGHT_GPIO),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_conf);
    gpio_set_level(LIGHT_GPIO, 0); // výchozí stav – světlo vypnuto

    while (1)
    {
        time_t now = time(NULL);
        struct tm timeinfo;
        localtime_r(&now, &timeinfo);

        int year = timeinfo.tm_year + 1900;
        int month = timeinfo.tm_mon + 1;
        int day = timeinfo.tm_mday;

        bool isDST = timeinfo.tm_isdst > 0;

        int sunrise = Dusk2Dawn_sunrise(&praha, year, month, day, isDST);
        int sunset = Dusk2Dawn_sunset(&praha, year, month, day, isDST);

        int nowMinutes = timeinfo.tm_hour * 60 + timeinfo.tm_min;

        if (sunrise >= 0 && sunset >= 0)
        {
            if (nowMinutes >= sunrise && nowMinutes < sunset)
            {
                gpio_set_level(LIGHT_GPIO, 1); // DEN – zapnout světlo
                ESP_LOGI("LIGHT", "DEN – světlo ZAPNUTO (%02d:%02d)", timeinfo.tm_hour, timeinfo.tm_min);
            }
            else
            {
                gpio_set_level(LIGHT_GPIO, 0); // NOC – vypnout světlo
                ESP_LOGI("LIGHT", "NOC – světlo VYPNUTO (%02d:%02d)", timeinfo.tm_hour, timeinfo.tm_min);
            }
        }
        else
        {
            gpio_set_level(LIGHT_GPIO, 0); // bezpečné vypnutí
            ESP_LOGW("LIGHT", "Není možné spočítat východ/západ (např. polární den/noc)");
        }

        vTaskDelay(pdMS_TO_TICKS(60000)); // každou minutu
    }
}

void dht_task(void *pvParameter)
{
    float temperature = 0, humidity = 0;
    esp_err_t res;

    while (1)
    {
        res = dht_read_float_data(DHT_TYPE_AM2301, DHT_GPIO, &humidity, &temperature);
        if (res == ESP_OK)
        {
            ESP_LOGI(TAG, "Teplota: %.1f °C, Vlhkost: %.1f %%", temperature, humidity);
        }
        else
        {
            ESP_LOGE(TAG, "Chyba čtení z DHT22: %s", esp_err_to_name(res));
        }
        if (xSemaphoreTake(data_mutex, pdMS_TO_TICKS(10)))
        {
            g_temperature_dht22 = temperature;
            g_humidity_dht22 = humidity;
            xSemaphoreGive(data_mutex);
        }
        vTaskDelay(pdMS_TO_TICKS(2000)); // každé 2 sekundy
    }
}
void ds18b20_task(void *pvParameters)
{
    UBaseType_t watermark = uxTaskGetStackHighWaterMark(NULL);
    bool is_heating_on = false;
    float temp = 0;
    time_t now;
    struct tm timeinfo;

    while (1)
    {
        // Spuštění konverze
        ds18b20_convert_all(owb);
        vTaskDelay(pdMS_TO_TICKS(800)); // čekání na dokončení (800 ms je běžné)

        // Přečtení teploty
        if (ds18b20_read_temp(ds18b20_info, &temp) == ESP_OK)
        {
            ESP_LOGI("STACK", "Stack min free: %u words", (unsigned int)watermark);
            print_current_time();
            ESP_LOGI("DS18B20", "Teplota: %.2f °C", temp);

            time(&now);
            localtime_r(&now, &timeinfo);

            // Aktualizace sdílených proměnných
            if (xSemaphoreTake(data_mutex, pdMS_TO_TICKS(10)))
            {
                g_temperature_ds18b20 = temp;
                g_heating_on = is_heating_on;
                xSemaphoreGive(data_mutex);
            }

            // Logika termostatu s hysterezí 3°C
            if (!is_heating_on && temp <= (thermostat_threshold - 3) &&
                timeinfo.tm_hour >= 5 && timeinfo.tm_hour < 20)
            {
                gpio_set_level(THERMOSTAT_GPIO, 1);
                ESP_LOGI("THERMOSTAT", "ZAPNUTO: %.1f °C ≤ %.1f °C, čas OK", temp, thermostat_threshold - 3);
                is_heating_on = true;
            }
            else if (is_heating_on &&
                     (temp >= thermostat_threshold ||
                      timeinfo.tm_hour < 5 || timeinfo.tm_hour >= 20))
            {
                gpio_set_level(THERMOSTAT_GPIO, 0);
                ESP_LOGI("THERMOSTAT", "VYPNUTO: %.1f °C ≥ %.1f °C nebo čas mimo", temp, thermostat_threshold);
                is_heating_on = false;
            }
        }
        else
        {
            ESP_LOGW("DS18B20", "Chyba čtení teploty");
        }

        vTaskDelay(pdMS_TO_TICKS(2000)); // hlavní smyčka běží každé 2 sekundy
    }
}

// void ds18b20_task(void *pvParameters)
// {
//     UBaseType_t watermark = uxTaskGetStackHighWaterMark(NULL);
//     bool is_heating_on = false; // proměnná pro sledování stavu topení

//     int conversionSkip = 0;
//     int conversionDelay = 0;
//     float temp = 0;
//     time_t now;
//     struct tm timeinfo;

//     while (1)
//     {

//         if (conversionSkip == 0) // pouze jednou za X cyklů
//         {
//             ds18b20_convert_all(owb);
//             conversionSkip = 1;  // nastav, že čekáme na výsledek
//             conversionDelay = 0; // resetuj počítadlo čekání
//         }
//         else if (conversionSkip == 1)
//         {
//             // čekáme na dokončení konverze
//             if (conversionDelay >= 4) // 4x 200ms = 800ms (přizpůsobte podle potřeby)
//             {
//                 ESP_LOGI("STACK", "Stack min free: %u words", (unsigned int)watermark);
//                 print_current_time();

//                 ds18b20_read_temp(ds18b20_info, &temp);
//                 ESP_LOGI("DS18B20", "Teplota: %.2f °C", temp);

//                 time(&now);
//                 localtime_r(&now, &timeinfo);

//                 conversionSkip = 0; // připrav na další cyklus
//             }
//             else
//             {
//                 conversionDelay++;
//             }
//         }

//         if (ui_temperatureTerra != NULL && temp > 0)
//         {
//             if (xSemaphoreTake(data_mutex, pdMS_TO_TICKS(10)))
//             {
//                 g_temperature_ds18b20 = temp;
//                 g_heating_on = is_heating_on;
//                 xSemaphoreGive(data_mutex);
//             }
//             // lv_label_set_text_fmt(ui_TempLabel, "Teplota: %.2f °C", temp);
//             char buf[32];
//             snprintf(buf, sizeof(buf), "Teplota: %.2f °C", temp);
//             char tempBig[8];
//             snprintf(tempBig, sizeof(tempBig), "%.1f", temp);

//             // Podmínka pro termostat s hysterezí 3°C
//             if (!is_heating_on && temp <= (thermostat_threshold - 3) && timeinfo.tm_hour >= 5 && timeinfo.tm_hour < 20)
//             {
//                 gpio_set_level(THERMOSTAT_GPIO, 1); // zapnout výstup
//                 ESP_LOGI("THERMOSTAT", "TEPLO: %.1f °C ≤ %.1f °C (práh-3) a čas mezi 5:00–20:00 → ZAPNUTO", temp, thermostat_threshold - 3);
//                 is_heating_on = true;
//             }
//             else if (is_heating_on && (temp >= thermostat_threshold || timeinfo.tm_hour < 5 || timeinfo.tm_hour >= 20))
//             {
//                 gpio_set_level(THERMOSTAT_GPIO, 0); // vypnout výstup
//                 ESP_LOGI("THERMOSTAT", "Podmínky pro vypnutí (%.1f °C ≥ %.1f °C nebo mimo 5:00–20:00) → VYPNUTO", temp, thermostat_threshold);
//                 is_heating_on = false; // aktualizace stavu topení
//             }
//             // gauge_set_speed((int)temp);
//         }
//     }
//     vTaskDelay(pdMS_TO_TICKS(1000)); // Pauza mezi cykly
// }
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
void slider1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *slider = lv_event_get_target(e);

    if (code == LV_EVENT_VALUE_CHANGED)
    {
        stored_brightness = lv_slider_get_value(slider);
        nvs_save_int("brightness", stored_brightness);
        bsp_brightness_set_level(stored_brightness); // <- vlastní funkce
        char buf[32];
        snprintf(buf, sizeof(buf), "%.0d", stored_brightness);
        lv_label_set_text(ui_Label9, buf);
    }
}
void slider2_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *slider = lv_event_get_target(e);

    if (code == LV_EVENT_VALUE_CHANGED)
    {
        thermostat_threshold = lv_slider_get_value(slider);
        nvs_save_float("thermostat", thermostat_threshold);
        char buf[32];
        snprintf(buf, sizeof(buf), "%.0f", thermostat_threshold);
        lv_label_set_text(ui_Label1, buf);
    }
}
void light_control_task(void *pvParameters)
{
    const int start_hour = 8; // čas zapnutí (např. 8:00)

    while (1)
    {
        time_t now;
        struct tm timeinfo;
        time(&now);
        localtime_r(&now, &timeinfo);

        int current_hour = timeinfo.tm_hour;
        int light_on_end = start_hour + on_time_hours;

        bool light_should_be_on = (current_hour >= start_hour && current_hour < light_on_end);

        gpio_set_level(LIGHT_GPIO, light_should_be_on ? 1 : 0);

        ESP_LOGI(TAG, "Time: %02d:%02d, light %s", timeinfo.tm_hour, timeinfo.tm_min, light_should_be_on ? "ON" : "OFF");

        vTaskDelay(pdMS_TO_TICKS(60000)); // kontrola každou minutu
    }
}

void app_main(void)
{
    // Inicializuj NVS
    esp_err_t err = nvs_lib_init();
    if (err != ESP_OK)
    {
        printf("NVS init failed: %s\\n", esp_err_to_name(err));
        return;
    }
    stored_brightness = nvs_load_int_default("brightness", 50);
    thermostat_threshold = nvs_load_float_default("thermostat", 30);
    char buf[32];
    data_mutex = xSemaphoreCreateMutex();
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
    bsp_brightness_set_level(stored_brightness);
    // imu_fusion_init(0.35f, 0.60f);
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << THERMOSTAT_GPIO),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_conf);
    gpio_set_level(THERMOSTAT_GPIO, 0); // výchozí stav: vypnuto
    initialize_wifi();

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
        lvgl_unlock();
    }
    snprintf(buf, sizeof(buf), "%.0d", stored_brightness);
    lv_label_set_text(ui_Label9, buf);
    snprintf(buf, sizeof(buf), "%.0f", thermostat_threshold);
    lv_label_set_text(ui_Label1, buf);
    lv_slider_set_value(ui_Slider1, stored_brightness, LV_ANIM_OFF);
    lv_obj_add_event_cb(ui_Slider1, slider1_event_handler, LV_EVENT_VALUE_CHANGED, NULL);

    lv_slider_set_value(ui_Slider2, thermostat_threshold, LV_ANIM_OFF);
    lv_obj_add_event_cb(ui_Slider2, slider2_event_handler, LV_EVENT_VALUE_CHANGED, NULL);

    obtain_time();
    // lv_timer_create(speed_demo_cb, 50, NULL);

    // vytvoření LVGL widgetu pro teplotu
    // ui_TempLabel = lv_label_create(lv_scr_act());
    // lv_label_set_text(ui_TempLabel, "Teplota: -- °C");
    // lv_obj_align(ui_TempLabel, LV_ALIGN_BOTTOM_LEFT, 10, -20);

    // // inicializace senzoru a spuštění úlohy
    ds18b20_init_sensor();
    xTaskCreatePinnedToCore(ds18b20_task, "ds18b20_task", 8192, NULL, 5, NULL, 1);
    xTaskCreatePinnedToCore(screenTouch_task, "screenTouch_task", 8192, NULL, 5, NULL, 1);
    xTaskCreatePinnedToCore(dask2down_task, "dask2down_task", 8192, NULL, 5, NULL, 1);
    xTaskCreatePinnedToCore(dht_task, "dht_task", 8192, NULL, 5, NULL, 1);
    xTaskCreatePinnedToCore(light_control_task, "light_control_task", 4096, NULL, 5, NULL, 1);
    xEventGroupWaitBits(wifi_event_group, WIFI_CONNECTED_BIT,
                        pdFALSE, pdTRUE, portMAX_DELAY);
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
