/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options text box
*/

#include <stdlib.h>
#include "game.h"

static const int OPTIONS_TEXT_BOX_NB = 1;
static const int SPRITE_OFFSET = 14;
static const int TEXT_OFFSET = 0;
static const int STRING_OFFSET = 0;

void options_text_boxes_create(scr_options_t *scr, game_objects_t *go)
{
    scr->text_boxes = (obj_text_boxes_t){
        go->sprites + SPRITE_OFFSET,
        go->sprite_is_hidden + SPRITE_OFFSET,
        go->texts + TEXT_OFFSET,
        go->sprite_rect + SPRITE_OFFSET,
        go->sprite_pos + SPRITE_OFFSET,
        go->sprite_size + SPRITE_OFFSET,
        (obj_texts_t){
            go->strings + STRING_OFFSET,
            go->string_is_num_only + STRING_OFFSET,
            go->string_max_length + STRING_OFFSET,
            go->string_length + STRING_OFFSET,
            0,
            '\0'
        },
        -1,
        -1,
        OPTIONS_TEXT_BOX_NB
    };
}
