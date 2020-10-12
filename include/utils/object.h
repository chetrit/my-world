/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** utils object header
*/

#ifndef UTILS_OBJECT_H_
#define UTILS_OBJECT_H_

void obj_sprite_zoom_on_hover(sfSprite *sprite, sfIntRect rect, int state);
void obj_sprite_rect_right_update(sfSprite *sprite, sfIntRect rect, int state);
void obj_sprite_rect_left_update(sfSprite *sprite, sfIntRect rect, int state);
void obj_sprite_none_update(sfSprite *sprite, sfIntRect rect, int state);
void obj_sprite_rotate(sfSprite *sprite, sfIntRect rect, int state);

static obj_sprite_func OBJ_FUNCS[] = {
    &obj_sprite_rect_left_update,
    &obj_sprite_zoom_on_hover,
    &obj_sprite_rect_right_update,
    &obj_sprite_none_update,
};

int point_is_colliding_rect_left_up(
    sfVector2f const *pos, sfVector2f const *size, sfVector2i const *mouse_pos);
int point_is_colliding_rect(
    sfVector2f const *pos, sfVector2f const *size, sfVector2i const *mouse_pos);
int point_is_colliding_circle(
    sfVector2f const *pos, sfVector2f const *size, sfVector2i const *mouse_pos);

static sprite_collision_func OBJ_COLLISION_FUNCS[] = {
    &point_is_colliding_rect,
    &point_is_colliding_rect,
    &point_is_colliding_circle,
};

#endif /* !UTILS_OBJECT_H_ */
