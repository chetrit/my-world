/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** main loop
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include "game.h"
#include "my_utils.h"

/*
** PARSE ARGS: --config = ./.config || -c ./.config ?
** -> parse args to edit config file ??
*/
static const char DEFAULT_WINDOW_TITLE[] = "My World";
static const char DEFAULT_MAP_SAVE_PATH[] = "./saves/maps/";
static const char DEFAULT_CONFIG_PATH[] = "./.config";
static const char DEFAULT_SCREENSHOTS_PATH[] = "./saves/screenshots/";
static const char CONFIG_FILE_PATH[8] = ".config";

void config_file_load(gm_t *gm)
{
    mode_t mode = 0666;
    int fd = open(CONFIG_FILE_PATH, O_RDONLY | O_CREAT, mode);
    ssize_t read_value = 0;

    if (fd == -1) {
        my_putstr_fd("config: open failed\n", 2);
    } else {
        read_value = read(fd, &gm->config, sizeof(game_config_t));
        if (read_value != 0 && read_value != sizeof(game_config_t)) {
            my_putstr_fd(read_value > 0 ?
                "config: invalid config file\n" : "config: read failed\n", 2);
        }
        close(fd);
    }
}

void config_file_save(gm_t *gm)
{
    mode_t mode = 0666;
    int fd = open(CONFIG_FILE_PATH, O_WRONLY | O_CREAT, mode);
    ssize_t write_value = 0;

    if (fd == -1) {
        my_putstr_fd("config: open failed\n", 2);
    } else {
        write_value = write(fd, &gm->config, sizeof(game_config_t));
        if (write_value != sizeof(game_config_t)) {
            my_putstr_fd("config: write failed\n", 2);
        }
        close(fd);
    }
}

void update_obj_from_config(gm_t *gm)
{
    gm->options.check_boxes.is_checked[0] = !gm->config.is_music_on;
    gm->options.check_boxes.is_checked[1] = !gm->config.is_sound_on;
    gm->options.check_boxes.is_checked[2] = !gm->config.is_help_box;
    gm->options.check_boxes.is_checked[3] = gm->config.max_fps == 120;
}

void config_init(gm_t *gm)
{
    gm->config = (game_config_t) {
        {0}, {0}, {0}, {0}, {1920, 1080, 32},
        sfDefaultStyle, 60, false, true, true, true
    };
    my_strcpy(gm->config.window_title, DEFAULT_WINDOW_TITLE);
    my_strcpy(gm->config.config_path, DEFAULT_CONFIG_PATH);
    my_strcpy(gm->config.maps_path, DEFAULT_MAP_SAVE_PATH);
    my_strcpy(gm->config.screenshots_path, DEFAULT_SCREENSHOTS_PATH);
    config_file_load(gm);
}
