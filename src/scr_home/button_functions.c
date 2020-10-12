/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** home button functions
*/

#include "game.h"

void home_button_function_go_scr_map_selection(gm_t *gm)
{
    buttons_reset(gm, &gm->home.buttons);
    buttons_animation(gm, &gm->map_selection.buttons);
    gm->current_screen = SCR_MAP_SELECTION;
}

void home_button_function_go_scr_options(gm_t *gm)
{
    if (gm->config.is_music_on) {
        sfMusic_stop(gm->go.musics[1]);
        sfMusic_play(gm->go.musics[2]);
    }
    buttons_reset(gm, &gm->home.buttons);
    buttons_animation(gm, &gm->options.buttons);
    gm->current_screen = SCR_OPTIONS;
}

void home_button_function_quit_game(gm_t *gm)
{
    gm->current_screen = SCR_CLOSE_GAME;
}
