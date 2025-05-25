#ifndef GAUGE_H
#define GAUGE_H

#include "lvgl.h"
#include "ui/ui.h"
#include <stdio.h>
#include <stdint.h>

#define GAUGE_SPEED_MAX 50.0f
// #define GAUGE_NEEDLE_MAX 6100
#define GAUGE_NEEDLE_MAX 2510
#define GAUGE_ARC_MAX 1023

void gauge_set_speed(float speed);

#endif // GAUGE_H