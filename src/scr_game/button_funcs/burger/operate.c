/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** burger menu
*/

#include "game.h"

void game_burger_operate_show_hide(gm_t *gm)
{
    for (int i = 0; i < 4; ++i) {
        gm->game.sprite_is_hidden[29 + i] = false;
    }
}

void game_burger_operate_no_idea(gm_t *gm)
{
    game_burger_close_all(gm);
}
