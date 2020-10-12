/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** burger menu utils
*/

#include "game.h"

void game_burger_close_all(gm_t *gm)
{
    for (int i = 0; i < 20; i += 4) {
        if (gm->game.sprite_is_hidden[21 + i] == true) {
            continue;
        }
        for (int j = 0; j < 4; ++j) {
            gm->game.sprite_is_hidden[21 + i + j] = true;
        }
    }
}
