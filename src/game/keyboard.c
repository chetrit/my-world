/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** keyboard utils
*/

#include "game.h"
#include "keyboard.h"

void keyboard_init(gm_t *gm)
{
    gm->go.kb.funcs = KEYBOARD_FUNCS;
    for (int i = 0; i < sfKeyCount; ++i) {
        gm->go.kb.funcs_idx[i] = i;
        gm->go.kb.keys[i] = sfFalse;
    }
}
