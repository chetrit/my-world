/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options check_box init
*/

#include <stdlib.h>
#include "game.h"
#include "screens/init/check_box/options.h"

void options_check_box_create(scr_options_t *scr, game_objects_t *go)
{
    bool *is_checked = malloc(sizeof(int) * OPTIONS_CHECK_BOXES_NB);

    for (int i = 0; i < OPTIONS_CHECK_BOXES_NB; ++i) {
        is_checked[i] = false;
    }
    scr->check_boxes = (obj_check_boxes_t){
        (game_func *)OPTIONS_CHECK_BOXES_FUNCS,
        go->sprites + SPRITE_OFFSET,
        go->sprite_is_hidden + SPRITE_OFFSET,
        OPTIONS_CHECK_BOX_ANIMATION_FUNC_IDS,
        OPTIONS_CHECK_BOX_COLLISION_TYPE,
        go->sounds,
        go->sprite_rect + SPRITE_OFFSET,
        go->sprite_pos + SPRITE_OFFSET,
        go->sprite_size + SPRITE_OFFSET,
        is_checked,
        1,
        -1,
        OPTIONS_CHECK_BOXES_NB
    };
}
