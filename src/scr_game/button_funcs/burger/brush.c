/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** burger menu
*/

#include "game.h"

void game_burger_brush_show_hide(gm_t *gm)
{
    for (int i = 0; i < 4; ++i) {
        gm->game.sprite_is_hidden[33 + i] = false;
    }
}

void game_burger_brush_no_idea(gm_t *gm)
{
    game_burger_close_all(gm);
}
