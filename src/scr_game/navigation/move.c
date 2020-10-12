/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** move management
*/

#include "game.h"

void game_move_map(gm_t *gm)
{
    map_t *map = &gm->game.map;

    if (map->params.speed.x != 0.0f || map->params.speed.y != 0.0f) {
        map->params.offset.x += map->params.speed.x;
        map->params.offset.y += map->params.speed.y;
        sfView_move(gm->go.map_view, map->params.speed);
    }
}
