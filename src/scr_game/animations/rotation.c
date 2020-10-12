/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** rotation animation
*/

#include <stdlib.h>
#include "game.h"

/*void game_animation_rotate(gm_t *gm)
{
    static int counter = -1;
    static int pos = 0;
    static int layer = 0;
    int tmp = 0;

    counter = (counter + 1) % 1;
    if (counter == 0) {
        if (layer * 2 + 1 >= gm->game.map.params.map.x) {
            gm->game.animation.is_active = 0;
            layer = 0;
            pos = 0;
            counter = -1;
        } else if (pos >= gm->game.map.params.map.x - (layer * 2 + 1)) {
            layer += 1;
            pos = 0;
        } else {
            tmp = gm->game.map.data.map_3d[layer][layer + pos];
            gm->game.map.data.map_3d[layer][layer + pos]
                = gm->game.map.data.map_3d
                    [gm->game.map.params.map.y - 1 - layer - pos][layer];
            gm->game.map.data.map_3d
                [gm->game.map.params.map.x - 1 - layer - pos][layer]
                = gm->game.map.data.map_3d
                    [gm->game.map.params.map.y - 1 - layer]
                    [gm->game.map.params.map.x - 1 - layer - pos];
            gm->game.map.data.map_3d
                [gm->game.map.params.map.y - 1 - layer]
                [gm->game.map.params.map.x - 1 - layer - pos]
                = gm->game.map.data.map_3d[layer + pos]
                    [gm->game.map.params.map.x - 1 - layer];
            gm->game.map.data.map_3d[layer + pos]
                [gm->game.map.params.map.x - 1 - layer] += tmp;
            pos += 1;
        }
    }
}*/

static void update_values(map_t *map, int *pos, int layer, float value)
{
    static int step = -1;

    step = (step + 1) % 4;
    switch (step) {
    case 0:
        map->data.map_3d[layer][layer + *pos] -= value;
        break;
    case 1:
        map->data.map_3d[map->params.map.x - 1 - layer - *pos][layer] -= value;
        break;
    case 2:
        map->data.map_3d[map->params.map.y - 1 - layer]
            [map->params.map.x - 1 - layer - *pos] -= value;
        break;
    case 3:
        map->data.map_3d[layer + *pos][map->params.map.x - 1 - layer] -= value;
        *pos += 1;
    }
}

static void animation_rotate(gm_t *gm, float value)
{
    static int counter = -1;
    static int pos = 0;
    static int layer = 0;

    counter = (counter + 1) % 1;
    for (int i = 0; i < 4; i += 1) {
        if (layer * 2 + 1 >= gm->game.map.params.map.x) {
            gm->game.animation.is_active = 0;
            layer = 0;
            pos = 0;
            counter = -1;
        } else if (pos >= gm->game.map.params.map.x - (layer * 2 + 1)) {
            layer += 1;
            pos = 0;
        } else {
            update_values(&gm->game.map, &pos, layer, value);
        }
    }
}

void game_animation_rotate_dig_of_1(gm_t *gm)
{
    animation_rotate(gm, -1.0f);
}

void game_animation_rotate_build_of_1(gm_t *gm)
{
    animation_rotate(gm, 1.0f);
}
