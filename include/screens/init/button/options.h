/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options screen button init header
*/

#ifndef SCR_OPTIONS_BUTTON_INIT_H_
#define SCR_OPTIONS_BUTTON_INIT_H_

static const int OPTIONS_BUTTON_NB = 1;
static const int SPRITE_OFFSET = 9;

void options_button_function_go_scr_home(gm_t *gm);

static const game_func OPTIONS_BUTTON_FUNCS[] = {
    &options_button_function_go_scr_home,
};

static const int OPTIONS_BUTTON_ANIMATION_FUNC_IDS[] = {
    0,
};

static const collision_type_e OPTIONS_BUTTON_COLLISION_TYPE[] = {
    RECT_CENTER,
};

#endif /* !SCR_OPTIONS_BUTTON_INIT_H_ */
