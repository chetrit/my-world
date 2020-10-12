/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** tiles keyboard
*/

#include "game.h"

void tile_outline_toggle(gm_t *gm)
{
    gm->game.map.params.is_tile_outline =
        !gm->game.map.params.is_tile_outline;
}
