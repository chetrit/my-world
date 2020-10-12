/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_selection button init
*/

#include <stdlib.h>
#include "game.h"
#include "screens/init/button/map_selection.h"

void map_selection_button_create(scr_map_selection_t *scr, game_objects_t *go)
{
    scr->buttons = (obj_buttons_t){
        (game_func *)MAP_SELECTION_BUTTON_FUNCS,
        go->sprites + SPRITE_OFFSET,
        go->sprite_is_hidden + SPRITE_OFFSET,
        MAP_SELECTION_BUTTON_ANIMATION_FUNC_IDS,
        MAP_SELECTION_BUTTON_COLLISION_TYPE,
        go->sounds + SOUND_OFFSET,
        go->sprite_rect + SPRITE_OFFSET,
        go->sprite_pos + SPRITE_OFFSET,
        go->sprite_size + SPRITE_OFFSET,
        1,
        -1,
        MAP_SELECTION_BUTTON_NB
    };
}
