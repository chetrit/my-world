/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map convert
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "game.h"
#include "my_utils.h"
#include "get_next_line.h"

static void map_convert_fail(char *maps_path)
{
    my_putstr_fd("Failed to convert map from ", 2);
    my_putstr_fd(maps_path, 2);
    my_putstr_fd("\n", 2);
}

static int map_save_convert_infos(map_save_t *map, char *line)
{
    map->infos = (map_save_info_t) {{0}, {0}, {50, 50}};
    if (line == NULL)
        return (1);
    for (int i = -1; *line != '\0' && *line != ':' && ++i < 62; ++line)
        map->infos.name[i] = *line;
    if (*line == '\0')
        return (1);
    if (*line++ != ':')
        for (; *line != '\0' && *line != ':'; ++line);
    for (int i = -1; *line != '\0' && *line != ':' && ++i < 62; ++line)
        map->infos.author[i] = *line;
    if (*line == '\0')
        return (1);
    if (*line++ != ':')
        for (; *line != '\0' && *line != ':'; ++line);
    line += *line == ':';
    map->infos.size.x = my_getnbr_mvptr(&line);
    line += *line == ':';
    map->infos.size.y = my_getnbr_mvptr(&line);
    return (map->infos.size.x == 0 || map->infos.size.y == 0);
}

static int map_convert_map_3d(map_save_t *map, int fd)
{
    char *line = NULL;
    float **map_3d = generate_map_3d(map->infos.size);

    for (int i = 0; i < map->infos.size.y; ++i) {
        line = get_next_line(fd);
        if (line == NULL)
            return (1);
        for (int j = 0; j < map->infos.size.x; ++j) {
            map_3d[i][j] = my_getnbr_mvptr(&line);
            line += *line == ':';
        }
    }
    map->map_3d = map_3d;
    return (0);
}

void convert_map(int ac, char *av[])
{
    map_save_t *map = NULL;
    int fd = -1;

    for (int i = 1; i < ac; ++i) {
        fd = open(av[i], O_RDONLY);
        if (fd == -1) {
            map_convert_fail(av[i]);
            continue;
        }
        map = map_save_create(NULL, my_string_merge("saves/maps/",
            get_last_occ_slash(av[i])));
        if (map_save_convert_infos(map, get_next_line(fd)) != 0
            || map_convert_map_3d(map, fd) != 0) {
            map_convert_fail(av[i]);
            continue;
        }
        my_putstr_fd("Map will be saved at ./saves/maps/\n", 2);
        map_save(map);
        close(fd);
    }
}
