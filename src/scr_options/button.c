/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options button init
*/

#include <stdlib.h>
#include "game.h"
#include "screens/init/button/options.h"

void options_button_create(scr_options_t *scr, game_objects_t *go)
{
    scr->buttons = (obj_buttons_t){
        (game_func *)OPTIONS_BUTTON_FUNCS,
        go->sprites + SPRITE_OFFSET,
        go->sprite_is_hidden + SPRITE_OFFSET,
        OPTIONS_BUTTON_ANIMATION_FUNC_IDS,
        OPTIONS_BUTTON_COLLISION_TYPE,
        go->sounds,
        go->sprite_rect + SPRITE_OFFSET,
        go->sprite_pos + SPRITE_OFFSET,
        go->sprite_size + SPRITE_OFFSET,
        1,
        -1,
        OPTIONS_BUTTON_NB
    };
}
