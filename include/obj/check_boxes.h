/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** check_box object
*/

#ifndef OBJ_CHECK_BOXES_H_
#define OBJ_CHECK_BOXES_H_

typedef struct obj_check_boxes_s
{
    game_func *funcs;
    sfSprite **sprites;
    bool *sprite_is_hidden;
    int const *hover_func_ids;
    collision_type_e const *collision_types;
    sfSound **sounds;
    sfIntRect const *rects;
    sfVector2f *pos;
    sfVector2f *size;
    bool *is_checked;
    int state;
    int id;
    int nb;
} obj_check_boxes_t;

void check_boxes_event(gm_t *gm, obj_check_boxes_t *check_boxs, sfEvent *event);
void check_boxes_update_rect(
    gm_t *gm, obj_check_boxes_t *check_boxs, int id, int state);
void check_boxes_animation(gm_t *gm, obj_check_boxes_t *check_boxes);
void check_boxes_reset(obj_check_boxes_t *check_boxs);

#endif /* !OBJ_CHECK_BOXES_H_ */
