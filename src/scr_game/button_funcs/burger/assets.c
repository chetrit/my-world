/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** burger menu
*/

#include "game.h"

void game_burger_assets_show_hide(gm_t *gm)
{
    for (int i = 0; i < 4; ++i) {
        gm->game.sprite_is_hidden[21 + i] = false;
    }
}

void game_burger_assets_house(gm_t *gm)
{
    game_burger_close_all(gm);
}

void game_burger_assets_tree(gm_t *gm)
{
    game_burger_close_all(gm);
}

void game_burger_assets_animal(gm_t *gm)
{
    game_burger_close_all(gm);
}

void game_burger_assets_human(gm_t *gm)
{
    game_burger_close_all(gm);
}
