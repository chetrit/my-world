/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game button functions
*/

#include <stdlib.h>
#include "game.h"

void game_button_function_go_scr_home(gm_t *gm)
{
    buttons_reset(gm, &gm->game.buttons);
    buttons_animation(gm, &gm->home.buttons);
    gm->current_screen = SCR_HOME;
}

void game_button_function_random_gen(gm_t *gm)
{
    sfVector2i *map_size = &gm->game.map.params.map;

    for (int i = 0; i < 50; i++) {
        gm->game.map.data.map_3d[rand() % map_size->y]
            [rand() % map_size->x] = (float)(((rand() % 40) - 10)  / 10.0f);
    }
    for (int i = 0; i < 50; i++) {
        gm->game.map.data.map_3d[rand() % map_size->y]
            [rand() % map_size->x] = (float)(((rand() % 40) - 10)  / 10.0f);
    }
}
