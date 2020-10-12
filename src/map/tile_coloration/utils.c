/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** tile coloration utils
*/

#include <stdlib.h>
#include "game.h"

void map_tile_coloration_func_id_increment(gm_t *gm)
{
    gm->game.map.params.tile_color_func_id
        = (gm->game.map.params.tile_color_func_id + 1)
        % gm->game.map.params.tile_color_func_nb;
    if (gm->game.map.params.tile_color_func_id == 3) {
        for (int i = 0; i < gm->game.map.params.map_nb_tiles; ++i) {
            sfConvexShape_setTextureRect(
                gm->game.map.data.tiles[i], (sfIntRect){0, 0, 0, 0});
        }
    }
}

void map_tile_coloration_func_id_decrement(gm_t *gm)
{
    if (gm->game.map.params.tile_color_func_id == 0) {
        gm->game.map.params.tile_color_func_id
            = gm->game.map.params.tile_color_func_nb - 1;
    } else {
        gm->game.map.params.tile_color_func_id -= 1;
    }
    if (gm->game.map.params.tile_color_func_id == 0) {
        for (int i = 0; i < gm->game.map.params.map_nb_tiles; ++i) {
            sfConvexShape_setTextureRect(
                gm->game.map.data.tiles[i], (sfIntRect){0, 0, 0, 0});
        }
    }
}
