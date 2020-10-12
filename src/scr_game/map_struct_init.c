/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map initialisation
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "game.h"
#include "map/consts.h"
#include "map/init.h"

void water_tile_set_point(map_t *map)
{
    sfVector2f point = project_iso_point(0, 0, -1.0f, map);

    sfConvexShape_setPoint(map->data.water_tile, 2, point);
    point = project_iso_point(map->params.map.y - 1, 0, -1.0f, map);
    sfConvexShape_setPoint(map->data.water_tile, 1, point);
    point = project_iso_point(0, map->params.map.x - 1, -1.0f, map);
    sfConvexShape_setPoint(map->data.water_tile, 3, point);
    point = project_iso_point(
        map->params.map.y - 1, map->params.map.x - 1, -1.0f, map);
    sfConvexShape_setPoint(map->data.water_tile, 0, point);
}

static int water_tile_init(map_t *map)
{
    if (map->data.water_tile == NULL) {
        return (1);
    } else {
        sfConvexShape_setOrigin(map->data.water_tile,
            (sfVector2f){SCREEN_SIZE.x / 2.0f, SCREEN_SIZE.y / 2.0f});
        sfConvexShape_setPosition(map->data.water_tile,
            (sfVector2f){SCREEN_SIZE.x / 2.0f, SCREEN_SIZE.y / 2.0f});
        sfConvexShape_setPointCount(map->data.water_tile, 4);
        sfConvexShape_setFillColor(map->data.water_tile, WATER_COLOR);
        return (0);
    }
}

static int corner_init(map_t *map)
{
    if (map->events.highlighted_corner == NULL) {
        return (1);
    } else {
        sfCircleShape_setFillColor(map->events.highlighted_corner, sfWhite);
        sfCircleShape_setRadius(map->events.highlighted_corner,
            HIGHLIGHT_CIRCLE_RADIUS);
        return (0);
    }
}

int game_map_init_struct(map_t *map)
{
    *map = (map_t) {
        .params = {
            .map = {50, 50}, .map_sampling = 50,
            .map_horizontal_angle = 15.0 * M_PI / 180,
            .map_vertical_angle = 35 * M_PI / 180,
            .map_shift = {940, 60}, .map_btm_coef = 3,
            .rect = {737, 2806, 80, 80},
            .zoom_level = {1.0f, 1.0f}, .offset = {0, 0}, .speed = {0, 0},
            .lowest_point = 0.0f, .is_tile_outline = true,
            .tile_color_func_id = 0, .tile_color_func_nb = TILE_COLOR_FUNC_NB,
            .tile_highlight_func_id = 0,
            .tile_highlight_func_nb = TILE_HIGHLIGHT_FUNC_NB
        },
        .data = {NULL, NULL, NULL, {NULL, NULL}, sfConvexShape_create(),
            TILE_COLOR_FUNCS, TILE_HIGHLIGHT_FUNCS},
        .events = {false, {0, 0}, sfCircleShape_create(), 0}
    };
    return (water_tile_init(map) || corner_init(map));
}
