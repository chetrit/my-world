/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** smooth animation
*/

#include <stdbool.h>
#include "game.h"

UNUSED void game_animation_smooth_reset_other(gm_t *gm)
{
    map_t *map = &gm->game.map;
    bool is_modif = false;

    for (int i = 0; i < map->params.map.y; ++i) {
        for (int j = 0; j < map->params.map.x; ++j) {
            if (ABS(map->data.map_3d[i][j]) > 0.03f) {
                map->data.map_3d[i][j]
                    += map->data.map_3d[i][j] < 0 ? 0.03f : -0.03f;
                is_modif = true;
            } else {
                map->data.map_3d[i][j] = 0.0f;
            }
        }
    }
    if (is_modif == false) {
        gm->game.animation.is_active = 0;
    }
}

void game_animation_smooth_reset(gm_t *gm)
{
    map_t *map = &gm->game.map;
    bool is_modif = false;

    for (int i = 0; i < map->params.map.y; ++i) {
        for (int j = 0; j < map->params.map.x; ++j) {
            if (ABS(map->data.map_3d[i][j]) > 0.05f) {
                map->data.map_3d[i][j] /= 1.02f;
                is_modif = true;
            } else {
                map->data.map_3d[i][j] = 0.0f;
            }
        }
    }
    if (is_modif == false) {
        gm->game.animation.is_active = 0;
    }
}
