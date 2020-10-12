/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game button init
*/

#include <stdlib.h>
#include "game.h"
#include "screens/init/button/game.h"

void game_button_create(scr_game_t *scr, game_objects_t *go)
{
    scr->buttons = (obj_buttons_t){
        (game_func *)GAME_BUTTON_FUNCS,
        go->sprites + SPRITE_OFFSET,
        go->sprite_is_hidden + SPRITE_OFFSET,
        GAME_BUTTON_ANIMATION_FUNC_IDS,
        GAME_BUTTON_COLLISION_TYPE,
        go->sounds,
        go->sprite_rect + SPRITE_OFFSET,
        go->sprite_pos + SPRITE_OFFSET,
        go->sprite_size + SPRITE_OFFSET,
        1,
        -1,
        GAME_BUTTON_NB
    };
}
