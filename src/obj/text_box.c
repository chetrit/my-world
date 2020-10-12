/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** text box object
*/

#include <stdlib.h>
#include "game.h"

static const char TEXT_BOX_CHAR_CORRES[] =
    "abcdefghijklmnopqrstuvwxyz0123456789\x1b\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00""[];,.'/\\~=- \n\xff""\t\x00\x00\x00\x00\xfe+-*""/\x00\xfd\xfc\x00"
    "0123456789""\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";

static string_action *STRING_ACTIONS[] = {
    &string_action_backspace,
    &string_action_delete,
    &string_action_left_arrow,
    &string_action_right_arrow,
};

void text_boxes_update_rect(obj_text_boxes_t *text_boxes, int id, int state)
{
    sfIntRect rect = text_boxes->rect[id];

    rect.left += rect.width * state;
    sfSprite_setTextureRect(text_boxes->sprites[id], rect);
}

static void text_boxes_update_colliding_id(
    obj_text_boxes_t *text_boxes, sfVector2i *mouse_pos)
{
    int text_box_nb = text_boxes->nb;
    int old_id = text_boxes->id;

    text_boxes->id = -1;
    for (int i = 0; i < text_box_nb; i++) {
        if (point_is_colliding_rect(
                text_boxes->pos + i, text_boxes->size + i, mouse_pos)) {
            text_boxes->id = i;
            break;
        }
    }
    if (old_id != text_boxes->id && old_id != -1
        && old_id != text_boxes->triggered_id) {
        text_boxes_update_rect(text_boxes, old_id, 0);
    }
    if (text_boxes->id != -1 && text_boxes->id != text_boxes->triggered_id)
        text_boxes_update_rect(text_boxes, text_boxes->id, 1);
}

static void text_boxes_animation(obj_text_boxes_t *text_boxes)
{
    if (text_boxes->id != text_boxes->triggered_id) {
        text_boxes_update_rect(text_boxes, text_boxes->triggered_id, 0);
    }
    text_boxes->triggered_id = text_boxes->id;
    if (text_boxes->id != -1) {
        text_boxes_update_rect(text_boxes, text_boxes->id, 2);
        text_boxes->pstrings.position =
            text_boxes->pstrings.length[text_boxes->id];
    }
}

static int text_boxes_string_update(
    obj_text_boxes_t *text_boxes, sfEvent *event)
{
    char evt_key;

    if (event->type == sfEvtTextEntered
        && (event->text.unicode != 8)) {
        return (text_boxes_string_add_char(text_boxes, event->text.unicode));
    } else if (event->type == sfEvtKeyPressed) {
        evt_key = TEXT_BOX_CHAR_CORRES[event->key.code];
        if (evt_key <= -1 && evt_key >= -4)
            return ((STRING_ACTIONS[(-(int)evt_key) - 1])(text_boxes));
    }
    return (0);
}

void text_boxes_event(gm_t *gm, obj_text_boxes_t *text_boxes, sfEvent *event)
{
    if (event->type == sfEvtMouseMoved) {
        text_boxes_update_colliding_id(text_boxes, &gm->go.mouse.pos);
        return;
    }
    if (event->type == sfEvtMouseButtonReleased
        && ((sfMouseButtonEvent *)event)->button == sfMouseLeft) {
        text_boxes_animation(text_boxes);
        return;
    }
    if ((event->type == sfEvtTextEntered || event->type == sfEvtKeyPressed)
        && text_boxes->triggered_id != -1) {
        if (text_boxes_string_update(text_boxes, event) != 0
            && gm->config.is_sound_on == true) {
            sfSound_play(gm->go.sounds[SE_ERROR_3]);
        }
    }
}
