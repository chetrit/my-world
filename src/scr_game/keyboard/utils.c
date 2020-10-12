/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game event
*/

#include "game.h"

void game_keyboard_actions(gm_t *gm)
{
    double speed_mod = 5.0f * (gm->go.kb.keys[sfKeyLShift]
        || gm->go.kb.keys[sfKeyRShift] ? 3.0f : 1.0f);

    gm->game.map.params.speed.x = speed_mod
        * (gm->go.kb.keys[sfKeyRight] - gm->go.kb.keys[sfKeyLeft]);
    gm->game.map.params.speed.y = speed_mod
        * (gm->go.kb.keys[sfKeyDown] - gm->go.kb.keys[sfKeyUp]);
}

static void game_shortcut_execute(gm_t *gm, sfEvent *event)
{
    if (event->key.code == sfKeyR)
        map_navigation_reset(gm);
    if (event->key.code == sfKeyS)
        keyboard_map_save(gm);
}

void game_keyboard_actions_pressed(gm_t *gm, sfEvent *event)
{
    if (event->type != sfEvtKeyPressed || event->key.code == sfKeyUnknown)
        return;
    if (event->key.control == sfFalse) {
        if (gm->go.kb.funcs[gm->go.kb.funcs_idx[event->key.code]] != NULL)
            (*gm->go.kb.funcs[gm->go.kb.funcs_idx[event->key.code]])(gm);
    } else {
        game_shortcut_execute(gm, event);
    }
}
