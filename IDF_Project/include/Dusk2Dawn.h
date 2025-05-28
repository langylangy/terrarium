#ifndef DUSK2DAWN_H
#define DUSK2DAWN_H

#include <stdbool.h>

typedef struct {
    float latitude;
    float longitude;
    float timezone;
} Dusk2Dawn;

void Dusk2Dawn_init(Dusk2Dawn *d2d, float latitude, float longitude, float timezone);
int Dusk2Dawn_sunrise(Dusk2Dawn *d2d, int year, int month, int day, bool isDST);
int Dusk2Dawn_sunset(Dusk2Dawn *d2d, int year, int month, int day, bool isDST);
bool Dusk2Dawn_min2str(char *str, int minutes);

#endif
