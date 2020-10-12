/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** animation button functions
*/

#include <stdlib.h>
#include "game.h"

void game_button_function_animation_increment(gm_t *gm)
{
    gm->game.animation.id = (gm->game.animation.id + 1) % gm->game.animation.nb;
}

void game_button_function_animation_decrement(gm_t *gm)
{
    if (gm->game.animation.id == 0) {
        gm->game.animation.id = gm->game.animation.nb - 1;
    } else {
        gm->game.animation.id -= 1;
    }
}

void game_button_function_call_animation(gm_t *gm)
{
    gm->game.animation.is_active = 1;
}
