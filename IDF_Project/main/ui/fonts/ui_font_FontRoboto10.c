/*******************************************************************************
 * Size: 10 px
 * Bpp: 2
 * Opts: --bpp 2 --size 10 --font /Users/karelfunda/Projects/Wheel2Inch/_squareline/assets/RobotoCondensed-Regular.ttf -o /Users/karelfunda/Projects/Wheel2Inch/_squareline/assets/ui_font_FontRoboto10.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONTROBOTO10
#define UI_FONT_FONTROBOTO10 1
#endif

#if UI_FONT_FONTROBOTO10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x22, 0x22, 0x21, 0x2,

    /* U+0022 "\"" */
    0x59, 0x60, 0x40,

    /* U+0023 "#" */
    0x8, 0x80, 0x88, 0x3f, 0xc0, 0x90, 0x6, 0x7,
    0xf8, 0x22, 0x2, 0x20,

    /* U+0024 "$" */
    0x0, 0x2, 0x1, 0xe0, 0xcc, 0x21, 0xe, 0x0,
    0x70, 0x9, 0x62, 0x4b, 0x80, 0x80,

    /* U+0025 "%" */
    0x28, 0x4, 0x88, 0x49, 0x42, 0x60, 0x5, 0x90,
    0xa2, 0x16, 0x20, 0x9,

    /* U+0026 "&" */
    0x2d, 0x3, 0x30, 0x32, 0x2, 0xc0, 0x3c, 0x85,
    0x3c, 0x62, 0x82, 0xac,

    /* U+0027 "'" */
    0x44, 0x40,

    /* U+0028 "(" */
    0x4, 0x53, 0x8, 0x61, 0x86, 0x8, 0x30, 0x80,
    0x80,

    /* U+0029 ")" */
    0x40, 0x83, 0x8, 0x14, 0x51, 0x45, 0x20, 0x85,
    0x0,

    /* U+002A "*" */
    0x8, 0x16, 0x82, 0xd0, 0xe0, 0x0, 0x0,

    /* U+002B "+" */
    0x8, 0x3, 0x0, 0xc2, 0xfd, 0xc, 0x3, 0x0,

    /* U+002C "," */
    0x59, 0x40,

    /* U+002D "-" */
    0xb0,

    /* U+002E "." */
    0x2,

    /* U+002F "/" */
    0x8, 0x8, 0x8, 0x14, 0x20, 0x20, 0x50, 0x80,
    0x40,

    /* U+0030 "0" */
    0x2e, 0x8, 0xc5, 0x25, 0x49, 0x52, 0x54, 0x92,
    0x30, 0xb8,

    /* U+0031 "1" */
    0x18, 0x2c, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,

    /* U+0032 "2" */
    0x2e, 0x18, 0xc0, 0x20, 0xc, 0x9, 0x2, 0x3,
    0x1, 0xfd,

    /* U+0033 "3" */
    0x2e, 0x14, 0xc0, 0x30, 0x78, 0x3, 0x0, 0x96,
    0x30, 0xb4,

    /* U+0034 "4" */
    0x7, 0x2, 0xc1, 0xb0, 0x8c, 0x63, 0x2f, 0xe0,
    0x30, 0xc,

    /* U+0035 "5" */
    0x3f, 0x4c, 0x3, 0x0, 0xf8, 0x12, 0x40, 0x52,
    0x24, 0xb8,

    /* U+0036 "6" */
    0xe, 0xc, 0x2, 0x1, 0xf8, 0x72, 0x58, 0x53,
    0x24, 0x78,

    /* U+0037 "7" */
    0x7f, 0x40, 0x80, 0x30, 0x18, 0x8, 0x3, 0x1,
    0x80, 0x80,

    /* U+0038 "8" */
    0x2e, 0x8, 0xc2, 0x30, 0xb8, 0x23, 0x14, 0x96,
    0x20, 0xb8,

    /* U+0039 "9" */
    0x2d, 0x18, 0xc5, 0x21, 0x8d, 0x2f, 0x0, 0xc0,
    0x70, 0xb0,

    /* U+003A ":" */
    0x20, 0x0, 0x2,

    /* U+003B ";" */
    0x60, 0x0, 0x6, 0x90,

    /* U+003C "<" */
    0x2, 0x2c, 0xa0, 0x2c, 0x2,

    /* U+003D "=" */
    0x3f, 0x0, 0x3, 0xf0,

    /* U+003E ">" */
    0x60, 0x7, 0x40, 0x30, 0xb4, 0x50, 0x0,

    /* U+003F "?" */
    0x3d, 0x92, 0x2, 0x9, 0x8, 0x14, 0x0, 0x14,

    /* U+0040 "@" */
    0x6, 0xa0, 0x14, 0x14, 0x22, 0x88, 0x12, 0x54,
    0x54, 0x44, 0x58, 0x84, 0x58, 0x88, 0x26, 0x64,
    0x20, 0x0, 0xa, 0x80,

    /* U+0041 "A" */
    0x9, 0x0, 0xe0, 0xb, 0x2, 0x64, 0x31, 0x83,
    0xfc, 0x60, 0xc9, 0x5,

    /* U+0042 "B" */
    0x3f, 0x8, 0x62, 0x18, 0xfc, 0x21, 0x88, 0x32,
    0x18, 0xfc,

    /* U+0043 "C" */
    0x1f, 0x43, 0xc, 0x60, 0x46, 0x0, 0x60, 0x6,
    0x4, 0x30, 0xc1, 0xf4,

    /* U+0044 "D" */
    0x3e, 0x2, 0x18, 0x20, 0xc2, 0xc, 0x20, 0xc2,
    0xc, 0x21, 0x83, 0xe0,

    /* U+0045 "E" */
    0x3f, 0x48, 0x2, 0x0, 0xfc, 0x20, 0x8, 0x2,
    0x0, 0xfe,

    /* U+0046 "F" */
    0x3f, 0x48, 0x2, 0x0, 0x80, 0x3f, 0x8, 0x2,
    0x0, 0x80,

    /* U+0047 "G" */
    0x1f, 0x43, 0xc, 0x60, 0x46, 0x0, 0x63, 0xc6,
    0x8, 0x30, 0x81, 0xf8,

    /* U+0048 "H" */
    0x20, 0x52, 0x5, 0x20, 0x53, 0xfd, 0x20, 0x52,
    0x5, 0x20, 0x52, 0x5,

    /* U+0049 "I" */
    0x22, 0x22, 0x22, 0x22,

    /* U+004A "J" */
    0x3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xc9,
    0x30, 0xf4,

    /* U+004B "K" */
    0x20, 0xc2, 0x34, 0x26, 0x3, 0xc0, 0x39, 0x2,
    0x30, 0x21, 0x82, 0xc,

    /* U+004C "L" */
    0x20, 0x8, 0x2, 0x0, 0x80, 0x20, 0x8, 0x2,
    0x0, 0xfd,

    /* U+004D "M" */
    0x30, 0x2c, 0xd0, 0xf3, 0x83, 0xcb, 0x1b, 0x28,
    0x9c, 0x97, 0x32, 0x38, 0xc8, 0x93,

    /* U+004E "N" */
    0x30, 0x53, 0x45, 0x2c, 0x52, 0x95, 0x22, 0x52,
    0x29, 0x20, 0xd2, 0x9,

    /* U+004F "O" */
    0x1f, 0x43, 0xc, 0x60, 0x96, 0x9, 0x60, 0x96,
    0x9, 0x30, 0xc1, 0xf4,

    /* U+0050 "P" */
    0x3f, 0x42, 0xc, 0x20, 0xc2, 0xc, 0x3f, 0x42,
    0x0, 0x20, 0x2, 0x0,

    /* U+0051 "Q" */
    0x1f, 0x43, 0xc, 0x60, 0x95, 0x9, 0x50, 0x96,
    0x9, 0x30, 0xc1, 0xf8, 0x0, 0xc0, 0x0,

    /* U+0052 "R" */
    0x3f, 0x2, 0x18, 0x20, 0xc2, 0x18, 0x3f, 0x2,
    0x30, 0x21, 0x82, 0xc,

    /* U+0053 "S" */
    0x2f, 0x18, 0x66, 0x4, 0xe0, 0x7, 0x40, 0x26,
    0x18, 0xbc,

    /* U+0054 "T" */
    0xbf, 0xc3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30,

    /* U+0055 "U" */
    0x60, 0xd8, 0x36, 0xd, 0x83, 0x60, 0xd8, 0x32,
    0xc, 0xbd,

    /* U+0056 "V" */
    0x90, 0x96, 0xc, 0x30, 0x83, 0x14, 0x26, 0x1,
    0xb0, 0xe, 0x0, 0x90,

    /* U+0057 "W" */
    0x92, 0x49, 0x53, 0x8c, 0x22, 0x8c, 0x32, 0x88,
    0x35, 0x98, 0x28, 0x64, 0x2c, 0x30, 0x18, 0x30,

    /* U+0058 "X" */
    0x60, 0xc3, 0x24, 0x1b, 0x0, 0xe0, 0xe, 0x1,
    0xb0, 0x32, 0x46, 0xc,

    /* U+0059 "Y" */
    0x90, 0xc6, 0x14, 0x33, 0x1, 0xa0, 0xd, 0x0,
    0xc0, 0xc, 0x0, 0xc0,

    /* U+005A "Z" */
    0x7f, 0x80, 0x90, 0x30, 0x24, 0xc, 0x9, 0x3,
    0x2, 0xfe,

    /* U+005B "[" */
    0x71, 0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0x87,
    0x0,

    /* U+005C "\\" */
    0x80, 0x60, 0x30, 0x20, 0x14, 0x8, 0xc, 0x9,
    0x0,

    /* U+005D "]" */
    0xa3, 0x33, 0x33, 0x33, 0x33, 0xa0,

    /* U+005E "^" */
    0x24, 0x38, 0x28, 0x98,

    /* U+005F "_" */
    0xbf,

    /* U+0060 "`" */
    0x50, 0xc0,

    /* U+0061 "a" */
    0x2e, 0x4, 0xc2, 0xb1, 0x8c, 0x63, 0xf, 0x80,

    /* U+0062 "b" */
    0x60, 0x18, 0x7, 0xe1, 0x89, 0x61, 0x58, 0x56,
    0x25, 0xb8,

    /* U+0063 "c" */
    0x2e, 0x18, 0x89, 0x2, 0x40, 0x62, 0xb, 0x80,

    /* U+0064 "d" */
    0x2, 0x40, 0x92, 0xf5, 0x89, 0x92, 0x64, 0x96,
    0x24, 0xad,

    /* U+0065 "e" */
    0x2e, 0x14, 0x87, 0xf5, 0x40, 0x61, 0xb, 0x80,

    /* U+0066 "f" */
    0x1c, 0x30, 0x30, 0xb8, 0x30, 0x30, 0x30, 0x30,
    0x30,

    /* U+0067 "g" */
    0x3f, 0x58, 0x99, 0x26, 0x49, 0x62, 0x4b, 0xd0,
    0x20, 0xb8,

    /* U+0068 "h" */
    0x60, 0x18, 0x7, 0xe1, 0x8c, 0x62, 0x18, 0x86,
    0x21, 0x88,

    /* U+0069 "i" */
    0x20, 0x66, 0x66, 0x66,

    /* U+006A "j" */
    0x14, 0x1, 0x86, 0x18, 0x61, 0x86, 0x18, 0xc0,

    /* U+006B "k" */
    0x60, 0x18, 0x6, 0x31, 0xb0, 0x78, 0x1f, 0x6,
    0x61, 0x8c,

    /* U+006C "l" */
    0x66, 0x66, 0x66, 0x66,

    /* U+006D "m" */
    0x7e, 0xb5, 0x8d, 0x36, 0x20, 0xd8, 0x83, 0x62,
    0xd, 0x88, 0x30,

    /* U+006E "n" */
    0x6e, 0x18, 0xc6, 0x21, 0x88, 0x62, 0x18, 0x80,

    /* U+006F "o" */
    0x2e, 0x18, 0x95, 0x1a, 0x46, 0x62, 0x4b, 0x80,

    /* U+0070 "p" */
    0x7a, 0x18, 0x96, 0x15, 0x85, 0x62, 0x5f, 0x86,
    0x1, 0x80,

    /* U+0071 "q" */
    0x3f, 0x58, 0x99, 0x26, 0x49, 0x62, 0x4f, 0xd0,
    0x24, 0x9,

    /* U+0072 "r" */
    0x1, 0xe6, 0x18, 0x61, 0x86, 0x0,

    /* U+0073 "s" */
    0x2d, 0x18, 0x83, 0x40, 0x2c, 0x53, 0xf, 0x80,

    /* U+0074 "t" */
    0x10, 0xcb, 0x4c, 0x30, 0xc3, 0xd,

    /* U+0075 "u" */
    0x52, 0x14, 0x85, 0x21, 0x48, 0x63, 0xf, 0xc0,

    /* U+0076 "v" */
    0x83, 0x14, 0x82, 0x50, 0xe0, 0x2c, 0x6, 0x0,

    /* U+0077 "w" */
    0x82, 0x21, 0x5c, 0xc2, 0xa6, 0xe, 0x64, 0x38,
    0xd0, 0x93, 0x0,

    /* U+0078 "x" */
    0x53, 0xe, 0x42, 0xc0, 0xb0, 0x39, 0x24, 0xc0,

    /* U+0079 "y" */
    0x83, 0x56, 0x29, 0x38, 0x28, 0x18, 0x20, 0x60,

    /* U+007A "z" */
    0x7f, 0x5, 0xc, 0x24, 0x30, 0xbf,

    /* U+007B "{" */
    0x8, 0x93, 0xc, 0x32, 0x83, 0xc, 0x30, 0x90,
    0x80,

    /* U+007C "|" */
    0x22, 0x22, 0x22, 0x22, 0x21,

    /* U+007D "}" */
    0x40, 0x83, 0xc, 0x30, 0x63, 0xc, 0x30, 0x84,
    0x0,

    /* U+007E "~" */
    0x3c, 0x81, 0x38
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 37, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 39, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 51, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 7, .adv_w = 88, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 19, .adv_w = 79, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 33, .adv_w = 101, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 87, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 28, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 59, .adv_w = 50, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 68, .adv_w = 51, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 77, .adv_w = 69, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 84, .adv_w = 79, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 92, .adv_w = 31, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 94, .adv_w = 40, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 95, .adv_w = 42, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 59, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 105, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 79, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 163, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 193, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 37, .box_w = 2, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 206, .adv_w = 32, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 210, .adv_w = 71, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 215, .adv_w = 77, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 219, .adv_w = 74, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 226, .adv_w = 68, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 123, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 254, .adv_w = 92, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 87, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 300, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 77, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 320, .adv_w = 95, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 99, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 40, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 77, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 87, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 76, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 380, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 99, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 89, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 445, .adv_w = 85, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 457, .adv_w = 83, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 83, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 90, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 90, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 122, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 515, .adv_w = 88, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 84, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 539, .adv_w = 84, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 549, .adv_w = 40, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 558, .adv_w = 59, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 567, .adv_w = 40, .box_w = 2, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 573, .adv_w = 59, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 577, .adv_w = 65, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 578, .adv_w = 49, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 580, .adv_w = 77, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 588, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 598, .adv_w = 74, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 616, .adv_w = 75, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 624, .adv_w = 51, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 633, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 643, .adv_w = 77, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 653, .adv_w = 37, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 657, .adv_w = 36, .box_w = 3, .box_h = 10, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 665, .adv_w = 72, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 675, .adv_w = 37, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 679, .adv_w = 120, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 690, .adv_w = 77, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 698, .adv_w = 80, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 706, .adv_w = 79, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 716, .adv_w = 80, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 726, .adv_w = 49, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 732, .adv_w = 73, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 740, .adv_w = 47, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 746, .adv_w = 77, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 754, .adv_w = 68, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 762, .adv_w = 104, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 773, .adv_w = 70, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 781, .adv_w = 67, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 789, .adv_w = 70, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 795, .adv_w = 49, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 804, .adv_w = 39, .box_w = 2, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 809, .adv_w = 49, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 818, .adv_w = 94, .box_w = 6, .box_h = 2, .ofs_x = 0, .ofs_y = 2}
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
    -3, -8, -8, -9, -4, -5, -5, -5,
    -5, -2, -2, -5, -2, -5, -6, 1,
    -8, -8, -9, -4, -5, -5, -5, -5,
    -2, -2, -5, -2, -5, -6, 1, 2,
    1, 2, -13, -13, -13, -13, -17, -9,
    -9, -5, -1, -1, -1, -1, -10, -1,
    -7, -5, -7, -1, -1, -1, -4, -3,
    -4, 1, -2, -2, -4, -2, -2, -1,
    -1, -8, -8, -2, -2, -2, -2, -3,
    -2, 2, -1, -1, -1, -1, -1, -1,
    -1, -1, -2, -2, -2, -18, -18, -13,
    -21, 2, -3, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, 1, -2, 1,
    -2, 1, -2, 1, -2, -2, -5, -2,
    -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -3, -5, -3,
    -26, -26, 1, -5, -5, -5, -5, -21,
    -4, -14, -11, -19, -3, -10, -7, -10,
    1, -2, 1, -2, 1, -2, 1, -2,
    -8, -8, -2, -2, -2, -2, -3, -2,
    -25, -25, -11, -16, -2, -2, -1, -1,
    -1, -1, -1, -1, -1, 1, 1, 1,
    -3, -2, -2, -3, -6, -1, -4, -3,
    -17, -18, -17, -6, -2, -2, -19, -2,
    -2, -1, 1, 1, 1, 1, -9, -8,
    -8, -8, -8, -9, -9, -8, -9, -8,
    -6, -9, -7, -6, -4, -6, -6, -5,
    -2, 2, -18, -3, -18, -6, -1, -1,
    -1, -1, 1, -4, -3, -3, -3, -3,
    -4, -3, -2, -2, -1, -1, 1, 1,
    -10, -5, -10, -3, 1, 1, -3, -2,
    -2, -2, -2, -2, -2, -2, -1, 1,
    -4, -2, -2, -2, -2, 1, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2,
    2, -4, -16, -4, -16, -7, -2, -2,
    -7, -2, -2, -1, 1, -7, 1, 1,
    1, 1, 1, -6, -5, -5, -5, -2,
    -5, -3, -3, -5, -3, -5, -3, -5,
    -2, -3, -2, -2, -2, -2, 1, 1,
    -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -1, -2, -2, -2, -1, -1,
    -5, -5, -1, -1, -2, -2, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    1, 1, 2, 1, -2, -2, -2, -2,
    -2, 1, -8, -8, -2, -2, -2, -2,
    -2, -8, -8, -8, -8, -11, -11, -1,
    -2, -1, -1, -2, -2, -1, -1, -1,
    -1, 1, 1, -10, -10, -3, -1, -1,
    -1, 1, -1, -2, -1, 4, 1, 1,
    1, -2, 1, 1, -8, -8, -1, -1,
    -1, -1, 1, -1, -1, -1, -10, -10,
    -2, -2, -2, -2, -2, -2, 1, 1,
    -8, -8, -1, -1, -1, -1, 1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1,
    -2, -2
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
const lv_font_t ui_font_FontRoboto10 = {
#else
lv_font_t ui_font_FontRoboto10 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 13,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONTROBOTO10*/

