/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game help box init
*/

#include <stdlib.h>
#include "game.h"

static const int SPRITE_OFFSET = 76;
static const int TEXT_OFFSET = 5;
static const int GAME_HELP_BOX_NB = 32;

static const int BUTTON_ID_CORRES[] = {
    -1,
};

void game_help_box_create(scr_game_t *scr, game_objects_t *go)
{
    scr->help_boxes = (obj_help_boxes_t){
        go->sprites + SPRITE_OFFSET,
        go->sprite_is_hidden + SPRITE_OFFSET,
        go->texts + TEXT_OFFSET,
        BUTTON_ID_CORRES,
        GAME_HELP_BOX_NB,
    };
}
