/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map init header
*/

#ifndef MAP_INIT_H_
#define MAP_INIT_H_

#include "map/defs.h"

static const float HIGHLIGHT_CIRCLE_RADIUS = 5;

static const int TILE_COLOR_FUNC_NB = 7;

void tile_color_function_standard(map_t *map, sfColor *color, int i, int j);
void tile_color_function_texture(map_t *map, sfColor *color, int i, int j);
void tile_color_function_texture_slop(map_t *map, sfColor *color, int i, int j);
void tile_color_function_cossin(map_t *map, sfColor *color, int i, int j);
void tile_color_function_epi_soft(map_t *map, sfColor *color, int i, int j);
void tile_color_function_height(map_t *map, sfColor *color, int i, int j);
void tile_color_function_what(map_t *map, sfColor *color, int i, int j);

static tile_color_func TILE_COLOR_FUNCS[] = {
    &tile_color_function_standard,
    &tile_color_function_texture,
    &tile_color_function_texture_slop,
    &tile_color_function_cossin,
    &tile_color_function_epi_soft,
    &tile_color_function_height,
    &tile_color_function_what,
};

static const int TILE_HIGHLIGHT_FUNC_NB = 4;

void tile_highlight_function_fillcolor_standard(
    map_t *map, sfVector2i *mid, int range);
void tile_highlight_function_fillcolor_contour(
    map_t *map, sfVector2i *mid, int range);
void tile_highlight_function_outlinecolor_standard(
    map_t *map, sfVector2i *mid, int range);
void tile_highlight_function_outlinecolor_contour(
    map_t *map, sfVector2i *mid, int range);

static tile_highlight_func TILE_HIGHLIGHT_FUNCS[] = {
    &tile_highlight_function_fillcolor_standard,
    &tile_highlight_function_fillcolor_contour,
    &tile_highlight_function_outlinecolor_standard,
    &tile_highlight_function_outlinecolor_contour,
};

#endif /* !MAP_INIT_H_ */
