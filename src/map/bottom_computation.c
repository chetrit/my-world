/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** bottom
*/

#include <stdlib.h>
#include "game.h"

void bottom_fix_point_init_right(map_t *map)
{
    int samp_offset = map->params.map_sampling * map->params.map_btm_coef;
    sfVector2f point = {0.0f, 0.0f};

    for (int i = 0; i < map->params.map.x; i++) {
        point = project_iso_point(
            map->params.map.y - 1, i, map->params.lowest_point, map);
        point.y += samp_offset;
        if (i != 0) {
            sfConvexShape_setPoint(map->data.bottom.right[i - 1], 0, point);
        }
        if (i != map->params.map.x - 1) {
            sfConvexShape_setPoint(map->data.bottom.right[i], 1, point);
        }
    }
}

void bottom_fix_point_init_left(map_t *map)
{
    int samp_offset = map->params.map_sampling * map->params.map_btm_coef;
    sfVector2f point = {0.0f, 0.0f};

    for (int i = 0; i < map->params.map.y; i++) {
        point = project_iso_point(
            i, map->params.map.x - 1, map->params.lowest_point, map);
        point.y += samp_offset;
        if (i != 0) {
            sfConvexShape_setPoint(map->data.bottom.left[i - 1], 0, point);
        }
        if (i != map->params.map.y - 1) {
            sfConvexShape_setPoint(map->data.bottom.left[i], 1, point);
        }
    }
}

static void bottom_computation_upper(map_t *map)
{
    for (int i = 0; i < map->params.map.y; i++) {
        if (i != 0) {
            sfConvexShape_setPoint(map->data.bottom.left[i - 1], 3,
                map->data.map_iso[i][map->params.map.x - 1]);
        }
        if (i != map->params.map.y - 1) {
            sfConvexShape_setPoint(map->data.bottom.left[i], 2,
                map->data.map_iso[i][map->params.map.x - 1]);
        }
    }
    for (int i = 0; i < map->params.map.x; i++) {
        if (i != 0) {
            sfConvexShape_setPoint(map->data.bottom.right[i - 1], 3,
                map->data.map_iso[map->params.map.y - 1][i]);
        }
        if (i != map->params.map.x - 1) {
            sfConvexShape_setPoint(map->data.bottom.right[i], 2,
                map->data.map_iso[map->params.map.y - 1][i]);
        }
    }
}

void bottom_computation(map_t *map)
{
    bottom_fix_point_init_right(map);
    bottom_fix_point_init_left(map);
    bottom_computation_upper(map);
}
