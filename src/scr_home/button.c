/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** home button init
*/

#include <stdlib.h>
#include "game.h"
#include "screens/init/button/home.h"

void home_button_create(scr_home_t *scr, game_objects_t *go)
{
    scr->buttons = (obj_buttons_t){
        (game_func *)HOME_BUTTON_FUNCS,
        go->sprites + SPRITE_OFFSET,
        go->sprite_is_hidden + SPRITE_OFFSET,
        HOME_BUTTON_ANIMATION_FUNC_IDS,
        HOME_BUTTON_COLLISION_TYPE,
        go->sounds + SOUND_OFFSET,
        go->sprite_rect + SPRITE_OFFSET,
        go->sprite_pos + SPRITE_OFFSET,
        go->sprite_size + SPRITE_OFFSET,
        1,
        -1,
        HOME_BUTTON_NB
    };
}
