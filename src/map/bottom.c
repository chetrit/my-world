/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** bottom
*/

#include <stdlib.h>
#include "game.h"

void bottom_draw(gm_t *gm)
{
    for (int i = 0; i < gm->game.map.params.map.x - 1; i++) {
        if (gm->game.map.data.map_3d[gm->game.map.params.map.y - 1][i] != -2.0f
            || gm->game.map.data.map_3d[gm->game.map.params.map.y - 1][i + 1]
            != -2.0f) {
            sfRenderWindow_drawConvexShape(
                gm->window,  gm->game.map.data.bottom.right[i], NULL);
        }
    }
    for (int i = 0; i < gm->game.map.params.map.y - 1; i++) {
        if (gm->game.map.data.map_3d[i][gm->game.map.params.map.x - 1] != -2.0f
            || gm->game.map.data.map_3d[i + 1][gm->game.map.params.map.x - 1]
            != -2.0f) {
            sfRenderWindow_drawConvexShape(
                gm->window,  gm->game.map.data.bottom.left[i], NULL);
        }
    }
}
