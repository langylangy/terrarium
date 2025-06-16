#include "nvs_flash.h"
#include "nvs.h"
#include "esp_log.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

static const char *TAG_NVS = "NVS_LIB";

// Inicializace NVS – musí být voláno jednou při startu aplikace
esp_err_t nvs_lib_init()
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    return err;
}

// Uloží int32_t
esp_err_t nvs_save_int(const char *key, int32_t value)
{
    nvs_handle_t handle;
    esp_err_t err = nvs_open("storage", NVS_READWRITE, &handle);
    if (err != ESP_OK)
        return err;
    err = nvs_set_i32(handle, key, value);
    if (err == ESP_OK)
        err = nvs_commit(handle);
    nvs_close(handle);
    return err;
}

// Načte int32_t
esp_err_t nvs_load_int(const char *key, int32_t *out_value)
{
    nvs_handle_t handle;
    esp_err_t err = nvs_open("storage", NVS_READONLY, &handle);
    if (err != ESP_OK)
        return err;
    err = nvs_get_i32(handle, key, out_value);
    nvs_close(handle);
    return err;
}

// Uloží bool (uloženo jako uint8_t)
esp_err_t nvs_save_bool(const char *key, bool value)
{
    return nvs_save_int(key, value ? 1 : 0);
}

// Načte bool (z uint8_t)
esp_err_t nvs_load_bool(const char *key, bool *out_value)
{
    int32_t temp = 0;
    esp_err_t err = nvs_load_int(key, &temp);
    if (err == ESP_OK)
    {
        *out_value = (temp != 0);
    }
    return err;
}

// Uloží string
esp_err_t nvs_save_string(const char *key, const char *value)
{
    nvs_handle_t handle;
    esp_err_t err = nvs_open("storage", NVS_READWRITE, &handle);
    if (err != ESP_OK)
        return err;
    err = nvs_set_str(handle, key, value);
    if (err == ESP_OK)
        err = nvs_commit(handle);
    nvs_close(handle);
    return err;
}

// Načte string
esp_err_t nvs_load_string(const char *key, char *out_value, size_t max_len)
{
    nvs_handle_t handle;
    esp_err_t err = nvs_open("storage", NVS_READONLY, &handle);
    if (err != ESP_OK)
        return err;

    size_t required_size = 0;
    err = nvs_get_str(handle, key, NULL, &required_size);
    if (err != ESP_OK || required_size > max_len)
    {
        nvs_close(handle);
        return err == ESP_OK ? ESP_ERR_NVS_INVALID_LENGTH : err;
    }

    err = nvs_get_str(handle, key, out_value, &required_size);
    nvs_close(handle);
    return err;
}

// Uloží float (uloženo jako string)
esp_err_t nvs_save_float(const char *key, float value)
{
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%f", value);
    return nvs_save_string(key, buffer);
}

// Načte float (ze stringu)
esp_err_t nvs_load_float(const char *key, float *out_value)
{
    char buffer[32];
    esp_err_t err = nvs_load_string(key, buffer, sizeof(buffer));
    if (err == ESP_OK)
    {
        *out_value = strtof(buffer, NULL);
    }
    return err;
}

// Načte int nebo vrátí výchozí hodnotu
int32_t nvs_load_int_default(const char *key, int32_t default_value)
{
    int32_t value = 0;
    if (nvs_load_int(key, &value) == ESP_OK)
        return value;
    return default_value;
}

// Načte bool nebo vrátí výchozí hodnotu
bool nvs_load_bool_default(const char *key, bool default_value)
{
    bool value = false;
    if (nvs_load_bool(key, &value) == ESP_OK)
        return value;
    return default_value;
}

// Načte float nebo vrátí výchozí hodnotu
float nvs_load_float_default(const char *key, float default_value)
{
    float value = 0.0f;
    if (nvs_load_float(key, &value) == ESP_OK)
        return value;
    return default_value;
}

// Načte string nebo vrátí výchozí hodnotu
void nvs_load_string_default(const char *key, char *out_value, size_t max_len, const char *default_value)
{
    if (nvs_load_string(key, out_value, max_len) != ESP_OK)
    {
        strncpy(out_value, default_value, max_len);
        out_value[max_len - 1] = '\\0'; // jistota ukončení
    }
}
