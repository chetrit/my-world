/*
** EPITECH PROJECT, 2020
** tiles
** File description:
** epileptic coloration for tiles
*/

#include <stdlib.h>
#include <math.h>
#include "game.h"

void tile_color_function_epi_soft(map_t *map, sfColor *color, int i, int j)
{
    float min = MIN(map->data.map_3d[i][j], (MIN(map->data.map_3d[i + 1][j + 1],
        (MIN(map->data.map_3d[i + 1][j], map->data.map_3d[i][j + 1])))));
    float max = MAX(map->data.map_3d[i][j], (MAX(map->data.map_3d[i + 1][j + 1],
        (MAX(map->data.map_3d[i + 1][j], map->data.map_3d[i][j + 1])))));

    color->g = ((rand() % 10 + 1) / 10.0f) * (map->data.map_3d[i][j]
        + map->data.map_3d[i][j + 1] + map->data.map_3d[i + 1][j]
        + map->data.map_3d[i + 1][j + 1] + 10) * 5.0f;
    color->r = ((rand() % 10 + 1) / 10.0f) * MIN(max * 25.0f, 255.0f);
    color->b = ((rand() % 10 + 1) / 10.0f)
        * MIN(ABS((max - min)) * 25.0f, 255.0f);
}

void tile_color_function_height(map_t *map, sfColor *color, int i, int j)
{
    double res = 50 + (map->data.map_3d[i][j] + map->data.map_3d[i][j + 1]
        + map->data.map_3d[i + 1][j] + map->data.map_3d[i + 1][j + 1]) * 3.0f;

    color->r = res;
    color->g = res;
    color->b = res;
}

void tile_color_function_cossin(map_t *map, sfColor *color, int i, int j)
{
    double res = (map->data.map_3d[i][j] + map->data.map_3d[i][j + 1]
        + map->data.map_3d[i + 1][j] + map->data.map_3d[i + 1][j + 1]);

    color->r = cos(33 * (j * j - i * i)) + sin(9 * (res)) * 120.0f;
    color->g = cos(21 * (res)) + sin(13 * (i + j)) * 120.0f;
    color->b = cos(28 * (res)) + sin(62 * (res)) * 120.0f;
}

void tile_color_function_what(map_t *map, sfColor *color, int i, int j)
{
    double res = (map->data.map_3d[i][j] + map->data.map_3d[i][j + 1]
        + map->data.map_3d[i + 1][j] + map->data.map_3d[i + 1][j + 1]);
    int test = (ABS((map->params.map.y / 2 - i))
        + ABS((map->params.map.x / 2 - j))) * 10;

    color->r = test - res * 2;
    color->g = test - res * 2;
    color->b = test - res * 2;
}
