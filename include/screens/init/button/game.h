/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game screen button init header
*/

#ifndef SCR_GAME_BUTTON_INIT_H_
#define SCR_GAME_BUTTON_INIT_H_

static const int GAME_BUTTON_NB = 34;
static const int SPRITE_OFFSET = 42;

void game_button_function_go_scr_home(gm_t *gm);
void game_button_function_random_gen(gm_t *gm);
void game_button_function_animation_decrement(gm_t *gm);
void game_button_function_animation_increment(gm_t *gm);
void game_button_function_call_animation(gm_t *gm);
void game_button_function_tools_decrement(gm_t *gm);
void game_button_function_tools_increment(gm_t *gm);
void game_button_function_call_tools(gm_t *gm);
void map_end_animation(gm_t *gm);

void game_burger_assets_show_hide(gm_t *gm);
void game_burger_paint_show_hide(gm_t *gm);
void game_burger_operate_show_hide(gm_t *gm);
void game_burger_brush_show_hide(gm_t *gm);
void game_burger_save_show_hide(gm_t *gm);

void game_burger_assets_house(gm_t *gm);
void game_burger_assets_tree(gm_t *gm);
void game_burger_assets_animal(gm_t *gm);
void game_burger_assets_human(gm_t *gm);

void game_burger_paint_rock(gm_t *gm);
void game_burger_paint_plain(gm_t *gm);
void game_burger_paint_dirt(gm_t *gm);
void game_burger_paint_sand(gm_t *gm);

void game_burger_operate_no_idea(gm_t *gm);

void game_burger_brush_no_idea(gm_t *gm);

void game_burger_save_save(gm_t *gm);
void game_burger_save_save_as(gm_t *gm);
void game_burger_save_rename(gm_t *gm);
void game_burger_save_no_idea(gm_t *gm);

static const game_func GAME_BUTTON_FUNCS[] = {
    &game_button_function_go_scr_home,
    /**/
    &game_button_function_tools_decrement,
    &game_button_function_tools_increment,
    &game_button_function_call_tools,
    &game_button_function_call_tools,
    /**/
    &game_button_function_animation_decrement,
    &game_button_function_animation_increment,
    &game_button_function_call_animation,
    &map_end_animation,
    /**/
    &game_burger_assets_show_hide,
    &game_burger_paint_show_hide,
    &game_burger_operate_show_hide,
    &game_burger_brush_show_hide,
    &game_burger_save_show_hide,
    /**/
    &game_burger_assets_house,
    &game_burger_assets_tree,
    &game_burger_assets_animal,
    &game_burger_assets_human,
    /**/
    &game_burger_paint_rock,
    &game_burger_paint_plain,
    &game_burger_paint_dirt,
    &game_burger_paint_sand,
    /**/
    &game_burger_operate_no_idea,
    &game_burger_operate_no_idea,
    &game_burger_operate_no_idea,
    &game_burger_operate_no_idea,
    /**/
    &game_burger_brush_no_idea,
    &game_burger_brush_no_idea,
    &game_burger_brush_no_idea,
    &game_burger_brush_no_idea,
    /**/
    &game_burger_save_save,
    &game_burger_save_save_as,
    &game_burger_save_rename,
    &game_burger_save_no_idea,
};

static const int GAME_BUTTON_ANIMATION_FUNC_IDS[] = {
    3,
    /**/
    1, 1, 1, 1,
    /**/
    1, 1, 1, 1,
    /**/
    1, 1, 1, 1, 1,
    /**/
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
};

static const collision_type_e GAME_BUTTON_COLLISION_TYPE[] = {
    RECT_CENTER,
    /**/
    CIRCLE_CENTER, CIRCLE_CENTER, CIRCLE_CENTER, RECT_CENTER,
    /**/
    CIRCLE_CENTER, CIRCLE_CENTER, CIRCLE_CENTER, RECT_CENTER,
    /**/
    RECT_CENTER, RECT_CENTER, RECT_CENTER, RECT_CENTER, RECT_CENTER,
    /**/
    RECT_CENTER, RECT_CENTER, RECT_CENTER, RECT_CENTER,
    RECT_CENTER, RECT_CENTER, RECT_CENTER, RECT_CENTER,
    RECT_CENTER, RECT_CENTER, RECT_CENTER, RECT_CENTER,
    RECT_CENTER, RECT_CENTER, RECT_CENTER, RECT_CENTER,
    RECT_CENTER, RECT_CENTER, RECT_CENTER, RECT_CENTER,
};

#endif /* !SCR_GAME_BUTTON_INIT_H_ */
