/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** object's animation utils
*/

#include "game.h"

void obj_sprite_none_update(
    UNUSED sfSprite *sprite, UNUSED sfIntRect rect, UNUSED int state)
{
    return;
}

void obj_sprite_rect_left_update(sfSprite *sprite, sfIntRect rect, int state)
{
    rect.left += rect.width * state;
    sfSprite_setTextureRect(sprite, rect);
}

void obj_sprite_rect_right_update(sfSprite *sprite, sfIntRect rect, int state)
{
    rect.left += rect.width * state;
    sfSprite_setTextureRect(sprite, rect);
}

void obj_sprite_zoom_on_hover(
    sfSprite *sprite, UNUSED sfIntRect rect, int state)
{
    if (state == 0) {
        sfSprite_setScale(sprite, (sfVector2f){1.0f, 1.0f});
    } else if (state == 1) {
        sfSprite_setScale(sprite, (sfVector2f){1.20f, 1.20f});
    } else {
        sfSprite_setScale(sprite, (sfVector2f){1.10f, 1.10f});
    }
}
