/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_selection text box
*/

#include <stdlib.h>
#include "game.h"

static const int MAP_SELECTION_TEXT_BOX_NB = 4;
static const int SPRITE_OFFSET = 30;
static const int TEXT_OFFSET = 1;
static const int STRING_OFFSET = 1;

void map_selection_text_boxes_create(
    scr_map_selection_t *scr, game_objects_t *go)
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
        MAP_SELECTION_TEXT_BOX_NB
    };
}
