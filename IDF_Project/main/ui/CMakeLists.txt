SET(SOURCES components/ui_comp_onoffcomp.c
    components/ui_comp.c
    screens/ui_MainScreen.c
    screens/ui_ScreenMenu.c
    screens/ui_ScreenAccel.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_1966217086.c
    fonts/ui_font_FontAwesomepro6light20.c
    fonts/ui_font_FontAwesomepro6light30.c
    fonts/ui_font_FontAwesomepro6lightSmall.c
    fonts/ui_font_FontAwesomepro6solid20.c
    fonts/ui_font_titulky.c)

add_library(ui ${SOURCES})
