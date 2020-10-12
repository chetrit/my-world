/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** brush tool
*/

#include <stdlib.h>
#include "game.h"

static const double BUILD_LIMIT = 15.96f;

void game_tool_brush_dig_or_mountain_add(scr_game_t *game, float value)
{
    float **map_3d = game->map.data.map_3d;
    sfVector2i *index = &game->map.events.pos_highlighted_item;

    for (int i = index->y - game->tools.brush_size - 1;
        i < index->y + game->tools.brush_size + 1; i++) {
        for (int j = index->x - game->tools.brush_size - 1;
            j < index->x + game->tools.brush_size +1; j++) {
            if (i >= 0 && i < game->map.params.map.y
                && j >= 0 && j < game->map.params.map.x
                && map_3d[i][j] * (value >= 0 ? 1 : -1) < BUILD_LIMIT) {
                map_3d[i][j] += value;
            }
        }
    }
}

void game_tool_brush_dig_or_mountain_replace(scr_game_t *game, float value)
{
    float **map_3d = game->map.data.map_3d;
    sfVector2i *index = &game->map.events.pos_highlighted_item;

    for (int i = index->y - game->tools.brush_size - 1;
        i < index->y + game->tools.brush_size; i++) {
        for (int j = index->x - game->tools.brush_size - 1;
            j < index->x + game->tools.brush_size; j++) {
            if (i >= 0 && i < game->map.params.map.y
                && j >= 0 && j < game->map.params.map.x) {
                map_3d[i][j] = value;
            }
        }
    }
}
