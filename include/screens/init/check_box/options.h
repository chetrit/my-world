/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options screen check_box init header
*/

#ifndef SCR_OPTIONS_CHECK_BOX_INIT_H_
#define SCR_OPTIONS_CHECK_BOX_INIT_H_


static const int OPTIONS_CHECK_BOXES_NB = 4;
static const int SPRITE_OFFSET = 15;

void options_check_boxes_function_music_on_off(gm_t *gm);
void options_check_boxes_function_sound_on_off(gm_t *gm);
void options_check_boxes_function_help_box_on_off(gm_t *gm);
void options_check_boxes_function_change_fps(gm_t *gm);

static const game_func OPTIONS_CHECK_BOXES_FUNCS[] = {
    &options_check_boxes_function_music_on_off,
    &options_check_boxes_function_sound_on_off,
    &options_check_boxes_function_help_box_on_off,
    &options_check_boxes_function_change_fps
};

static const int OPTIONS_CHECK_BOX_ANIMATION_FUNC_IDS[] = {
    3, 3, 3, 3,
    3, 3, 3, 3,
};

static const collision_type_e OPTIONS_CHECK_BOX_COLLISION_TYPE[] = {
    RECT_CENTER, RECT_CENTER, RECT_CENTER, RECT_CENTER,
    RECT_CENTER, RECT_CENTER, RECT_CENTER, RECT_CENTER,
};

#endif /* !SCR_OPTIONS_CHECK_BOX_INIT_H_ */
