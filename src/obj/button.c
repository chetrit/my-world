/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** buttons object
*/

#include <stdlib.h>
#include "game.h"

void buttons_update_rect(obj_buttons_t *buttons, int id, int state)
{
    sfIntRect rect = buttons->rects[id];

    rect.left += rect.width * state;
    sfSprite_setTextureRect(buttons->sprites[id], rect);
}

static void buttons_update_colliding_id(gm_t *gm, obj_buttons_t *buttons)
{
    int button_nb = buttons->nb;

    buttons->id = -1;
    for (int i = 0; i < button_nb; i++) {
        if ((gm->go.obj_sprite_collision_funcs[buttons->collision_types[
                buttons->id]])(buttons->pos + i, buttons->size + i,
                    &gm->go.mouse.pos)
            && buttons->sprite_is_hidden[i] == false) {
            buttons->id = i;
            break;
        }
    }
}

void buttons_animation(gm_t *gm, obj_buttons_t *buttons)
{
    int old_button_id = buttons->id;

    buttons_update_colliding_id(gm, buttons);
    if (old_button_id != buttons->id) {
        if (old_button_id != -1) {
            (gm->go.obj_sprite_funcs[buttons->hover_func_ids[old_button_id]])(
                buttons->sprites[old_button_id],
                buttons->rects[old_button_id], 0);
        }
        if (buttons->id != -1) {
            (gm->go.obj_sprite_funcs[buttons->hover_func_ids[buttons->id]])(
                buttons->sprites[buttons->id],
                buttons->rects[buttons->id], buttons->state);
        }
    }
}

void buttons_event(gm_t *gm, obj_buttons_t *buttons, sfEvent *event)
{
    if (event->type == sfEvtMouseMoved)
        buttons_animation(gm, buttons);
    if (event->type == sfEvtMouseButtonPressed && event->mouseButton.button
        == sfMouseLeft && buttons->id != -1 && buttons->state == 1) {
        buttons->state = 2;
        (gm->go.obj_sprite_funcs[buttons->hover_func_ids[buttons->id]])(
            buttons->sprites[buttons->id],
            buttons->rects[buttons->id], buttons->state);
    }
    if (event->type == sfEvtMouseButtonReleased && event->mouseButton.button
        == sfMouseLeft && buttons->id != -1 && buttons->state == 2) {
        buttons->state = 1;
        (gm->go.obj_sprite_funcs[buttons->hover_func_ids[buttons->id]])(
            buttons->sprites[buttons->id],
            buttons->rects[buttons->id], buttons->state);
        (buttons->funcs[buttons->id])(gm);
        if (gm->config.is_sound_on == true)
            sfSound_play(gm->go.sounds[0]);
    }
}
