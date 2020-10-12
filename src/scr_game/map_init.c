/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map initialisation
*/

#include <stdlib.h>
#include <unistd.h>
#include "game.h"
#include "map/consts.h"

static const sfIntRect EMPTY_RECT = {0, 0, 0, 0};

sfConvexShape **game_map_bottom_shapes_init(int length, sfTexture *texture)
{
    sfConvexShape **shapes = malloc(sizeof(sfConvexShape *) * (length));

    for (int i = 0; i < length; i++) {
        shapes[i] = sfConvexShape_create();
        if (shapes[i] == NULL)
            return (NULL);
        sfConvexShape_setOrigin(shapes[i],
            (sfVector2f){SCREEN_SIZE.x / 2.0f, SCREEN_SIZE.y / 2.0f});
        sfConvexShape_setPosition(shapes[i],
            (sfVector2f){SCREEN_SIZE.x / 2.0f, SCREEN_SIZE.y / 2.0f});
        sfConvexShape_setPointCount(shapes[i], 4);
        sfConvexShape_setFillColor(shapes[i], BOTTOM_COLOR);
        sfConvexShape_setTexture(shapes[i], texture, sfTrue);
        sfConvexShape_setTextureRect(shapes[i], EMPTY_RECT);
    }
    return (shapes);
}

int game_map_init_bottom(map_t *map, sfTexture *texture)
{
    map->data.bottom.left
        = game_map_bottom_shapes_init(map->params.map.y - 1, texture);
    map->data.bottom.right
        = game_map_bottom_shapes_init(map->params.map.x - 1, texture);
    bottom_fix_point_init_right(map);
    bottom_fix_point_init_left(map);
    bottom_computation(map);
    return (0);
}

int game_map_init_tiles(map_t *map, sfTexture *texture, int nb_tiles)
{
    map->data.tiles = malloc(sizeof(sfConvexShape *) * nb_tiles);
    if (map->data.tiles == NULL)
        return (1);
    for (int i = 0; i < map->params.map_nb_tiles; i++) {
        map->data.tiles[i] = sfConvexShape_create();
        if (map->data.tiles[i] == NULL)
            return (1);
        sfConvexShape_setFillColor(map->data.tiles[i], TILE_COLOR);
        sfConvexShape_setOutlineThickness(
            map->data.tiles[i], TILE_OUTLINE_THICKNESS);
        sfConvexShape_setOutlineColor(map->data.tiles[i], TILE_OUTLINE_COLOR);
        sfConvexShape_setOrigin(map->data.tiles[i],
            (sfVector2f){SCREEN_SIZE.x / 2.0f, SCREEN_SIZE.y / 2.0f});
        sfConvexShape_setPosition(map->data.tiles[i],
            (sfVector2f){SCREEN_SIZE.x / 2.0f, SCREEN_SIZE.y / 2.0f});
        sfConvexShape_setPointCount(map->data.tiles[i], 4);
        sfConvexShape_setTexture(map->data.tiles[i], texture, sfTrue);
        sfConvexShape_setTextureRect(map->data.tiles[i], EMPTY_RECT);
    }
    return (0);
}

void game_map_destroy(map_t *map)
{
    for (int i = 0; i < map->params.map_nb_tiles; ++i) {
        sfConvexShape_destroy(map->data.tiles[i]);
    }
    for (int i = 0; i < map->params.map.y - 1; ++i) {
        free(map->data.map_iso[i]);
        sfConvexShape_destroy(map->data.bottom.left[i]);
    }
    for (int j = 0; j < map->params.map.x - 1; ++j) {
        sfConvexShape_destroy(map->data.bottom.right[j]);
    }
    free(map->data.map_iso[map->params.map.y - 1]);
    free(map->data.map_iso);
}

int game_map_init(gm_t *gm, map_save_t *map_save)
{
    map_t *map = &gm->game.map;

    gm->game.map.params.map = map_save->infos.size;
    gm->game.map.data.map_3d = map_save->map_3d;
    map->data.map_iso = malloc_2d_map(map->params.map.y, map->params.map.x);
    if (map->data.map_iso == NULL)
        return (1);
    map->params.map_nb_tiles =
        (map->params.map.x - 1) * (map->params.map.y - 1);
    map_iso_update(map);
    water_tile_set_point(map);
    return (game_map_init_bottom(map, gm->go.texture)
        || game_map_init_tiles(map, gm->go.texture, map->params.map_nb_tiles));
}
