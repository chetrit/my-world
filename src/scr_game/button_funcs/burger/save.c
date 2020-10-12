/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** burger menu
*/

#include "game.h"

void game_burger_save_show_hide(gm_t *gm)
{
    for (int i = 0; i < 4; ++i) {
        gm->game.sprite_is_hidden[37 + i] = false;
    }
}

void game_burger_save_save(gm_t *gm)
{
    game_burger_close_all(gm);
    if (gm->maps->path == NULL) {
        gm->maps->path = my_string_merge(
            gm->config.maps_path, gm->maps->infos.name);
    }
    map_save(gm->maps);
}

void game_burger_save_save_as(gm_t *gm)
{
    game_burger_close_all(gm);
}

void game_burger_save_rename(gm_t *gm)
{
    game_burger_close_all(gm);
    buttons_reset(gm, &gm->game.buttons);
    buttons_animation(gm, &gm->map_selection.buttons);
    gm->current_screen = SCR_MAP_SELECTION;
}

void game_burger_save_no_idea(gm_t *gm)
{
    game_burger_close_all(gm);
}
