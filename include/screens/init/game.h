/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game screen init header
*/

#ifndef SCR_GAME_INIT_H_
#define SCR_GAME_INIT_H_

void game_button_create(scr_game_t *scr, game_objects_t *go);
void game_help_box_create(scr_game_t *scr, game_objects_t *go);

static const int GAME_ANIMATION_NB = 8;

void game_animation_wave_x(gm_t *gm);
void game_animation_wave_y(gm_t *gm);
void game_animation_rotate_build_of_1(gm_t *gm);
void game_animation_rotate_dig_of_1(gm_t *gm);
void game_animation_square_x(gm_t *gm);
void game_animation_smooth_reset(gm_t *gm);
void game_animation_math_structure(gm_t *gm);
void game_animation_math_fun_rand(gm_t *gm);

static game_func GAME_ANIMATION_FUNCS[] = {
    &game_animation_wave_x,
    &game_animation_wave_y,
    &game_animation_rotate_build_of_1,
    &game_animation_rotate_dig_of_1,
    &game_animation_square_x,
    &game_animation_smooth_reset,
    &game_animation_math_structure,
    &game_animation_math_fun_rand,
};

static const int GAME_TOOL_NB = 4;

static const tool_type_e GAME_TOOL_TYPE[] = {
    TOOL_TILE, TOOL_TILE, TOOL_CORNER, TOOL_TILE,
};

void game_tool_dig_or_mountain_add(gm_t *gm);
void game_tool_reset_to_0(gm_t *gm);
void game_tool_dig_or_mountain_corner(gm_t *gm);
void game_tool_dig_or_mountain_add_once(gm_t *gm);

static game_func GAME_TOOL_FUNCS[] = {
    &game_tool_dig_or_mountain_add,
    &game_tool_reset_to_0,
    &game_tool_dig_or_mountain_corner,
    &game_tool_dig_or_mountain_add_once,
};

#endif /* !SCR_GAME_INIT_H_ */
