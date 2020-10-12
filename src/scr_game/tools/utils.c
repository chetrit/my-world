/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** terraforming tools
*/

#include "game.h"

void tool_logic(gm_t *gm)
{
    if (gm->game.buttons.id == -1 && gm->game.tools.id != -1
        && gm->game.map.events.is_highlight) {
        (gm->game.tools.funcs[gm->game.tools.id])(gm);
    }
}
