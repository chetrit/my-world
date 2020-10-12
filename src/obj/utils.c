/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** object's utils
*/

#include "game.h"

int point_is_colliding_rect(
    sfVector2f const *pos, sfVector2f const *size, sfVector2i const *mouse_pos)
{
    return (
        mouse_pos->x < pos->x - size->x
        || mouse_pos->y < pos->y - size->y
        || mouse_pos->x > pos->x + size->x
        || mouse_pos->y > pos->y + size->y
        ? 0 : 1
    );
}

int point_is_colliding_rect_left_up(
    sfVector2f const *pos, sfVector2f const *size, sfVector2i const *mouse_pos)
{
    return (
        mouse_pos->x < pos->x
        || mouse_pos->y < pos->y
        || mouse_pos->x > pos->x + (size->x * 2.0f)
        || mouse_pos->y > pos->y + (size->y * 2.0f)
        ? 0 : 1
    );
}

int point_is_colliding_circle(
    sfVector2f const *pos, sfVector2f const *size, sfVector2f const *mouse_pos)
{
    return (
        ABS(pos->x - mouse_pos->x) <= size->x
        && ABS(pos->y - mouse_pos->y) <= size->y
    );
}
