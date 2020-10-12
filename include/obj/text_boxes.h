/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** text boxes object
*/

#ifndef OBJ_TEXT_BOXES_H_
#define OBJ_TEXT_BOXES_H_

/*
** Looking for better var name:  last_char
** last_char is either '\0' or last_char replaced by a
**     "_" to indicate where the cursor is
*/

typedef struct obj_texts_s
{
    char **strings;
    bool const *is_num_only;
    int const *max_len;
    int *length;
    int position;
    char last_char;
} obj_texts_t;

typedef struct obj_text_boxes_s
{
    sfSprite **sprites;
    bool *sprite_is_hidden;
    sfText **texts;
    sfIntRect const *rect;
    sfVector2f *pos;
    sfVector2f *size;
    obj_texts_t pstrings;
    int triggered_id;
    int id;
    int nb;
} obj_text_boxes_t;

void text_boxes_event(gm_t *gm, obj_text_boxes_t *text_boxes, sfEvent *event);
void text_boxes_update_rect(obj_text_boxes_t *text_boxes, int id, int state);
void text_boxes_reset(obj_text_boxes_t *text_boxes);

typedef int (string_action)(obj_text_boxes_t *text_boxes);

int string_action_backspace(obj_text_boxes_t *text_boxes);
int string_action_delete(obj_text_boxes_t *text_boxes);
int string_action_left_arrow(obj_text_boxes_t *text_boxes);
int string_action_right_arrow(obj_text_boxes_t *text_boxes);
int text_boxes_string_add_char(obj_text_boxes_t *text_boxes, char evt_key);

#endif /* !OBJ_TEXT_BOXES_H_ */
