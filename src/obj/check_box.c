/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** check_boxes object
*/

#include <stdlib.h>
#include "game.h"

void check_boxes_update_rect(
    gm_t *gm, obj_check_boxes_t *check_boxes, int id, int state)
{
    (gm->go.obj_sprite_funcs[check_boxes->hover_func_ids[id]])(
        check_boxes->sprites[id], check_boxes->rects[id], state);
    (gm->go.obj_sprite_funcs[check_boxes->hover_func_ids[
        id + check_boxes->nb]])(check_boxes->sprites[id + check_boxes->nb],
            check_boxes->rects[id + check_boxes->nb], state);
}

static void check_boxes_update_colliding_id(
    obj_check_boxes_t *check_boxes, sfVector2i const *mouse_pos)
{
    int check_box_nb = check_boxes->nb;

    check_boxes->id = -1;
    for (int i = 0; i < check_box_nb; i++) {
        if (point_is_colliding_rect(
            check_boxes->pos + i, check_boxes->size + i, mouse_pos)) {
            check_boxes->id = i;
            break;
        }
    }
}

void check_boxes_animation(gm_t *gm, obj_check_boxes_t *check_boxes)
{
    int old_check_box_id = check_boxes->id;

    check_boxes_update_colliding_id(check_boxes, &gm->go.mouse.pos);
    if (old_check_box_id != check_boxes->id) {
        if (old_check_box_id != -1) {
            check_boxes_update_rect(gm, check_boxes, old_check_box_id, 0);
        }
        if (check_boxes->id != -1) {
            check_boxes_update_rect(
                gm, check_boxes, check_boxes->id, check_boxes->state);
        }
    }
}

void check_boxes_event(gm_t *gm, obj_check_boxes_t *check_boxes, sfEvent *event)
{
    if (event->type == sfEvtMouseMoved) {
        check_boxes_animation(gm, check_boxes);
        return;
    }
    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft
        && check_boxes->id != -1 && check_boxes->state == 1) {
        check_boxes->state = 2;
        check_boxes_update_rect(gm, check_boxes, check_boxes->id, 2);
    }
    if (event->type == sfEvtMouseButtonReleased && event->mouseButton.button
        == sfMouseLeft && check_boxes->id != -1 && check_boxes->state == 2) {
        check_boxes->state = 1;
        check_boxes_update_rect(gm, check_boxes, check_boxes->id, 1);
        check_boxes->is_checked[check_boxes->id] =
            !check_boxes->is_checked[check_boxes->id];
        (check_boxes->funcs[check_boxes->id])(gm);
    }
}
