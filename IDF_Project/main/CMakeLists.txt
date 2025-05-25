  file(GLOB_RECURSE SRC_UI
      "${CMAKE_CURRENT_LIST_DIR}/ui/*.c")

idf_component_register(
    SRCS
        "bsp_qmi8658.c"
        "owb_rmt.c"
        "owb.c"
        "owb_gpio.c"
        "ds18b20.c"
        "gauge.c"
        "main.c"
        "ui/fonts/ui_font_FontAwesomepro6lightSmall.c"
        "ui/fonts/ui_font_FontAwesomepro6light20.c"
        "ui/fonts/ui_font_FontAwesomepro6light30.c"
        ${SRC_UI}
      INCLUDE_DIRS
          "."
          "ui"
          "ui/images"
          "ui/fonts"
          "../include"
    REQUIRES
        spiffs
)
# Create SPIFFS image from spiffs_data directory
spiffs_create_partition_image(spiffs ../spiffs_data FLASH_IN_PROJECT)