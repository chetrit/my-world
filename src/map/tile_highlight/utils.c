/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** tile highlighting utils
*/

#include <stdlib.h>
#include "game.h"

void map_tile_highlighting_func_id_increment(gm_t *gm)
{
    map_t *map = &gm->game.map;

    map->params.tile_highlight_func_id
        = (map->params.tile_highlight_func_id + 1)
        % map->params.tile_highlight_func_nb;
}

void map_tile_highlighting_func_id_decrement(gm_t *gm)
{
    map_t *map = &gm->game.map;

    if (map->params.tile_highlight_func_id == 0) {
        map->params.tile_highlight_func_id
            = map->params.tile_highlight_func_nb - 1;
    } else {
        map->params.tile_highlight_func_id -= 1;
    }
}
