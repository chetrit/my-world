/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** text box string action
*/

#include "game.h"

int string_action_backspace(obj_text_boxes_t *text_boxes)
{
    char *string = text_boxes->pstrings.strings[text_boxes->triggered_id];
    int pos = text_boxes->pstrings.position;
    int length = text_boxes->pstrings.length[text_boxes->triggered_id];

    if (pos <= 0)
        return (1);
    if (pos != length) {
        text_boxes->pstrings.position--;
        for (int i = pos - 1; i < length; i++) {
            string[i] = string[i + 1];
        }
    } else {
        string[--text_boxes->pstrings.position] = '\0';
    }
    text_boxes->pstrings.length[text_boxes->triggered_id]--;
    sfText_setString(text_boxes->texts[text_boxes->triggered_id], string);
    return (0);
}

int string_action_delete(obj_text_boxes_t *text_boxes)
{
    char *string = text_boxes->pstrings.strings[text_boxes->triggered_id];
    int pos = text_boxes->pstrings.position;
    int length = text_boxes->pstrings.length[text_boxes->triggered_id];

    if (pos != length) {
        for (int i = pos; i < length; i++) {
            string[i] = string[i + 1];
        }
        text_boxes->pstrings.length[text_boxes->triggered_id]--;
        sfText_setString(text_boxes->texts[text_boxes->triggered_id], string);
        return (0);
    } else {
        return (1);
    }
}

int string_action_left_arrow(obj_text_boxes_t *text_boxes)
{
    if (text_boxes->pstrings.position > 0) {
        text_boxes->pstrings.position--;
        return (0);
    } else {
        return (1);
    }
}

int string_action_right_arrow(obj_text_boxes_t *text_boxes)
{
    if (text_boxes->pstrings.position
        < text_boxes->pstrings.length[text_boxes->triggered_id]) {
        text_boxes->pstrings.position++;
        return (0);
    } else {
        return (1);
    }
}

int text_boxes_string_add_char(obj_text_boxes_t *text_boxes, char evt_key)
{
    char *string = text_boxes->pstrings.strings[text_boxes->triggered_id];

    if (text_boxes->pstrings.length[text_boxes->triggered_id]
        < text_boxes->pstrings.max_len[text_boxes->triggered_id]
        && (text_boxes->pstrings.is_num_only[text_boxes->triggered_id] == false
        || (evt_key >= '0' && evt_key <= '9'))) {
        if (text_boxes->pstrings.position
            != text_boxes->pstrings.length[text_boxes->triggered_id]) {
            for (int i = text_boxes->pstrings.length[text_boxes->triggered_id];
                i > text_boxes->pstrings.position; i--) {
                string[i] = string[i - 1];
            }
        }
        string[text_boxes->pstrings.position++] = evt_key;
        text_boxes->pstrings.length[text_boxes->triggered_id]++;
        sfText_setString(text_boxes->texts[text_boxes->triggered_id], string);
        return (0);
    }
    return (1);
}
