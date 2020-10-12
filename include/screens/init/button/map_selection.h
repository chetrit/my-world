/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_selection screen button init header
*/

#ifndef SCR_MAP_SELECTION_BUTTON_INIT_H_
#define SCR_MAP_SELECTION_BUTTON_INIT_H_

static const int MAP_SELECTION_BUTTON_NB = 4;
static const int SPRITE_OFFSET = 26;
static const int SOUND_OFFSET = 0;

void map_selection_button_function_go_scr_home(gm_t *gm);
void map_selection_button_function_go_scr_game(gm_t *gm);
void map_selection_index_map_increment(gm_t *gm);
void map_selection_index_map_decrement(gm_t *gm);
void map_selection_map_create(gm_t *gm);

static const game_func MAP_SELECTION_BUTTON_FUNCS[] = {
    &map_selection_button_function_go_scr_home,
    &map_selection_button_function_go_scr_game,
    &map_selection_index_map_increment,
    &map_selection_index_map_decrement,
    &map_selection_map_create,
};

static const int MAP_SELECTION_BUTTON_ANIMATION_FUNC_IDS[] = {
    3, 3, 0, 0, 0,
};

static const collision_type_e MAP_SELECTION_BUTTON_COLLISION_TYPE[] = {
    RECT_CENTER, RECT_CENTER, RECT_CENTER, RECT_CENTER, RECT_CENTER
};

#endif /* !SCR_MAP_SELECTION_BUTTON_INIT_H_ */
