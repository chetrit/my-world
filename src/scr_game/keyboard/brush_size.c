/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** brush size
*/

#include "game.h"

void brush_size_decrement(gm_t *gm)
{
    gm->game.tools.brush_size -= gm->game.tools.brush_size <= 0 ? 0 : 1;
}

void brush_size_increment(gm_t *gm)
{
    gm->game.tools.brush_size = (gm->game.tools.brush_size + 1) % 1000;
}
