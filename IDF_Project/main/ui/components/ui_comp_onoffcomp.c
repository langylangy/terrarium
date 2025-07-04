// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.2
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

// COMPONENT OnOffComp

lv_obj_t * ui_OnOffComp_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_OnOffComp;
    cui_OnOffComp = lv_obj_create(comp_parent);
    lv_obj_remove_style_all(cui_OnOffComp);
    lv_obj_set_height(cui_OnOffComp, 50);
    lv_obj_set_width(cui_OnOffComp, lv_pct(100));
    lv_obj_set_x(cui_OnOffComp, 2);
    lv_obj_set_y(cui_OnOffComp, 120);
    lv_obj_set_align(cui_OnOffComp, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(cui_OnOffComp, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_Switch1;
    cui_Switch1 = lv_switch_create(cui_OnOffComp);
    lv_obj_set_width(cui_Switch1, 50);
    lv_obj_set_height(cui_Switch1, 25);
    lv_obj_set_x(cui_Switch1, -10);
    lv_obj_set_y(cui_Switch1, 0);
    lv_obj_set_align(cui_Switch1, LV_ALIGN_RIGHT_MID);

    lv_obj_t * cui_Container19;
    cui_Container19 = lv_obj_create(cui_OnOffComp);
    lv_obj_remove_style_all(cui_Container19);
    lv_obj_set_width(cui_Container19, 145);
    lv_obj_set_height(cui_Container19, 20);
    lv_obj_set_align(cui_Container19, LV_ALIGN_LEFT_MID);
    lv_obj_set_flex_flow(cui_Container19, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_Container19, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Container19, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_Label11;
    cui_Label11 = lv_label_create(cui_Container19);
    lv_obj_set_width(cui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Label11, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_Label11, "Světlo");
    lv_obj_set_style_text_font(cui_Label11, &ui_font_titulky, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Label12;
    cui_Label12 = lv_label_create(cui_Container19);
    lv_obj_set_width(cui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Label12, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_Label12, "UVB");
    lv_obj_set_style_text_font(cui_Label12, &ui_font_titulky, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Label12, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Label12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Label12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Label12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_ONOFFCOMP_NUM);
    children[UI_COMP_ONOFFCOMP_ONOFFCOMP] = cui_OnOffComp;
    children[UI_COMP_ONOFFCOMP_SWITCH1] = cui_Switch1;
    children[UI_COMP_ONOFFCOMP_CONTAINER19] = cui_Container19;
    children[UI_COMP_ONOFFCOMP_CONTAINER19_LABEL11] = cui_Label11;
    children[UI_COMP_ONOFFCOMP_CONTAINER19_LABEL12] = cui_Label12;
    lv_obj_add_event_cb(cui_OnOffComp, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_OnOffComp, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_OnOffComp_create_hook(cui_OnOffComp);
    return cui_OnOffComp;
}

