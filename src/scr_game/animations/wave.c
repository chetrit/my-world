/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** wave animation
*/

#include <stdlib.h>
#include "game.h"

void game_animation_wave_y(gm_t *gm)
{
    static int pos = -1;
    static int counter = -1;

    counter = (counter + 1) % 5;
    if (counter != 0)
        return;
    for (int i = 0; i < gm->game.map.params.map.x; i++) {
        if (pos != -1)
            gm->game.map.data.map_3d[pos][i] -= 2.0f;
        if (pos + 1 < gm->game.map.params.map.y)
            gm->game.map.data.map_3d[pos + 1][i] += 2.0f;
    }
    if (++pos == gm->game.map.params.map.y) {
        pos = -1;
        counter = -1;
        gm->game.animation.is_active = 0;
    }
}

void game_animation_wave_x(gm_t *gm)
{
    static int pos = -1;
    static int counter = -1;

    counter = (counter + 1) % 5;
    if (counter == 0)
        return;
    for (int i = 0; i < gm->game.map.params.map.y; i++) {
        if (pos != -1)
            gm->game.map.data.map_3d[i][pos] -= 2.0f;
        if (pos + 1 < gm->game.map.params.map.x)
            gm->game.map.data.map_3d[i][pos + 1] += 2.0f;
    }
    if (++pos == gm->game.map.params.map.x) {
        pos = -1;
        counter = -1;
        gm->game.animation.is_active = 0;
    }
}
