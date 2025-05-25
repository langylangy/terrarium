SET(SOURCES screens/ui_MainScreen.c
    screens/ui_ScreenMenu.c
    screens/ui_ScreenAccel.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_1882603517.c
    images/ui_img_942215904.c
    images/ui_img_1798728470.c
    images/ui_img_1601502596.c
    images/ui_img_scull_png.c
    fonts/ui_font_FontRoboto12.c
    fonts/ui_font_FontRoboto20.c
    fonts/ui_font_FontSpeed.c)

add_library(ui ${SOURCES})
