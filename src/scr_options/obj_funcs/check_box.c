/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options check_box functions
*/

#include "game.h"

void options_check_boxes_function_sound_on_off(gm_t *gm)
{
    gm->config.is_sound_on = !gm->config.is_sound_on;
}

void options_check_boxes_function_music_on_off(gm_t *gm)
{
    if (gm->config.is_music_on == true) {
        sfMusic_stop(gm->go.musics[2]);
        gm->config.is_music_on = false;
    } else {
        sfMusic_play(gm->go.musics[2]);
        gm->config.is_music_on = true;
    }
}

void options_check_boxes_function_help_box_on_off(gm_t *gm)
{
    gm->config.is_help_box = !gm->config.is_help_box;
}

void options_check_boxes_function_change_fps(gm_t *gm)
{
    if (gm->config.max_fps == 60)
        gm->config.max_fps = 120;
    else
        gm->config.max_fps = 60;
    sfRenderWindow_setFramerateLimit(gm->window, gm->config.max_fps);
}
