/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** sequence animation
*/

#include <stdlib.h>
#include <math.h>
#include "game.h"

void game_animation_square_x(gm_t *gm)
{
    static int pos = -1;
    static int counter = -1;
    map_t *map = &gm->game.map;

    counter = (counter + 1) % 5;
    if (counter != 0)
        return;
    for (int y = 0; y < map->params.map.y; y++) {
        if (pos + 1 < map->params.map.x)
            map->data.map_3d[y][pos + 1]
                = (map->params.map.y - pos)
                    * (map->params.map.y - pos) / 50 + 1;
    }
    if (++pos == map->params.map.y) {
        pos = -1;
        counter = -1;
        gm->game.animation.is_active = 0;
    }
}
