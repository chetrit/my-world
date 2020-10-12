/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** 3d map
*/

#include <stdlib.h>
#include "game.h"

void map_3d_destroy(float **map_3d, const sfVector2i *size)
{
    for (int i = 0; i < size->y; ++i) {
        free(map_3d[i]);
    }
    free(map_3d);
}

int map_3d_realloc(
    float ***map_3d, const sfVector2i *size, const sfVector2i *new_size)
{
    float **new_map = malloc(sizeof(float *) * new_size->y);
    float **map = *map_3d;

    if (new_map == NULL)
        return (1);
    for (int i = 0; i < new_size->y; ++i) {
        new_map[i] = malloc(sizeof(float) * new_size->x);
        if (new_map[i] == NULL)
            return (1);
        for (int j = 0; j < new_size->x; ++j) {
            new_map[i][j] = i < size->y && j < size->x ? map[i][j] : 0.0f;
        }
    }
    map_3d_destroy(map, size);
    *map_3d = new_map;
    return (0);
}

float **generate_map_3d(sfVector2i dim)
{
    float **arr = malloc(sizeof(float *) * dim.y);

    if (arr == NULL)
        return (NULL);
    for (int i = 0; i < dim.y; i++) {
        arr[i] = malloc(sizeof(float) * dim.x);
        if (arr[i] == NULL)
            return (NULL);
        for (int j = 0; j < dim.x; j++) {
            arr[i][j] = 0;
        }
    }
    return (arr);
}
