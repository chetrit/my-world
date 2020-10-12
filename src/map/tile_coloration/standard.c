/*
** EPITECH PROJECT, 2020
** tiles
** File description:
** epileptic coloration for tiles
*/

#include <stdlib.h>
#include <math.h>
#include "game.h"

static const int STD_COLOR_NB = 4;

static const sfColor STD_COLORS[] = {
    {242, 209, 107, 255},
    {113, 137, 44, 255},
    {150, 159, 178, 255},
    {238, 233, 233, 255},
};

static const float STD_COLOR_ASSOS[] = {
    -100.0f,
    -2.5f,
    2.5f,
    7.5f,
    100.0f
};

static const float STD_SLOPE_ASSOS[] = {
    -1.0f,
    2.5f,
    5.0f,
    7.5f,
    10.0f,
    12.5f,
    15.0f,
    17.5f,
};

void tile_color_function_standard(map_t *map, sfColor *color, int i, int j)
{
    float min = MIN(map->data.map_3d[i][j], (MIN(map->data.map_3d[i + 1][j + 1],
        (MIN(map->data.map_3d[i + 1][j], map->data.map_3d[i][j + 1])))));
    float max = MAX(map->data.map_3d[i][j], (MAX(map->data.map_3d[i + 1][j + 1],
        (MAX(map->data.map_3d[i + 1][j], map->data.map_3d[i][j + 1])))));
    float mid = (min + max) / 2.0f;

    for (int index = 0; index < STD_COLOR_NB; ++index) {
        if (mid > STD_COLOR_ASSOS[index]
            && mid <= STD_COLOR_ASSOS[index + 1]) {
            *color = STD_COLORS[index];
            color->r = MIN(color->r + ABS(mid) * 10.0, 255);
            color->g = MIN(color->g + ABS(mid) * 10.0, 255);
            color->b = MIN(color->b + ABS(mid) * 10.0, 255);
            break;
        }
    }
}

void tile_color_function_texture(map_t *map, sfColor *color, int i, int j)
{
    float min = MIN(map->data.map_3d[i][j], (MIN(map->data.map_3d[i + 1][j + 1],
        (MIN(map->data.map_3d[i + 1][j], map->data.map_3d[i][j + 1])))));
    float max = MAX(map->data.map_3d[i][j], (MAX(map->data.map_3d[i + 1][j + 1],
        (MAX(map->data.map_3d[i + 1][j], map->data.map_3d[i][j + 1])))));
    float mid = (min + max) / 2.0f;
    sfIntRect rect = map->params.rect;

    for (int index = 0; index < STD_COLOR_NB; ++index) {
        if (mid > STD_COLOR_ASSOS[index]
            && mid <= STD_COLOR_ASSOS[index + 1]) {
            *color = (sfColor){255, 255, 255, 255};
            rect.left += 80 * index;
            sfConvexShape_setTextureRect(
                map->data.tiles[i * (map->params.map.x - 1) + j], rect);
            break;
        }
    }
}

void tile_color_function_texture_slop(map_t *map, sfColor *color, int i, int j)
{
    float min = MIN(map->data.map_3d[i][j], (MIN(map->data.map_3d[i + 1][j + 1],
        (MIN(map->data.map_3d[i + 1][j], map->data.map_3d[i][j + 1])))));
    float max = MAX(map->data.map_3d[i][j], (MAX(map->data.map_3d[i + 1][j + 1],
        (MAX(map->data.map_3d[i + 1][j], map->data.map_3d[i][j + 1])))));
    float mid = max - min;
    sfIntRect rect = map->params.rect;

    for (int index = 0; index < 7; ++index) {
        if (mid > STD_SLOPE_ASSOS[index]
            && mid <= STD_SLOPE_ASSOS[index + 1]) {
            *color = (sfColor){255, 255, 255, 255};
            rect.left += 80 * index;
            sfConvexShape_setTextureRect(
                map->data.tiles[i * (map->params.map.x - 1) + j], rect);
            break;
        }
    }
}
