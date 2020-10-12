/*
** EPITECH PROJECT, 2020
** tiles
** File description:
** all about the tiles for the map
*/

#include "game.h"
#include "map/consts.h"

void draw_tiles(gm_t *gm)
{
    map_t *map = &gm->game.map;

    for (int i = 0; i < map->params.map.y - 1; i++) {
        for (int j = 0; j < map->params.map.x - 1; j++)
            if (MAX(map->data.map_3d[i][j], (MAX(map->data.map_3d[i + 1][j + 1],
                (MAX(map->data.map_3d[i + 1][j], map->data.map_3d[i][j + 1])))))
                < 0.0)
                sfRenderWindow_drawConvexShape(gm->window, map->data.tiles
                    [(i * (map->params.map.x - 1)) + j], NULL);
    }
    sfRenderWindow_drawConvexShape(gm->window, map->data.water_tile, NULL);
    for (int i = 0; i < map->params.map.y - 1; i++) {
        for (int j = 0; j < map->params.map.x - 1; j++)
            if (MAX(map->data.map_3d[i][j], (MAX(map->data.map_3d[i + 1][j + 1],
                (MAX(map->data.map_3d[i + 1][j], map->data.map_3d[i][j + 1])))))
                >= 0.0)
                sfRenderWindow_drawConvexShape(gm->window, map->data.tiles
                    [(i * (map->params.map.x - 1)) + j], NULL);
    }
}

void set_tile(
    sfConvexShape *tile, sfVector2f points[4],
    sfColor *new_color, bool is_tile_outline)
{
    sfConvexShape_setPoint(tile, 0, points[0]);
    sfConvexShape_setPoint(tile, 1, points[1]);
    sfConvexShape_setPoint(tile, 2, points[2]);
    sfConvexShape_setPoint(tile, 3, points[3]);
    sfConvexShape_setOutlineThickness(tile, is_tile_outline ?
        TILE_OUTLINE_THICKNESS : 0.0f);
    sfConvexShape_setFillColor(tile, *new_color);
}

void set_tiles(gm_t *gm)
{
    map_t *map = &gm->game.map;
    sfVector2f points[4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    sfColor new_color = {0, 100, 100, 200};

    for (int i = 0; i < map->params.map.y - 1; i++) {
        for (int j = 0; j < map->params.map.x - 1; j++) {
            points[0] = map->data.map_iso[i][j];
            points[1] = map->data.map_iso[i + 1][j];
            points[2] = map->data.map_iso[i + 1][j + 1];
            points[3] = map->data.map_iso[i][j + 1];
            (map->data.color_funcs[map->params.tile_color_func_id])
                (map, &new_color, i, j);
            set_tile(map->data.tiles[(i * (map->params.map.x - 1)) + j],
                points, &new_color, map->params.is_tile_outline);
        }
    }
}
