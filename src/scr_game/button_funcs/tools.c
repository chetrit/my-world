/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** tools button functions
*/

#include <stdlib.h>
#include "game.h"

void game_button_function_tools_increment(gm_t *gm)
{
    gm->game.tools.new_id = (gm->game.tools.new_id + 1) % gm->game.tools.nb;
}

void game_button_function_tools_decrement(gm_t *gm)
{
    if (gm->game.tools.new_id == 0) {
        gm->game.tools.new_id = gm->game.tools.nb - 1;
    } else {
        gm->game.tools.new_id -= 1;
    }
}

void game_button_function_call_tools(gm_t *gm)
{
    gm->game.tools.id = gm->game.tools.new_id;
    gm->game.tools.is_corner = gm->game.tools.tool_type[gm->game.tools.id];
}
