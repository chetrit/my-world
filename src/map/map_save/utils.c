/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map load
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "game.h"
#include "my_utils.h"

static const char DEFAULT_MAP_NAME[] = "New World";
static const char DEFAULT_MAP_AUTHOR[] = "Guest";

map_save_t *map_save_create(map_save_t *prev, char *path)
{
    map_save_t *map = malloc(sizeof(map_save_t));

    if (map == NULL) {
        return (NULL);
    }
    map->prev = prev;
    map->next = NULL;
    map->path = path == NULL ? NULL : my_strdup(path);
    map->has_been_load = false;
    return (map);
}

void map_save_set_default_infos(map_save_t *map)
{
    map->infos = (map_save_info_t) {
        {0}, {0}, {50, 50}
    };
    map->size_str[0][0] = '5';
    map->size_str[0][1] = '0';
    map->size_str[0][2] = '\0';
    map->size_str[0][3] = '\0';
    map->size_str[1][0] = '5';
    map->size_str[1][1] = '0';
    map->size_str[1][2] = '\0';
    map->size_str[1][3] = '\0';
    my_strcpy(map->infos.name, DEFAULT_MAP_NAME);
    my_strcpy(map->infos.author, DEFAULT_MAP_AUTHOR);
    map->map_3d = generate_map_3d(map->infos.size);
}
