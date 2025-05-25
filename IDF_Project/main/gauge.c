#include "gauge.h"

uint8_t gauge_value = 0;

void gauge_set_speed(float speed)
{
    if (speed > GAUGE_SPEED_MAX)
    {
        speed = GAUGE_SPEED_MAX;
    }

    extern lv_obj_t *ui_MainSpeed;       // label
    extern lv_obj_t *ui_MainSpeedArc;    // arc
    extern lv_obj_t *ui_MainSpeedNeedle; // img

    /* Convert speed to gauge representations */
    uint16_t angle = (uint16_t)(speed * GAUGE_NEEDLE_MAX / GAUGE_SPEED_MAX);
    uint16_t arc_val = (uint16_t)(speed * GAUGE_ARC_MAX / GAUGE_SPEED_MAX);

    lv_img_set_angle(ui_MainSpeedNeedle, angle);
    lv_arc_set_value(ui_MainSpeedArc, arc_val);

    /* Update label text */
    static char buf[5]; // supports up to "255" plus null terminator
    snprintf(buf, sizeof(buf), "%.0f", speed);
    lv_label_set_text(ui_MainSpeed, buf);
}
