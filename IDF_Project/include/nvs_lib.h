
#ifndef NVS_LIB_H
#define NVS_LIB_H

#include <stdbool.h>
#include <stddef.h>
#include "esp_err.h"

// Inicializace NVS
esp_err_t nvs_lib_init(void);

// Int
esp_err_t nvs_save_int(const char *key, int32_t value);
esp_err_t nvs_load_int(const char *key, int32_t *out_value);

// Bool
esp_err_t nvs_save_bool(const char *key, bool value);
esp_err_t nvs_load_bool(const char *key, bool *out_value);

// Float (uložen jako string)
esp_err_t nvs_save_float(const char *key, float value);
esp_err_t nvs_load_float(const char *key, float *out_value);

// String
esp_err_t nvs_save_string(const char *key, const char *value);
esp_err_t nvs_load_string(const char *key, char *out_value, size_t max_len);


int32_t nvs_load_int_default(const char *key, int32_t default_value);
bool nvs_load_bool_default(const char *key, bool default_value);
float nvs_load_float_default(const char *key, float default_value);
void nvs_load_string_default(const char *key, char *out_value, size_t max_len, const char *default_value);

#endif // NVS_LIB_H
