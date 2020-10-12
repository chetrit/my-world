/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** 3d animation
*/

#include <stdlib.h>
#include <math.h>
#include "game.h"
#include "math_funcs.h"

void game_animation_line_by_line(gm_t *gm, math_3d_func *func)
{
    map_t *map = &gm->game.map;
    static sfVector2i vf = {0, 0};
    static int y = -1;

    if (++y < map->params.map.y) {
        for (int x = 0; x < map->params.map.x; ++x) {
            map->data.map_3d[y][x] = (*func)(
                (float)(x - map->params.map.x / 2 + vf.x),
                (float)(y - map->params.map.y / 2 + vf.y)
            );
        }
    } else {
        vf.x = rand() % (map->params.map.x / 2 + 1) * (rand() % 2 ? -1 : 1);
        vf.y = rand() % (map->params.map.y / 2 + 1) * (rand() % 2 ? -1 : 1);
        gm->game.animation.is_active = false;
        y = -1;
    }
}

void game_animation_by_time(gm_t *gm, math_3d_func *func)
{
    map_t *map = &gm->game.map;
    static float timer = -1.0f;
    static sfVector2i vf = {0, 0};

    timer += 0.005f;
    if (timer > 0.0f) {
        timer = 0.0f;
        vf.x = rand() % (map->params.map.x / 2 + 1) * (rand() % 2 ? -1 : 1);
        vf.y = rand() % (map->params.map.y / 2 + 1) * (rand() % 2 ? -1 : 1);
        gm->game.animation.is_active = false;
    }
    for (int y = 0; y < map->params.map.y; ++y) {
        for (int x = 0; x < map->params.map.x; ++x) {
            map->data.map_3d[y][x] = (*func)(
                (float)(x - map->params.map.x / 2 + vf.x) * timer,
                (float)(y - map->params.map.y / 2 + vf.y) * timer);
        }
    }
    if (timer == 0.0f)
        timer = -1.0f;
}
