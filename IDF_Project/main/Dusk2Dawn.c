#include "dusk2dawn.h"
#include <math.h>
#include <stdio.h>

static int sunriseSet(Dusk2Dawn *d2d, bool isRise, int y, int m, int d, bool isDST);
static float sunriseSetUTC(bool isRise, float jday, float latitude, float longitude);
static float equationOfTime(float t);
static float meanObliquityOfEcliptic(float t);
static float eccentricityEarthOrbit(float t);
static float sunDeclination(float t);
static float sunApparentLong(float t);
static float sunTrueLong(float t);
static float sunEqOfCenter(float t);
static float hourAngleSunrise(float lat, float solarDec);
static float obliquityCorrection(float t);
static float geomMeanLongSun(float t);
static float geomMeanAnomalySun(float t);
static float jDay(int year, int month, int day);
static float fractionOfCentury(float jd);
static float radToDeg(float rad);
static float degToRad(float deg);
static bool zeroPadTime(char *str, int timeComponent);

void Dusk2Dawn_init(Dusk2Dawn *d2d, float latitude, float longitude, float timezone)
{
  d2d->latitude = latitude;
  d2d->longitude = longitude;
  d2d->timezone = timezone;
}

int Dusk2Dawn_sunrise(Dusk2Dawn *d2d, int y, int m, int d, bool isDST)
{
  return sunriseSet(d2d, true, y, m, d, isDST);
}

int Dusk2Dawn_sunset(Dusk2Dawn *d2d, int y, int m, int d, bool isDST)
{
  return sunriseSet(d2d, false, y, m, d, isDST);
}

bool Dusk2Dawn_min2str(char *str, int minutes)
{
  if (minutes < 0 || minutes >= 1440)
  {
    sprintf(str, "ERROR");
    return false;
  }

  int hour = minutes / 60;
  int min = minutes % 60;
  char hStr[3], mStr[3];

  if (!zeroPadTime(hStr, hour) || !zeroPadTime(mStr, min))
  {
    sprintf(str, "ERROR");
    return false;
  }

  sprintf(str, "%s:%s", hStr, mStr);
  return true;
}

static int sunriseSet(Dusk2Dawn *d2d, bool isRise, int y, int m, int d, bool isDST)
{
  float jd = jDay(y, m, d);
  float timeUTC = sunriseSetUTC(isRise, jd, d2d->latitude, d2d->longitude);
  float newJday = jd + timeUTC / (60 * 24);
  float newTimeUTC = sunriseSetUTC(isRise, newJday, d2d->latitude, d2d->longitude);

  if (!isnan(newTimeUTC))
  {
    int timeLocal = (int)roundf(newTimeUTC + (d2d->timezone * 60));
    if (isDST)
      timeLocal += 60;
    return timeLocal;
  }

  return -1;
}

static float sunriseSetUTC(bool isRise, float jday, float latitude, float longitude)
{
  float t = fractionOfCentury(jday);
  float eqTime = equationOfTime(t);
  float solarDec = sunDeclination(t);
  float hourAngle = hourAngleSunrise(latitude, solarDec);
  hourAngle = isRise ? hourAngle : -hourAngle;

  float delta = longitude + radToDeg(hourAngle);
  return 720 - (4 * delta) - eqTime;
}

static float equationOfTime(float t)
{
  float epsilon = obliquityCorrection(t);
  float l0 = geomMeanLongSun(t);
  float e = eccentricityEarthOrbit(t);
  float m = geomMeanAnomalySun(t);

  float y = tan(degToRad(epsilon) / 2);
  y *= y;

  return radToDeg(y * sin(2 * degToRad(l0)) - 2 * e * sin(degToRad(m)) + 4 * e * y * sin(degToRad(m)) * cos(2 * degToRad(l0)) - 0.5 * y * y * sin(4 * degToRad(l0)) - 1.25 * e * e * sin(2 * degToRad(m))) * 4;
}

static float obliquityCorrection(float t)
{
  float e0 = meanObliquityOfEcliptic(t);
  float omega = 125.04 - 1934.136 * t;
  return e0 + 0.00256 * cos(degToRad(omega));
}

static float meanObliquityOfEcliptic(float t)
{
  float seconds = 21.448 - t * (46.815 + t * (0.00059 - t * 0.001813));
  return 23 + (26 + (seconds / 60)) / 60;
}

static float eccentricityEarthOrbit(float t)
{
  return 0.016708634 - t * (0.000042037 + 0.0000001267 * t);
}

static float sunDeclination(float t)
{
  return radToDeg(asin(sin(degToRad(obliquityCorrection(t))) * sin(degToRad(sunApparentLong(t)))));
}

static float sunApparentLong(float t)
{
  float o = sunTrueLong(t);
  float omega = 125.04 - 1934.136 * t;
  return o - 0.00569 - 0.00478 * sin(degToRad(omega));
}

static float sunTrueLong(float t)
{
  return geomMeanLongSun(t) + sunEqOfCenter(t);
}

static float sunEqOfCenter(float t)
{
  float m = geomMeanAnomalySun(t);
  float mrad = degToRad(m);
  return sin(mrad) * (1.914602 - t * (0.004817 + 0.000014 * t)) +
         sin(2 * mrad) * (0.019993 - 0.000101 * t) +
         sin(3 * mrad) * 0.000289;
}

static float hourAngleSunrise(float lat, float solarDec)
{
  float latRad = degToRad(lat);
  float sdRad = degToRad(solarDec);
  float cosH = (cos(degToRad(90.833)) / (cos(latRad) * cos(sdRad))) - tan(latRad) * tan(sdRad);
  return acos(cosH);
}

static float geomMeanLongSun(float t)
{
  float L0 = 280.46646 + t * (36000.76983 + t * 0.0003032);
  while (L0 > 360)
    L0 -= 360;
  while (L0 < 0)
    L0 += 360;
  return L0;
}

static float geomMeanAnomalySun(float t)
{
  return 357.52911 + t * (35999.05029 - 0.0001537 * t);
}

static float jDay(int year, int month, int day)
{
  if (month <= 2)
  {
    year -= 1;
    month += 12;
  }
  int A = year / 100;
  int B = 2 - A + A / 4;
  return floor(365.25 * (year + 4716)) +
         floor(30.6001 * (month + 1)) +
         day + B - 1524.5;
}

static float fractionOfCentury(float jd)
{
  return (jd - 2451545) / 36525;
}

static float radToDeg(float rad)
{
  return rad * 180.0 / M_PI;
}

static float degToRad(float deg)
{
  return deg * M_PI / 180.0;
}

static bool zeroPadTime(char *str, int timeComponent)
{
  if (timeComponent >= 100)
    return false;
  str[0] = '0' + (timeComponent / 10);
  str[1] = '0' + (timeComponent % 10);
  str[2] = '\0';
  return true;
}
