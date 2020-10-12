/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** isometric map
*/

#include <stdlib.h>
#include <math.h>
#include "game.h"

sfVector2f project_iso_point(int x, int y, float z, map_t *map)
{
    sfVector2f point = {
        cos(map->params.map_horizontal_angle) * (x - y),
        sin(map->params.map_vertical_angle) * (x + y) - z
    };

    point.x = point.x * map->params.map_sampling + map->params.map_shift.x;
    point.y = point.y * map->params.map_sampling + map->params.map_shift.y;
    return (point);
}

sfVector2f **malloc_2d_map(int nb_rows, int nb_cols)
{
    sfVector2f **arr = malloc(sizeof(sfVector2f *) * nb_rows);

    if (arr == NULL)
        return (NULL);
    for (int i = 0; i < nb_rows; i++) {
        arr[i] = malloc(sizeof(sfVector2f) * (nb_cols + 1));
        if (arr[i] == NULL)
            return (NULL);
    }
    return (arr);
}

void map_iso_update(map_t *map)
{
    sfVector2f **map_iso = map->data.map_iso;

    map->params.lowest_point = 0.0f;
    for (int i = 0; i < map->params.map.y; i++) {
        for (int j = 0; j < map->params.map.x; j++) {
            map_iso[i][j] = project_iso_point(
                i, j, map->data.map_3d[i][j], map);
            if (map->params.lowest_point > map->data.map_3d[i][j]) {
                map->params.lowest_point = map->data.map_3d[i][j];
            }
        }
    }
}
