/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** reset functions
*/

#include "game.h"

void buttons_reset(gm_t *gm, obj_buttons_t *buttons)
{
    if (buttons->id != -1) {
        (gm->go.obj_sprite_funcs[buttons->hover_func_ids[buttons->id]])(
            buttons->sprites[buttons->id],
            buttons->rects[buttons->id], 0);
    }
    buttons->id = -1;
}

void text_boxes_reset(obj_text_boxes_t *text_boxes)
{
    if (text_boxes->triggered_id != -1)
        text_boxes_update_rect(text_boxes, text_boxes->triggered_id, 0);
    text_boxes->id = -1;
    text_boxes->triggered_id = -1;
}
