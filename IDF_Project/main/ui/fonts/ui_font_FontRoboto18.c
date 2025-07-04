/*******************************************************************************
 * Size: 18 px
 * Bpp: 2
 * Opts: --bpp 2 --size 18 --font /Users/karelfunda/Projects/Wheel2Inch/_squareline/assets/RobotoCondensed-Regular.ttf -o /Users/karelfunda/Projects/Wheel2Inch/_squareline/assets/ui_font_FontRoboto18.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONTROBOTO18
#define UI_FONT_FONTROBOTO18 1
#endif

#if UI_FONT_FONTROBOTO18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0xb2, 0xcb, 0x2c, 0xb2, 0xcb, 0x2c, 0x70, 0x40,
    0x1c, 0x70,

    /* U+0022 "\"" */
    0xd7, 0xd7, 0xd6, 0xd6, 0x41,

    /* U+0023 "#" */
    0x2, 0x49, 0x0, 0xd3, 0x40, 0x30, 0xc1, 0xff,
    0xfd, 0x1b, 0x6d, 0x2, 0x8a, 0x0, 0x92, 0x40,
    0x34, 0xd0, 0xff, 0xff, 0x7, 0x1c, 0x1, 0xc7,
    0x0, 0xa2, 0x80, 0x28, 0xa0, 0x0,

    /* U+0024 "$" */
    0x0, 0x40, 0x0, 0xc0, 0x0, 0xd0, 0xb, 0xf8,
    0x1e, 0x1d, 0x2c, 0xe, 0x2c, 0xa, 0x1d, 0x0,
    0xf, 0x80, 0x2, 0xf4, 0x0, 0x7d, 0x0, 0xf,
    0x34, 0xb, 0x38, 0xf, 0x2d, 0x2d, 0xb, 0xf8,
    0x1, 0xc0, 0x0, 0xc0,

    /* U+0025 "%" */
    0x1f, 0x80, 0x0, 0xd3, 0x1, 0x3, 0x9, 0x24,
    0xd, 0x34, 0xc0, 0x1f, 0x89, 0x0, 0x0, 0x70,
    0x0, 0x3, 0x40, 0x0, 0x1c, 0xb8, 0x0, 0xda,
    0x34, 0x6, 0x34, 0xa0, 0x30, 0xd2, 0x80, 0x82,
    0x8d, 0x0, 0x3, 0xe0,

    /* U+0026 "&" */
    0x3, 0xf0, 0x0, 0xf7, 0xc0, 0xd, 0x1c, 0x0,
    0xd1, 0xc0, 0xf, 0x78, 0x0, 0x7e, 0x0, 0xb,
    0xc0, 0x1, 0xdf, 0x1c, 0x38, 0x3a, 0xc3, 0x42,
    0xf8, 0x38, 0xf, 0x1, 0xd2, 0xf8, 0x7, 0xf6,
    0xd0,

    /* U+0027 "'" */
    0x30, 0xc3, 0xc, 0x10,

    /* U+0028 "(" */
    0x2, 0x1, 0xc0, 0xc0, 0xb0, 0x34, 0x1c, 0xb,
    0x2, 0xc0, 0xe0, 0x38, 0xe, 0x2, 0xc0, 0xb0,
    0x1c, 0x3, 0x40, 0xe0, 0x1c, 0x2, 0x80, 0x30,
    0x0,

    /* U+0029 ")" */
    0x50, 0x1c, 0x2, 0x80, 0x30, 0xe, 0x2, 0xc0,
    0x70, 0xd, 0x3, 0x40, 0xd0, 0x34, 0xd, 0x3,
    0x41, 0xc0, 0xb0, 0x34, 0x1c, 0xd, 0x6, 0x0,
    0x0,

    /* U+002A "*" */
    0x3, 0x80, 0x2, 0x80, 0x62, 0x88, 0x7f, 0xfd,
    0x7, 0xc0, 0xe, 0xe0, 0x2c, 0x74, 0x0, 0x10,

    /* U+002B "+" */
    0x0, 0x80, 0x0, 0x70, 0x0, 0x1c, 0x0, 0x7,
    0x0, 0x2a, 0xea, 0x1f, 0xff, 0xc0, 0x1c, 0x0,
    0x7, 0x0, 0x1, 0xc0, 0x0, 0x70, 0x0,

    /* U+002C "," */
    0x38, 0xe3, 0x6c, 0x10,

    /* U+002D "-" */
    0x0, 0x2f, 0xc1, 0x50,

    /* U+002E "." */
    0x72, 0xc0,

    /* U+002F "/" */
    0x0, 0x70, 0x2, 0x80, 0xd, 0x0, 0x70, 0x2,
    0x80, 0xd, 0x0, 0x70, 0x2, 0xc0, 0xd, 0x0,
    0x30, 0x1, 0xc0, 0xe, 0x0, 0x30, 0x1, 0xc0,
    0x5, 0x0, 0x0,

    /* U+0030 "0" */
    0x1f, 0xd0, 0xf7, 0xcb, 0x3, 0x78, 0xe, 0xe0,
    0x2f, 0x80, 0xbe, 0x2, 0xf8, 0xb, 0xe0, 0x2f,
    0x80, 0xeb, 0x3, 0x4f, 0x7c, 0x1f, 0xd0,

    /* U+0031 "1" */
    0x2, 0x8b, 0xeb, 0x78, 0xe, 0x3, 0x80, 0xe0,
    0x38, 0xe, 0x3, 0x80, 0xe0, 0x38, 0xe, 0x3,
    0x80,

    /* U+0032 "2" */
    0x7, 0xf4, 0x7, 0x9f, 0x3, 0x80, 0xe0, 0xd0,
    0x38, 0x0, 0xe, 0x0, 0x7, 0x0, 0x3, 0x80,
    0x2, 0xc0, 0x1, 0xd0, 0x1, 0xe0, 0x0, 0xe0,
    0x0, 0xb5, 0x54, 0x3f, 0xff, 0x0,

    /* U+0033 "3" */
    0xb, 0xf4, 0x2e, 0x7c, 0x38, 0xd, 0x0, 0xd,
    0x0, 0x2c, 0x3, 0xf4, 0x1, 0x7c, 0x0, 0xe,
    0x0, 0xe, 0x34, 0xe, 0x38, 0xd, 0x1e, 0x7c,
    0x7, 0xe0,

    /* U+0034 "4" */
    0x0, 0x3c, 0x0, 0x1f, 0x0, 0xf, 0xc0, 0xb,
    0xb0, 0x3, 0x6c, 0x2, 0xcb, 0x0, 0xd2, 0xc0,
    0xb0, 0xb0, 0x38, 0x2c, 0x1f, 0xff, 0xd1, 0x56,
    0xd0, 0x0, 0xb0, 0x0, 0x2c, 0x0,

    /* U+0035 "5" */
    0x3f, 0xfc, 0x3e, 0xa4, 0x34, 0x0, 0x34, 0x0,
    0x3b, 0xe0, 0x7e, 0xf4, 0x10, 0x3c, 0x0, 0x2c,
    0x0, 0x1c, 0x60, 0x2c, 0x70, 0x3c, 0x3d, 0xb4,
    0xb, 0xd0,

    /* U+0036 "6" */
    0x2, 0xd0, 0x7e, 0x3, 0x80, 0x1c, 0x0, 0xbb,
    0xe3, 0xf6, 0xdf, 0x3, 0xb8, 0xb, 0xf0, 0x2e,
    0xc0, 0xb7, 0x43, 0x8f, 0x7c, 0xf, 0xd0,

    /* U+0037 "7" */
    0x7f, 0xff, 0x5, 0x57, 0xc0, 0x0, 0xe0, 0x0,
    0x70, 0x0, 0x2c, 0x0, 0xd, 0x0, 0x7, 0x0,
    0x3, 0x80, 0x0, 0xd0, 0x0, 0xb0, 0x0, 0x38,
    0x0, 0x1c, 0x0, 0xf, 0x0, 0x0,

    /* U+0038 "8" */
    0x1f, 0xd1, 0xe7, 0xcb, 0x3, 0xac, 0xe, 0x74,
    0xb0, 0xbf, 0x43, 0x9b, 0x2c, 0xe, 0xe0, 0x3f,
    0x80, 0xfb, 0x3, 0x9e, 0x7c, 0x1f, 0xd0,

    /* U+0039 "9" */
    0x7, 0xe0, 0x1e, 0x7c, 0x3c, 0x1d, 0x38, 0xe,
    0x34, 0xe, 0x38, 0xe, 0x2d, 0x2e, 0xf, 0xee,
    0x0, 0xd, 0x0, 0x1d, 0x0, 0x3c, 0x2, 0xf4,
    0xb, 0x80,

    /* U+003A ":" */
    0xb2, 0xc0, 0x0, 0x0, 0x0, 0x0, 0xb2, 0xc0,

    /* U+003B ";" */
    0x2c, 0x3c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3c, 0x3c, 0x38, 0x70, 0x10,

    /* U+003C "<" */
    0x0, 0x18, 0x2, 0xe0, 0xbd, 0xf, 0x40, 0x78,
    0x0, 0x7e, 0x0, 0x1f, 0x80, 0xa, 0x0, 0x0,

    /* U+003D "=" */
    0x0, 0x2, 0xff, 0xd1, 0x55, 0x0, 0x0, 0x0,
    0x2, 0xff, 0xd1, 0x55, 0x0,

    /* U+003E ">" */
    0x90, 0x2, 0xe0, 0x1, 0xf8, 0x0, 0x7d, 0x0,
    0xb4, 0x2f, 0x4b, 0xd0, 0x38, 0x0, 0x0, 0x0,

    /* U+003F "?" */
    0xb, 0xd0, 0xfa, 0xd3, 0x43, 0x80, 0xf, 0x0,
    0x38, 0x2, 0xc0, 0x1d, 0x0, 0xe0, 0x3, 0x40,
    0x4, 0x0, 0x0, 0x0, 0xd0, 0x3, 0x40,

    /* U+0040 "@" */
    0x0, 0x2f, 0xe0, 0x0, 0x1e, 0x47, 0xc0, 0x3,
    0x40, 0xa, 0x0, 0xa0, 0x0, 0x30, 0xc, 0xb,
    0x82, 0x81, 0x82, 0x8e, 0x1c, 0x24, 0x30, 0xd0,
    0xc3, 0x4b, 0xd, 0xc, 0x30, 0xa0, 0xd0, 0xc3,
    0xe, 0xc, 0xc, 0x34, 0xa0, 0xc1, 0x83, 0x4b,
    0x2d, 0x30, 0x28, 0x3d, 0x7d, 0x0, 0xc0, 0x0,
    0x0, 0xa, 0x0, 0x0, 0x0, 0x3d, 0x9, 0x0,
    0x0, 0x7f, 0x80, 0x0,

    /* U+0041 "A" */
    0x0, 0xb0, 0x0, 0x3, 0xd0, 0x0, 0x1f, 0x80,
    0x0, 0xb7, 0x0, 0x3, 0x4d, 0x0, 0xc, 0x38,
    0x0, 0xb0, 0x70, 0x3, 0x81, 0xd0, 0xf, 0xff,
    0x80, 0xb5, 0x5b, 0x3, 0x80, 0x1c, 0xd, 0x0,
    0x38, 0x70, 0x0, 0xf0,

    /* U+0042 "B" */
    0xbf, 0xe0, 0xb5, 0xbc, 0xb0, 0x1d, 0xb0, 0xe,
    0xb0, 0xd, 0xb0, 0x3c, 0xbf, 0xf4, 0xb5, 0x6c,
    0xb0, 0xe, 0xb0, 0xf, 0xb0, 0xe, 0xb5, 0x7c,
    0xbf, 0xf4,

    /* U+0043 "C" */
    0xb, 0xf4, 0xb, 0x9b, 0x87, 0x40, 0xb2, 0xc0,
    0x1d, 0xf0, 0x1, 0x38, 0x0, 0xe, 0x0, 0x3,
    0x80, 0x0, 0xf0, 0x0, 0x2c, 0x1, 0xd7, 0x40,
    0xb0, 0xf9, 0xb8, 0xb, 0xf4, 0x0,

    /* U+0044 "D" */
    0xbf, 0xe0, 0x2d, 0x6f, 0xb, 0x0, 0xe2, 0xc0,
    0x2c, 0xb0, 0x7, 0x2c, 0x1, 0xcb, 0x0, 0x72,
    0xc0, 0x1c, 0xb0, 0xb, 0x2c, 0x2, 0xcb, 0x1,
    0xe2, 0xd6, 0xf0, 0xbf, 0xe0, 0x0,

    /* U+0045 "E" */
    0xbf, 0xfc, 0xb5, 0x54, 0xb0, 0x0, 0xb0, 0x0,
    0xb0, 0x0, 0xb0, 0x0, 0xbf, 0xf8, 0xb5, 0x50,
    0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0, 0xb5, 0x54,
    0xbf, 0xfd,

    /* U+0046 "F" */
    0xbf, 0xfc, 0xb5, 0x54, 0xb0, 0x0, 0xb0, 0x0,
    0xb0, 0x0, 0xb0, 0x0, 0xbf, 0xf4, 0xb5, 0x50,
    0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0,
    0xb0, 0x0,

    /* U+0047 "G" */
    0xb, 0xf4, 0xf, 0x9b, 0x87, 0x40, 0xb2, 0xc0,
    0x8, 0xe0, 0x0, 0x38, 0x0, 0xe, 0xb, 0xf7,
    0x80, 0x5d, 0xf0, 0x3, 0x6c, 0x0, 0xd7, 0x40,
    0x74, 0xf9, 0xbc, 0xb, 0xf8, 0x0,

    /* U+0048 "H" */
    0xb0, 0x3, 0xec, 0x0, 0xfb, 0x0, 0x3e, 0xc0,
    0xf, 0xb0, 0x3, 0xec, 0x0, 0xfb, 0xff, 0xfe,
    0xd5, 0x5f, 0xb0, 0x3, 0xec, 0x0, 0xfb, 0x0,
    0x3e, 0xc0, 0xf, 0xb0, 0x3, 0xc0,

    /* U+0049 "I" */
    0xb2, 0xcb, 0x2c, 0xb2, 0xcb, 0x2c, 0xb2, 0xcb,
    0x2c, 0xb0,

    /* U+004A "J" */
    0x0, 0xd, 0x0, 0xd, 0x0, 0xd, 0x0, 0xd,
    0x0, 0xd, 0x0, 0xd, 0x0, 0xd, 0x0, 0xd,
    0x0, 0xd, 0x70, 0x1d, 0x74, 0x2c, 0x3e, 0xb8,
    0xb, 0xe0,

    /* U+004B "K" */
    0xb0, 0xf, 0x2c, 0xb, 0x4b, 0x7, 0x82, 0xc3,
    0xc0, 0xb2, 0xc0, 0x2d, 0xd0, 0xb, 0xf8, 0x2,
    0xf7, 0x40, 0xb0, 0xf0, 0x2c, 0x1e, 0xb, 0x2,
    0xc2, 0xc0, 0x3c, 0xb0, 0x7, 0x40,

    /* U+004C "L" */
    0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0,
    0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0,
    0xb0, 0x0, 0xb0, 0x0, 0xb0, 0x0, 0xb5, 0x54,
    0xbf, 0xfc,

    /* U+004D "M" */
    0xb8, 0x0, 0x3c, 0xbc, 0x0, 0x7c, 0xbc, 0x0,
    0xbc, 0xbe, 0x0, 0xfc, 0xbb, 0x1, 0xec, 0xb7,
    0x2, 0xdc, 0xb3, 0x83, 0x9c, 0xb2, 0xc3, 0x1c,
    0xb1, 0xcb, 0x1c, 0xb0, 0xde, 0x1c, 0xb0, 0xbc,
    0x1c, 0xb0, 0x7c, 0x1c, 0xb0, 0x38, 0x1c,

    /* U+004E "N" */
    0xb4, 0x3, 0xaf, 0x0, 0xeb, 0xd0, 0x3a, 0xec,
    0xe, 0xb3, 0x43, 0xac, 0xb0, 0xeb, 0xd, 0x3a,
    0xc2, 0xce, 0xb0, 0x37, 0xac, 0xb, 0xeb, 0x0,
    0xfa, 0xc0, 0x2e, 0xb0, 0x3, 0x80,

    /* U+004F "O" */
    0xb, 0xf4, 0xf, 0xaf, 0x87, 0x40, 0xb2, 0xc0,
    0xd, 0xf0, 0x3, 0xb8, 0x0, 0xee, 0x0, 0x3b,
    0x80, 0xe, 0xf0, 0x3, 0xac, 0x0, 0xd7, 0x40,
    0xb0, 0xfa, 0xf8, 0xb, 0xf4, 0x0,

    /* U+0050 "P" */
    0xbf, 0xf4, 0x2d, 0x5b, 0x8b, 0x0, 0xf2, 0xc0,
    0x1c, 0xb0, 0x7, 0x2c, 0x2, 0xcb, 0x1, 0xe2,
    0xff, 0xf0, 0xb5, 0x40, 0x2c, 0x0, 0xb, 0x0,
    0x2, 0xc0, 0x0, 0xb0, 0x0, 0x0,

    /* U+0051 "Q" */
    0xb, 0xf4, 0xf, 0xaf, 0x87, 0x40, 0xb3, 0xc0,
    0xd, 0xe0, 0x3, 0xb8, 0x0, 0xee, 0x0, 0x3b,
    0x80, 0xe, 0xe0, 0x3, 0xbc, 0x0, 0xd7, 0x40,
    0xb0, 0xfa, 0xf8, 0xb, 0xfd, 0x0, 0x3, 0xd0,
    0x0, 0x34, 0x0, 0x0,

    /* U+0052 "R" */
    0xbf, 0xe0, 0x2d, 0x6f, 0xb, 0x0, 0xe2, 0xc0,
    0x38, 0xb0, 0xe, 0x2c, 0xb, 0x4b, 0xff, 0x42,
    0xd6, 0xc0, 0xb0, 0x74, 0x2c, 0xf, 0xb, 0x1,
    0xc2, 0xc0, 0x38, 0xb0, 0xb, 0x0,

    /* U+0053 "S" */
    0x7, 0xf8, 0x7, 0xdb, 0xc3, 0xc0, 0x74, 0xe0,
    0xd, 0x2c, 0x0, 0x3, 0xd0, 0x0, 0x2f, 0x80,
    0x0, 0xbc, 0x0, 0x7, 0x4d, 0x0, 0xe3, 0x80,
    0x74, 0x7d, 0xbc, 0x7, 0xf8, 0x0,

    /* U+0054 "T" */
    0x7f, 0xff, 0xc5, 0x79, 0x50, 0xe, 0x0, 0x3,
    0x80, 0x0, 0xe0, 0x0, 0x38, 0x0, 0xe, 0x0,
    0x3, 0x80, 0x0, 0xe0, 0x0, 0x38, 0x0, 0xe,
    0x0, 0x3, 0x80, 0x0, 0xe0, 0x0,

    /* U+0055 "U" */
    0xf0, 0xb, 0x3c, 0x2, 0xcf, 0x0, 0xb3, 0xc0,
    0x2c, 0xf0, 0xb, 0x3c, 0x2, 0xcf, 0x0, 0xb3,
    0xc0, 0x2c, 0xf0, 0xb, 0x3c, 0x2, 0xcb, 0x0,
    0xf0, 0xf9, 0xf4, 0xb, 0xf4, 0x0,

    /* U+0056 "V" */
    0x74, 0x0, 0xe3, 0x80, 0x1d, 0x3c, 0x2, 0xc2,
    0xc0, 0x38, 0x1d, 0x7, 0x40, 0xe0, 0xb0, 0xb,
    0xe, 0x0, 0x70, 0xd0, 0x3, 0x5c, 0x0, 0x2a,
    0xc0, 0x1, 0xf8, 0x0, 0xf, 0x0, 0x0, 0xf0,
    0x0,

    /* U+0057 "W" */
    0x74, 0xe, 0x1, 0xc3, 0x80, 0xf0, 0x2c, 0x38,
    0x1f, 0x3, 0x82, 0xc1, 0xf4, 0x38, 0x1c, 0x2a,
    0x83, 0x41, 0xc3, 0x5c, 0x70, 0xd, 0x30, 0xcb,
    0x0, 0xe7, 0xd, 0xb0, 0xb, 0xa0, 0xde, 0x0,
    0xbd, 0xa, 0xd0, 0x7, 0xc0, 0x7c, 0x0, 0x3c,
    0x3, 0xc0, 0x3, 0x80, 0x3c, 0x0,

    /* U+0058 "X" */
    0x3c, 0x3, 0xc2, 0xd0, 0x74, 0xe, 0xf, 0x0,
    0xb1, 0xd0, 0x3, 0xbc, 0x0, 0x1f, 0x40, 0x0,
    0xf0, 0x0, 0x2f, 0x40, 0x3, 0xbc, 0x0, 0xb1,
    0xe0, 0xe, 0xf, 0x2, 0xc0, 0x78, 0x38, 0x3,
    0xc0,

    /* U+0059 "Y" */
    0xb4, 0x3, 0xc3, 0x80, 0x74, 0x2c, 0xb, 0x0,
    0xd0, 0xe0, 0xb, 0x1c, 0x0, 0x77, 0x80, 0x3,
    0xf4, 0x0, 0x1f, 0x0, 0x0, 0xe0, 0x0, 0xe,
    0x0, 0x0, 0xe0, 0x0, 0xe, 0x0, 0x0, 0xe0,
    0x0,

    /* U+005A "Z" */
    0x3f, 0xff, 0x45, 0x56, 0xd0, 0x0, 0xe0, 0x0,
    0xb0, 0x0, 0x38, 0x0, 0x2c, 0x0, 0x1d, 0x0,
    0xf, 0x0, 0x7, 0x40, 0x3, 0xc0, 0x2, 0xc0,
    0x0, 0xf5, 0x55, 0x3f, 0xff, 0x80,

    /* U+005B "[" */
    0x0, 0xfc, 0xf4, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
    0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
    0xf0, 0xf0, 0xfc, 0x14,

    /* U+005C "\\" */
    0x70, 0x0, 0xd0, 0x3, 0x80, 0x7, 0x0, 0xd,
    0x0, 0x38, 0x0, 0xb0, 0x0, 0xc0, 0x3, 0x80,
    0xb, 0x0, 0x1c, 0x0, 0x34, 0x0, 0xb0, 0x1,
    0xc0, 0x2, 0x0,

    /* U+005D "]" */
    0x0, 0xbc, 0x2c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
    0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
    0x1c, 0x1c, 0xbc, 0x14,

    /* U+005E "^" */
    0x1, 0x0, 0x2c, 0x0, 0xf8, 0x3, 0x70, 0x2c,
    0xc0, 0xd3, 0x83, 0xb, 0x0,

    /* U+005F "_" */
    0x0, 0x0, 0xff, 0xfc, 0x15, 0x54,

    /* U+0060 "`" */
    0x24, 0xb, 0x0, 0xb0,

    /* U+0061 "a" */
    0x1f, 0xd1, 0xe7, 0xca, 0x3, 0x40, 0xd, 0x1f,
    0xf5, 0xe1, 0xde, 0x3, 0x78, 0x1d, 0xba, 0xf4,
    0xbd, 0xd0,

    /* U+0062 "b" */
    0xe0, 0x0, 0xe0, 0x0, 0xe0, 0x0, 0xe0, 0x0,
    0xeb, 0xe0, 0xfd, 0xb4, 0xf0, 0x3c, 0xe0, 0x2c,
    0xe0, 0x2c, 0xe0, 0x2c, 0xe0, 0x2c, 0xf0, 0x3c,
    0xfd, 0xb4, 0xeb, 0xe0,

    /* U+0063 "c" */
    0x7, 0xf4, 0x1e, 0x7c, 0x38, 0xe, 0x34, 0x5,
    0x34, 0x0, 0x34, 0x0, 0x34, 0x0, 0x38, 0xe,
    0x1e, 0x6c, 0x7, 0xf0,

    /* U+0064 "d" */
    0x0, 0xe, 0x0, 0xe, 0x0, 0xe, 0x0, 0xe,
    0xb, 0xde, 0x2e, 0x7e, 0x3c, 0xe, 0x34, 0xe,
    0x34, 0xe, 0x34, 0xe, 0x34, 0xe, 0x38, 0xe,
    0x1e, 0x6e, 0xb, 0xee,

    /* U+0065 "e" */
    0x7, 0xf4, 0x1e, 0x7c, 0x38, 0xe, 0x38, 0xe,
    0x3f, 0xfe, 0x39, 0x54, 0x38, 0x0, 0x3c, 0x0,
    0x1e, 0x6d, 0x7, 0xf8,

    /* U+0066 "f" */
    0x0, 0x0, 0x3d, 0xf, 0x40, 0xd0, 0xd, 0x7,
    0xfc, 0x1e, 0x40, 0xd0, 0xd, 0x0, 0xd0, 0xd,
    0x0, 0xd0, 0xd, 0x0, 0xd0, 0xd, 0x0,

    /* U+0067 "g" */
    0xb, 0xda, 0x2e, 0x7e, 0x3c, 0xe, 0x38, 0xe,
    0x34, 0xe, 0x34, 0xe, 0x34, 0xe, 0x3c, 0xe,
    0x1e, 0x7e, 0xb, 0xde, 0x0, 0xe, 0x0, 0xe,
    0x1d, 0x7c, 0xb, 0xf0,

    /* U+0068 "h" */
    0xe0, 0x3, 0x80, 0xe, 0x0, 0x38, 0x0, 0xeb,
    0xd3, 0xf7, 0xcf, 0x3, 0x78, 0xe, 0xe0, 0x3b,
    0x80, 0xee, 0x3, 0xb8, 0xe, 0xe0, 0x3b, 0x80,
    0xe0,

    /* U+0069 "i" */
    0xba, 0xb, 0xbb, 0xbb, 0xbb, 0xbb, 0xb0,

    /* U+006A "j" */
    0xa, 0xa, 0x0, 0xf, 0xf, 0xf, 0xf, 0xf,
    0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xe, 0x2e,
    0x3c,

    /* U+006B "k" */
    0xe0, 0x3, 0x80, 0xe, 0x0, 0x38, 0x0, 0xe0,
    0xb3, 0x87, 0x4e, 0x38, 0x3a, 0xc0, 0xfe, 0x3,
    0xfd, 0xf, 0x3c, 0x38, 0x74, 0xe0, 0xb3, 0x80,
    0xe0,

    /* U+006C "l" */
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,

    /* U+006D "m" */
    0xeb, 0xd2, 0xf4, 0xf9, 0xfe, 0x7c, 0xf0, 0x3c,
    0x1c, 0xe0, 0x38, 0xd, 0xe0, 0x38, 0xd, 0xe0,
    0x38, 0xd, 0xe0, 0x38, 0xd, 0xe0, 0x38, 0xd,
    0xe0, 0x38, 0xd, 0xe0, 0x38, 0xd,

    /* U+006E "n" */
    0xeb, 0xd3, 0xf7, 0xcf, 0x3, 0x78, 0xe, 0xe0,
    0x3b, 0x80, 0xee, 0x3, 0xb8, 0xe, 0xe0, 0x3b,
    0x80, 0xe0,

    /* U+006F "o" */
    0x7, 0xf4, 0x7, 0x9b, 0x43, 0xc0, 0xf0, 0xe0,
    0x1c, 0x34, 0x7, 0xd, 0x1, 0xc3, 0x80, 0x70,
    0xf0, 0x3c, 0x1e, 0x6d, 0x1, 0xfd, 0x0,

    /* U+0070 "p" */
    0xeb, 0xe0, 0xf9, 0xb4, 0xf0, 0x3c, 0xe0, 0x2c,
    0xe0, 0x2c, 0xe0, 0x2c, 0xe0, 0x2c, 0xf0, 0x3c,
    0xf9, 0xb4, 0xeb, 0xe0, 0xe0, 0x0, 0xe0, 0x0,
    0xe0, 0x0, 0xe0, 0x0,

    /* U+0071 "q" */
    0xb, 0xee, 0x2e, 0x6e, 0x3c, 0xe, 0x34, 0xe,
    0x34, 0xe, 0x34, 0xe, 0x34, 0xe, 0x38, 0xe,
    0x2e, 0x6e, 0xb, 0xee, 0x0, 0xe, 0x0, 0xe,
    0x0, 0xe, 0x0, 0xe,

    /* U+0072 "r" */
    0x0, 0x3a, 0xcf, 0x93, 0xc0, 0xe0, 0x38, 0xe,
    0x3, 0x80, 0xe0, 0x38, 0xe, 0x0,

    /* U+0073 "s" */
    0xb, 0xe0, 0x1e, 0x7c, 0x3c, 0x1c, 0x2c, 0x0,
    0xf, 0x80, 0x1, 0xf8, 0x0, 0x2c, 0x38, 0x1d,
    0x2e, 0x7c, 0xb, 0xf0,

    /* U+0074 "t" */
    0x8, 0x7, 0x1, 0xc3, 0xfe, 0x2d, 0x7, 0x1,
    0xc0, 0x70, 0x1c, 0x7, 0x1, 0xc0, 0x39, 0xb,
    0x80,

    /* U+0075 "u" */
    0xe0, 0x3b, 0x80, 0xee, 0x3, 0xb8, 0xe, 0xe0,
    0x3b, 0x80, 0xee, 0x3, 0xac, 0xe, 0x7a, 0xf8,
    0xbd, 0xe0,

    /* U+0076 "v" */
    0x70, 0x1c, 0x34, 0x2c, 0x38, 0x38, 0x2c, 0x34,
    0x1c, 0x70, 0xd, 0xa0, 0xa, 0xd0, 0x7, 0xc0,
    0x3, 0xc0, 0x3, 0x80,

    /* U+0077 "w" */
    0x70, 0x38, 0x1c, 0x34, 0x3c, 0x2c, 0x38, 0x7c,
    0x38, 0x38, 0xad, 0x34, 0x2c, 0xde, 0x30, 0x1d,
    0xcb, 0x70, 0xf, 0xc3, 0xe0, 0xf, 0x83, 0xd0,
    0xb, 0x42, 0xd0, 0x7, 0x1, 0xc0,

    /* U+0078 "x" */
    0x38, 0x2c, 0x2c, 0x38, 0xd, 0xb0, 0xb, 0xe0,
    0x3, 0xc0, 0x3, 0xc0, 0xb, 0xe0, 0xd, 0xb0,
    0x3c, 0x38, 0x74, 0x2c,

    /* U+0079 "y" */
    0xb0, 0x2c, 0x74, 0x38, 0x38, 0x34, 0x2c, 0x70,
    0x1c, 0xb0, 0xd, 0xe0, 0xe, 0xd0, 0xb, 0xc0,
    0x7, 0xc0, 0x3, 0x80, 0x3, 0x40, 0x7, 0x0,
    0x2e, 0x0, 0x38, 0x0,

    /* U+007A "z" */
    0x3f, 0xfc, 0x15, 0x7c, 0x0, 0x70, 0x0, 0xe0,
    0x2, 0xc0, 0x3, 0x40, 0xf, 0x0, 0x1d, 0x0,
    0x3d, 0x54, 0x3f, 0xfc,

    /* U+007B "{" */
    0x0, 0x0, 0x2c, 0x7, 0x40, 0xb0, 0xe, 0x0,
    0xe0, 0xe, 0x0, 0xe0, 0x1d, 0x7, 0x80, 0x2c,
    0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0, 0xb0,
    0x7, 0x0, 0x2c, 0x0, 0x40,

    /* U+007C "|" */
    0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x71,

    /* U+007D "}" */
    0x0, 0x2c, 0x3, 0xc0, 0x70, 0xd, 0x3, 0x40,
    0xd0, 0x34, 0xf, 0x0, 0xf0, 0xb4, 0x34, 0xd,
    0x3, 0x40, 0xd0, 0x70, 0x2c, 0x1c, 0x0, 0x0,

    /* U+007E "~" */
    0x0, 0x0, 0xf, 0xc0, 0xdb, 0x7d, 0x73, 0x82,
    0xf8, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 66, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 71, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 92, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 15, .adv_w = 158, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 142, .box_w = 8, .box_h = 18, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 81, .adv_w = 182, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 157, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 50, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 154, .adv_w = 90, .box_w = 5, .box_h = 20, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 179, .adv_w = 92, .box_w = 5, .box_h = 20, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 204, .adv_w = 124, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 220, .adv_w = 143, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 243, .adv_w = 57, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 247, .adv_w = 71, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 251, .adv_w = 76, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 107, .box_w = 7, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 280, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 142, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 320, .adv_w = 142, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 142, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 142, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 142, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 455, .adv_w = 142, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 508, .adv_w = 142, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 534, .adv_w = 67, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 58, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 555, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 571, .adv_w = 138, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 584, .adv_w = 132, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 600, .adv_w = 122, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 623, .adv_w = 221, .box_w = 14, .box_h = 17, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 683, .adv_w = 166, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 719, .adv_w = 157, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 745, .adv_w = 163, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 775, .adv_w = 164, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 805, .adv_w = 143, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 831, .adv_w = 138, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 857, .adv_w = 170, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 887, .adv_w = 179, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 917, .adv_w = 72, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 927, .adv_w = 139, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 953, .adv_w = 157, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 983, .adv_w = 137, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1009, .adv_w = 218, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1048, .adv_w = 178, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1078, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1108, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1138, .adv_w = 173, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1174, .adv_w = 153, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1204, .adv_w = 149, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1234, .adv_w = 150, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1264, .adv_w = 162, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1294, .adv_w = 161, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1327, .adv_w = 219, .box_w = 14, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1373, .adv_w = 159, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1406, .adv_w = 151, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1439, .adv_w = 150, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1469, .adv_w = 72, .box_w = 4, .box_h = 20, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1489, .adv_w = 106, .box_w = 7, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1516, .adv_w = 72, .box_w = 4, .box_h = 20, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1536, .adv_w = 107, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 1549, .adv_w = 117, .box_w = 8, .box_h = 3, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1555, .adv_w = 89, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 11},
    {.bitmap_index = 1559, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1577, .adv_w = 142, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1605, .adv_w = 133, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1625, .adv_w = 143, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1653, .adv_w = 135, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1673, .adv_w = 91, .box_w = 6, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1696, .adv_w = 142, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1724, .adv_w = 139, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1749, .adv_w = 66, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1756, .adv_w = 64, .box_w = 4, .box_h = 17, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 1773, .adv_w = 130, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1798, .adv_w = 66, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1805, .adv_w = 217, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1835, .adv_w = 139, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1853, .adv_w = 145, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1876, .adv_w = 142, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1904, .adv_w = 144, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1932, .adv_w = 88, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1946, .adv_w = 131, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1966, .adv_w = 85, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1983, .adv_w = 139, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2001, .adv_w = 123, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2021, .adv_w = 187, .box_w = 12, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2051, .adv_w = 126, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2071, .adv_w = 120, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 2099, .adv_w = 126, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2119, .adv_w = 88, .box_w = 6, .box_h = 19, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 2148, .adv_w = 70, .box_w = 2, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 2156, .adv_w = 88, .box_w = 5, .box_h = 19, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 2180, .adv_w = 170, .box_w = 9, .box_h = 5, .ofs_x = 1, .ofs_y = 3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    1, 53,
    3, 3,
    3, 8,
    3, 34,
    3, 66,
    3, 68,
    3, 69,
    3, 70,
    3, 72,
    3, 78,
    3, 79,
    3, 80,
    3, 81,
    3, 82,
    3, 84,
    3, 88,
    8, 3,
    8, 8,
    8, 34,
    8, 66,
    8, 68,
    8, 69,
    8, 70,
    8, 72,
    8, 78,
    8, 79,
    8, 80,
    8, 81,
    8, 82,
    8, 84,
    8, 88,
    9, 55,
    9, 56,
    9, 58,
    13, 3,
    13, 8,
    15, 3,
    15, 8,
    16, 16,
    34, 3,
    34, 8,
    34, 32,
    34, 36,
    34, 40,
    34, 48,
    34, 50,
    34, 53,
    34, 54,
    34, 55,
    34, 56,
    34, 58,
    34, 80,
    34, 85,
    34, 86,
    34, 87,
    34, 88,
    34, 90,
    34, 91,
    35, 53,
    35, 55,
    35, 58,
    36, 10,
    36, 53,
    36, 62,
    36, 94,
    37, 13,
    37, 15,
    37, 34,
    37, 53,
    37, 55,
    37, 57,
    37, 58,
    37, 59,
    38, 53,
    38, 68,
    38, 69,
    38, 70,
    38, 71,
    38, 72,
    38, 80,
    38, 82,
    38, 86,
    38, 87,
    38, 88,
    38, 90,
    39, 13,
    39, 15,
    39, 34,
    39, 43,
    39, 53,
    39, 66,
    39, 68,
    39, 69,
    39, 70,
    39, 72,
    39, 80,
    39, 82,
    39, 83,
    39, 86,
    39, 87,
    39, 90,
    41, 34,
    41, 53,
    41, 57,
    41, 58,
    42, 34,
    42, 53,
    42, 57,
    42, 58,
    43, 34,
    44, 14,
    44, 36,
    44, 40,
    44, 48,
    44, 50,
    44, 68,
    44, 69,
    44, 70,
    44, 72,
    44, 78,
    44, 79,
    44, 80,
    44, 81,
    44, 82,
    44, 86,
    44, 87,
    44, 88,
    44, 90,
    45, 3,
    45, 8,
    45, 34,
    45, 36,
    45, 40,
    45, 48,
    45, 50,
    45, 53,
    45, 54,
    45, 55,
    45, 56,
    45, 58,
    45, 86,
    45, 87,
    45, 88,
    45, 90,
    46, 34,
    46, 53,
    46, 57,
    46, 58,
    47, 34,
    47, 53,
    47, 57,
    47, 58,
    48, 13,
    48, 15,
    48, 34,
    48, 53,
    48, 55,
    48, 57,
    48, 58,
    48, 59,
    49, 13,
    49, 15,
    49, 34,
    49, 43,
    49, 57,
    49, 59,
    49, 66,
    49, 68,
    49, 69,
    49, 70,
    49, 72,
    49, 80,
    49, 82,
    49, 85,
    49, 87,
    49, 90,
    50, 53,
    50, 55,
    50, 56,
    50, 58,
    51, 53,
    51, 55,
    51, 58,
    53, 1,
    53, 13,
    53, 14,
    53, 15,
    53, 34,
    53, 36,
    53, 40,
    53, 43,
    53, 48,
    53, 50,
    53, 52,
    53, 53,
    53, 55,
    53, 56,
    53, 58,
    53, 66,
    53, 68,
    53, 69,
    53, 70,
    53, 72,
    53, 78,
    53, 79,
    53, 80,
    53, 81,
    53, 82,
    53, 83,
    53, 84,
    53, 86,
    53, 87,
    53, 88,
    53, 89,
    53, 90,
    53, 91,
    54, 34,
    55, 10,
    55, 13,
    55, 14,
    55, 15,
    55, 34,
    55, 36,
    55, 40,
    55, 48,
    55, 50,
    55, 62,
    55, 66,
    55, 68,
    55, 69,
    55, 70,
    55, 72,
    55, 80,
    55, 82,
    55, 83,
    55, 86,
    55, 87,
    55, 90,
    55, 94,
    56, 10,
    56, 13,
    56, 14,
    56, 15,
    56, 34,
    56, 53,
    56, 62,
    56, 66,
    56, 68,
    56, 69,
    56, 70,
    56, 72,
    56, 80,
    56, 82,
    56, 83,
    56, 86,
    56, 94,
    57, 14,
    57, 36,
    57, 40,
    57, 48,
    57, 50,
    57, 55,
    57, 68,
    57, 69,
    57, 70,
    57, 72,
    57, 80,
    57, 82,
    57, 86,
    57, 87,
    57, 90,
    58, 7,
    58, 10,
    58, 11,
    58, 13,
    58, 14,
    58, 15,
    58, 34,
    58, 36,
    58, 40,
    58, 43,
    58, 48,
    58, 50,
    58, 52,
    58, 53,
    58, 54,
    58, 55,
    58, 56,
    58, 57,
    58, 58,
    58, 62,
    58, 66,
    58, 68,
    58, 69,
    58, 70,
    58, 71,
    58, 72,
    58, 78,
    58, 79,
    58, 80,
    58, 81,
    58, 82,
    58, 83,
    58, 84,
    58, 85,
    58, 86,
    58, 87,
    58, 89,
    58, 90,
    58, 91,
    58, 94,
    59, 34,
    59, 36,
    59, 40,
    59, 48,
    59, 50,
    59, 68,
    59, 69,
    59, 70,
    59, 72,
    59, 80,
    59, 82,
    59, 86,
    59, 87,
    59, 88,
    59, 90,
    60, 43,
    60, 54,
    66, 3,
    66, 8,
    66, 87,
    66, 90,
    67, 3,
    67, 8,
    67, 87,
    67, 89,
    67, 90,
    67, 91,
    68, 3,
    68, 8,
    70, 3,
    70, 8,
    70, 87,
    70, 90,
    71, 3,
    71, 8,
    71, 10,
    71, 62,
    71, 68,
    71, 69,
    71, 70,
    71, 72,
    71, 82,
    71, 94,
    73, 3,
    73, 8,
    76, 68,
    76, 69,
    76, 70,
    76, 72,
    76, 82,
    78, 3,
    78, 8,
    79, 3,
    79, 8,
    80, 3,
    80, 8,
    80, 87,
    80, 89,
    80, 90,
    80, 91,
    81, 3,
    81, 8,
    81, 87,
    81, 89,
    81, 90,
    81, 91,
    83, 3,
    83, 8,
    83, 13,
    83, 15,
    83, 66,
    83, 68,
    83, 69,
    83, 70,
    83, 71,
    83, 72,
    83, 80,
    83, 82,
    83, 85,
    83, 87,
    83, 88,
    83, 90,
    85, 80,
    87, 3,
    87, 8,
    87, 13,
    87, 15,
    87, 66,
    87, 68,
    87, 69,
    87, 70,
    87, 71,
    87, 72,
    87, 80,
    87, 82,
    88, 13,
    88, 15,
    89, 68,
    89, 69,
    89, 70,
    89, 72,
    89, 80,
    89, 82,
    90, 3,
    90, 8,
    90, 13,
    90, 15,
    90, 66,
    90, 68,
    90, 69,
    90, 70,
    90, 71,
    90, 72,
    90, 80,
    90, 82,
    91, 68,
    91, 69,
    91, 70,
    91, 72,
    91, 80,
    91, 82,
    92, 43,
    92, 54
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -6, -15, -15, -17, -7, -8, -8, -8,
    -8, -3, -3, -9, -3, -8, -11, 2,
    -15, -15, -17, -7, -8, -8, -8, -8,
    -3, -3, -9, -3, -8, -11, 2, 3,
    3, 3, -24, -24, -24, -24, -31, -17,
    -17, -9, -2, -2, -2, -2, -18, -2,
    -12, -10, -13, -2, -2, -2, -7, -5,
    -7, 2, -4, -3, -8, -4, -4, -2,
    -2, -14, -14, -3, -4, -3, -3, -6,
    -3, 3, -3, -3, -3, -3, -3, -3,
    -3, -2, -4, -3, -4, -33, -33, -24,
    -37, 3, -5, -3, -3, -3, -3, -3,
    -3, -4, -3, -3, -3, 3, -4, 2,
    -4, 3, -4, 2, -4, -3, -9, -4,
    -4, -4, -4, -4, -4, -4, -4, -3,
    -3, -4, -3, -4, -3, -6, -9, -6,
    -47, -47, 3, -9, -9, -9, -9, -39,
    -8, -25, -20, -34, -6, -19, -13, -19,
    3, -4, 2, -4, 3, -4, 2, -4,
    -14, -14, -3, -4, -3, -3, -6, -3,
    -46, -46, -19, -28, -4, -4, -2, -2,
    -2, -2, -2, -2, -2, 2, 2, 2,
    -6, -4, -3, -5, -11, -3, -7, -6,
    -31, -33, -31, -11, -4, -4, -34, -4,
    -4, -2, 2, 2, 2, 2, -16, -14,
    -14, -14, -14, -15, -15, -14, -15, -14,
    -11, -16, -13, -10, -8, -11, -10, -8,
    -3, 3, -32, -5, -32, -11, -2, -2,
    -2, -2, 2, -6, -6, -6, -6, -6,
    -6, -6, -4, -4, -2, -2, 3, 2,
    -17, -8, -17, -6, 2, 2, -5, -4,
    -4, -4, -4, -4, -4, -3, -3, 2,
    -6, -4, -4, -4, -4, 2, -4, -4,
    -4, -4, -3, -4, -3, -4, -4, -4,
    3, -7, -30, -7, -30, -13, -4, -4,
    -13, -4, -4, -2, 2, -13, 3, 2,
    2, 3, 3, -10, -9, -9, -9, -3,
    -9, -6, -6, -9, -6, -9, -6, -8,
    -3, -5, -3, -3, -3, -4, 3, 2,
    -4, -4, -4, -4, -3, -3, -3, -3,
    -3, -3, -3, -4, -4, -4, -3, -3,
    -9, -9, -2, -2, -4, -4, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2,
    2, 2, 3, 3, -3, -3, -3, -3,
    -3, 3, -15, -15, -3, -3, -3, -3,
    -3, -15, -15, -15, -15, -19, -19, -2,
    -3, -2, -2, -4, -4, -2, -2, -2,
    -2, 2, 2, -17, -17, -6, -3, -3,
    -3, 2, -3, -3, -3, 7, 3, 2,
    3, -3, 2, 2, -15, -15, -2, -2,
    -2, -2, 2, -2, -2, -2, -17, -17,
    -3, -3, -3, -3, -3, -3, 2, 2,
    -15, -15, -2, -2, -2, -2, 2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2,
    -3, -3
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 434,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_FontRoboto18 = {
#else
lv_font_t ui_font_FontRoboto18 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 21,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONTROBOTO18*/

