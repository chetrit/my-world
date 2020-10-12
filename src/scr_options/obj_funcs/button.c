/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options button functions
*/

#include "game.h"

void options_button_function_go_scr_home(gm_t *gm)
{
    if (gm->config.is_music_on) {
        sfMusic_stop(gm->go.musics[2]);
        sfMusic_play(gm->go.musics[1]);
    }
    buttons_reset(gm, &gm->options.buttons);
    gm->options.prog_bars.id = -1;
    text_boxes_reset(&gm->options.text_boxes);
    buttons_animation(gm, &gm->home.buttons);
    gm->current_screen = SCR_HOME;
}
