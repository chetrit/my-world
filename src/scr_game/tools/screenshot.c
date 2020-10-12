/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** screenshot
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

#include <SFML/Graphics.h>

static const char SCREENSHOT_PATH[] = "saves/screenshots/";

static int count_nb_file_matching(char *name)
{
    DIR *folder = NULL;
    int count = 0;

    folder = opendir(SCREENSHOT_PATH);
    if (folder == NULL) {
        my_putstr_fd("Screenshot save fail:\n    a folder named \"", 2);
        my_putstr_fd(SCREENSHOT_PATH, 2);
        my_putstr_fd("\" is required to load maps\n", 2);
        return (-1);
    }
    for (struct dirent *dir_info = readdir(folder);
        dir_info != NULL; dir_info = readdir(folder)) {
        if (my_strncmp(name, dir_info->d_name, my_strlen(name)) == 0) {
            ++count;
        }
    }
    return (count);
}

static void screen_make_path(gm_t *gm, char *path, int nb)
{
    my_strcpy(path, SCREENSHOT_PATH);
    my_strcat(path, gm->maps->infos.name);
    my_strcat(path, "_");
    my_putnbr_in_end_str(nb, path);
    my_strcat(path, ".png");
}

void take_screenshot(gm_t *gm)
{
    sfImage *screenshot = NULL;
    sfTexture *texture = sfTexture_create(SCREEN_SIZE.x, SCREEN_SIZE.y);
    int nb = count_nb_file_matching(gm->maps->infos.name);
    char *path = malloc(
        sizeof(char) * (30 + my_strlen(gm->maps->infos.name)));

    if (nb == -1 || path == NULL)
        return;
    screen_make_path(gm, path, nb);
    sfRenderWindow_setView(gm->window, gm->go.ui_view);
    draw_tiles(gm);
    bottom_draw(gm);
    sfTexture_updateFromRenderWindow(texture, gm->window, 0, 0);
    screenshot = sfTexture_copyToImage(texture);
    if (screenshot == NULL)
        return;
    sfImage_saveToFile(screenshot, path);
    sfImage_destroy(screenshot);
    free(path);
}
