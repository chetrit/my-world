/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** home screen button init header
*/

#ifndef SCR_HOME_BUTTON_INIT_H_
#define SCR_HOME_BUTTON_INIT_H_

static const int HOME_BUTTON_NB = 3;
static const int SPRITE_OFFSET = 2;
static const int SOUND_OFFSET = 0;

void home_button_function_go_scr_map_selection(gm_t *gm);
void home_button_function_go_scr_options(gm_t *gm);
void home_button_function_quit_game(gm_t *gm);

static const game_func HOME_BUTTON_FUNCS[] = {
    &home_button_function_go_scr_map_selection,
    &home_button_function_go_scr_options,
    &home_button_function_quit_game,
};

static const int HOME_BUTTON_ANIMATION_FUNC_IDS[] = {
    0, 0, 0,
};

static const collision_type_e HOME_BUTTON_COLLISION_TYPE[] = {
    RECT_CENTER, RECT_CENTER, RECT_CENTER,
};

#endif /* !SCR_HOME_BUTTON_INIT_H_ */
