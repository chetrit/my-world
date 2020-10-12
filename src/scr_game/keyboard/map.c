/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** brush size
*/

#include "game.h"

void map_smooth_reset(gm_t *gm)
{
    gm->game.animation.is_active = true;
    gm->game.animation.id = 5;
}

void map_end_animation(gm_t *gm)
{
    while (gm->game.animation.is_active == 1) {
        (gm->game.animation.funcs[gm->game.animation.id])(gm);
    }
}
