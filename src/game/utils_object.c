/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** utils object
*/

#include "game.h"
#include "utils/object.h"

void objs_add_function(gm_t *gm)
{
    gm->go.obj_sprite_funcs = OBJ_FUNCS;
    gm->go.obj_sprite_collision_funcs = OBJ_COLLISION_FUNCS;
}
