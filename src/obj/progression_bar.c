/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** progression bar
*/

#include <stdlib.h>
#include "game.h"

static void prog_bars_update_rect(
    UNUSED obj_prog_bars_t *prog_bars, UNUSED int id, UNUSED int state)
{
    return;
}

static void prog_bars_update_value(
    obj_prog_bars_t *prog_bars, sfVector2i const *mouse_pos)
{
    sfIntRect rect = sfSprite_getTextureRect(prog_bars->sprites[prog_bars->id]);
    int rect_diff = mouse_pos->x - prog_bars->pos[prog_bars->id].x
        + prog_bars->size[prog_bars->id].x;

    if (rect_diff >= prog_bars->size[prog_bars->id].x * 2) {
        rect.width = prog_bars->size[prog_bars->id].x * 2;
    } else if (rect_diff <= 0){
        rect.width = 0;
    } else {
        rect.width = rect_diff;
    }
    sfSprite_setTextureRect(prog_bars->sprites[prog_bars->id], rect);
}

static void prog_bars_update_colliding_id(
    obj_prog_bars_t *prog_bars, sfVector2i const *mouse_pos)
{
    int prog_bar_nb = prog_bars->nb;

    prog_bars->id = -1;
    for (int i = 0; i < prog_bar_nb; i++) {
        if (point_is_colliding_rect(
                prog_bars->pos + i, prog_bars->size + i, mouse_pos)) {
            prog_bars->id = i;
            break;
        }
    }
}

void prog_bars_animation(
    obj_prog_bars_t *prog_bars, sfVector2i const *mouse_pos)
{
    int old_prog_bar_id = prog_bars->id;

    prog_bars_update_colliding_id(prog_bars, mouse_pos);
    if (old_prog_bar_id != prog_bars->id) {
        if (old_prog_bar_id != -1) {
            prog_bars_update_rect(prog_bars, old_prog_bar_id, -1);
        }
        if (prog_bars->id != -1) {
            prog_bars_update_rect(prog_bars, prog_bars->id, 1);
        }
    }
}

void prog_bars_event(gm_t *gm, obj_prog_bars_t *prog_bars, sfEvent *event)
{
    if (event->type == sfEvtMouseMoved) {
        if (prog_bars->state == 0)
            prog_bars_animation(prog_bars, &gm->go.mouse.pos);
        else if (prog_bars->id != -1)
            prog_bars_update_value(prog_bars, &gm->go.mouse.pos);
    }
    if (event->type == sfEvtMouseButtonPressed && event->mouseButton.button
        == sfMouseLeft && prog_bars->id != -1) {
        prog_bars->state = 1;
        prog_bars_update_rect(prog_bars, prog_bars->id, 1);
        prog_bars_update_value(prog_bars, &gm->go.mouse.pos);
    }
    if (event->type == sfEvtMouseButtonReleased && event->mouseButton.button
        == sfMouseLeft && prog_bars->id != -1) {
        prog_bars->state = 0;
        prog_bars_update_rect(prog_bars, prog_bars->id, -1);
        (prog_bars->funcs[prog_bars->id])(gm);
    }
}
