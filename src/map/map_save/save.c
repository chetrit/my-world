/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map save
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "game.h"
#include "my_utils.h"

void map_save_destroy_all(gm_t *gm)
{
    map_save_t *map = gm->maps;

    if (map->prev != NULL)
        map->prev->next = NULL;
    for (; map->next != NULL;) {
        free(map->path);
        map_3d_destroy(map->map_3d, &map->infos.size);
        map = map->next;
        if (map->prev != NULL)
            free(map->prev);
    }
    free(map->path);
    map_3d_destroy(map->map_3d, &map->infos.size);
    free(map);
}

static void map_save_fail(char *maps_path)
{
    if (maps_path == NULL) {
        my_putstr_fd("Failed to save map\n", 2);
    } else {
        my_putstr_fd("Failed to save map from ", 2);
        my_putstr_fd(maps_path, 2);
        my_putstr_fd("\n", 2);
    }
}

void map_save(map_save_t *map)
{
    int fd = open(map->path, O_WRONLY | O_CREAT, 0666);

    if (fd == -1 || write(
        fd, &map->infos, sizeof(map_save_info_t)) != sizeof(map_save_info_t)) {
        map_save_fail(map->path);
        return;
    }
    for (int i = 0; i < map->infos.size.y; i++) {
        for (int j = 0; j < map->infos.size.x; j++) {
            if (write(fd, map->map_3d[i] + j, sizeof(float)) != sizeof(float)) {
                map_save_fail(map->path);
                return;
            }
        }
    }
    close(fd);
    my_putstr("Map saved\n");
}

void map_save_all(gm_t *gm)
{
    map_save_t *current = gm->maps;

    current->prev->next = NULL;
    for (; current != NULL; current = current->next) {
        if (current->path == NULL)
            current->path = my_string_merge(
                gm->config.maps_path, current->infos.name);
        if (current->has_been_load == true)
            map_save(current);
    }
}
