/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** burger menu
*/

#include "game.h"

void game_burger_paint_show_hide(gm_t *gm)
{
    for (int i = 0; i < 4; ++i) {
        gm->game.sprite_is_hidden[25 + i] = false;
    }
}

void game_burger_paint_rock(gm_t *gm)
{
    game_burger_close_all(gm);
}

void game_burger_paint_plain(gm_t *gm)
{
    game_burger_close_all(gm);
}

void game_burger_paint_dirt(gm_t *gm)
{
    game_burger_close_all(gm);
}

void game_burger_paint_sand(gm_t *gm)
{
    game_burger_close_all(gm);
}
