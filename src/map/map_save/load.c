/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map load
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "game.h"
#include "my_utils.h"

static void map_load_fail(char *maps_path)
{
    if (maps_path == NULL) {
        my_putstr_fd("Failed to load map\n", 2);
    } else {
        my_putstr_fd("Failed to load map from ", 2);
        my_putstr_fd(maps_path, 2);
        my_putstr_fd("\n", 2);
    }
}

int map_load(map_save_t *map, char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1 || read(
        fd, &map->infos, sizeof(map_save_info_t)) != sizeof(map_save_info_t)) {
        map_load_fail(path);
        return (1);
    }
    map->map_3d = generate_map_3d(map->infos.size);
    for (int i = 0; i < map->infos.size.y; i++) {
        for (int j = 0; j < map->infos.size.x; j++) {
            if (read(fd, map->map_3d[i] + j, sizeof(float)) != sizeof(float)) {
                map_load_fail(path);
                return (1);
            }
        }
    }
    close(fd);
    my_putstr("map loaded\n");
    return (0);
}

map_save_t *load_all_maps_loop(
    DIR *folder, char maps_path[64], map_save_t *current)
{
    map_save_t *previous = NULL;
    char *map_path = NULL;

    for (struct dirent *dir_info = readdir(folder);
        dir_info != NULL; dir_info = readdir(folder)) {
        if (dir_info->d_name[0] == '.' || dir_info->d_type != DT_REG)
            continue;
        map_path = my_string_merge(maps_path, dir_info->d_name);
        previous = current;
        current = map_save_create(previous, map_path);
        previous->next = current;
        if (map_load(current, map_path) != 0)
            current = previous;
        my_putnbr_in_str(current->infos.size.x > 999 ?
            50 : current->infos.size.x, current->size_str[0]);
        my_putnbr_in_str(current->infos.size.y > 999 ?
            50 : current->infos.size.y, current->size_str[1]);
    }
    return (current);
}

static void load_all_maps_args(gm_t *gm, int ac, char *av[])
{
    map_save_t *previous = NULL;
    map_save_t *current = gm->maps;
    map_save_t *tmp = gm->maps->next;

    for (int i = 0; i < ac; ++i) {
        previous = current;
        current = map_save_create(previous, get_last_occ_slash(av[i]));
        previous->next = current;
        if (map_load(current, av[i]) != 0)
            current = previous;
        my_putnbr_in_str(current->infos.size.x > 999 ?
            50 : current->infos.size.x, current->size_str[0]);
        my_putnbr_in_str(current->infos.size.y > 999 ?
            50 : current->infos.size.y, current->size_str[1]);
    }
    current->next = tmp;
}

int load_all_maps(gm_t *gm, int ac, char *av[])
{
    DIR *folder = NULL;
    map_save_t *current = map_save_create(NULL, NULL);

    folder = opendir(gm->config.maps_path);
    if (current == NULL) {
        return (1);
    } else if (folder == NULL) {
        my_putstr_fd("maps load fail:\n    a folder named \"", 2);
        my_putstr_fd(gm->config.maps_path, 2);
        my_putstr_fd("\" is required to load maps\n", 2);
        return (1);
    }
    map_save_set_default_infos(current);
    gm->maps = current;
    current = load_all_maps_loop(folder, gm->config.maps_path, current);
    closedir(folder);
    gm->maps->prev = current;
    current->next = gm->maps;
    load_all_maps_args(gm, ac, av);
    return (0);
}
