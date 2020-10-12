/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** tiles highlight functions
*/

#include "game.h"
#include "map/consts.h"

void tile_highlight_function_fillcolor_standard(
    map_t *map, sfVector2i *mid, int range)
{
    sfConvexShape **tiles = map->data.tiles;
    sfVector2i *size = &map->params.map;

    for (int i = mid->y - range - 1; i < mid->y + range; ++i) {
        for (int j = mid->x - range - 1; j < mid->x + range; ++j) {
            if (i >= 0 && i < size->y - 1 && j >= 0 && j < size->x - 1) {
                sfConvexShape_setFillColor(
                    tiles[i * (size->x - 1) + j], HIGHLIGHT_COLOR);
            }
        }
    }
}

void tile_highlight_function_fillcolor_contour(
    map_t *map, sfVector2i *mid, int range)
{
    sfConvexShape **tiles = map->data.tiles;
    sfVector2i *size = &map->params.map;

    for (int j = mid->x - range - 1; j < mid->x + range; ++j) {
        if (mid->y - range - 1 >= 0 && j >= 0 && j < size->x - 1)
            sfConvexShape_setFillColor(tiles[(mid->y - range - 1)
                * (size->x - 1) + j], HIGHLIGHT_COLOR);
        if (mid->y + range - 1 < size->y - 1 && j >= 0 && j < size->x - 1)
            sfConvexShape_setFillColor(tiles[(mid->y + range - 1)
                * (size->x - 1) + j], HIGHLIGHT_COLOR);
    }
    for (int i = mid->y - range - 1; i < mid->y + range; ++i) {
        if (mid->x - range - 1 >= 0 && i >= 0 && i < size->y - 1)
            sfConvexShape_setFillColor(
                tiles[i * (size->x - 1) + mid->x - range - 1], HIGHLIGHT_COLOR);
        if (mid->x + range - 1 < size->x - 1 && i >= 0 && i < size->y - 1)
            sfConvexShape_setFillColor(
                tiles[i * (size->x - 1) + mid->x + range - 1], HIGHLIGHT_COLOR);
    }
}

void tile_highlight_function_outlinecolor_standard(
    map_t *map, sfVector2i *mid, int range)
{
    sfConvexShape **tiles = map->data.tiles;
    sfVector2i *size = &map->params.map;
    float thickness = map->params.is_tile_outline ? 0.0f : 1.5f;

    for (int i = mid->y - range - 1; i < mid->y + range; ++i) {
        for (int j = mid->x - range - 1; j < mid->x + range; ++j) {
            if (i >= 0 && i < size->y - 1 && j >= 0 && j < size->x - 1) {
                sfConvexShape_setOutlineThickness(
                    tiles[i * (size->x - 1) + j], thickness);
            }
        }
    }
}

void tile_highlight_function_outlinecolor_contour(
    map_t *map, sfVector2i *mid, int range)
{
    sfConvexShape **tiles = map->data.tiles;
    sfVector2i *size = &map->params.map;
    float thickness = map->params.is_tile_outline ? 0.0f : 1.5f;

    for (int j = mid->x - range - 1; j < mid->x + range; ++j) {
        if (mid->y - range - 1 >= 0 && j >= 0 && j < size->x - 1)
            sfConvexShape_setOutlineThickness(tiles[(mid->y - range - 1)
                * (size->x - 1) + j], thickness);
        if (mid->y + range - 1 < size->y - 1 && j >= 0 && j < size->x - 1)
            sfConvexShape_setOutlineThickness(tiles[(mid->y + range - 1)
                * (size->x - 1) + j], thickness);
    }
    for (int i = mid->y - range - 1; i < mid->y + range; ++i) {
        if (mid->x - range - 1 >= 0 && i >= 0 && i < size->y - 1)
            sfConvexShape_setOutlineThickness(tiles[i * (size->x - 1) + mid->x
                - range - 1], thickness);
        if (mid->x + range - 1 < size->x - 1 && i >= 0 && i < size->y - 1)
            sfConvexShape_setOutlineThickness(tiles[i * (size->x - 1) + mid->x
                + range - 1], thickness);
    }
}
