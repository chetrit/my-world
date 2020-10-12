/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game's event
*/

#include "game.h"

static void mouse_infos_update(gm_t *gm)
{
    sfEvent *evt = &gm->go.event;
    sfVector2i vector = {0, 0};
    sfVector2f vf = {0.0f, 0.0f};

    if (evt->type == sfEvtMouseButtonPressed
        || evt->type == sfEvtMouseButtonReleased) {
        gm->go.mouse.buttons[evt->mouseButton.button]
            = evt->type == sfEvtMouseButtonPressed;
        vector = (sfVector2i){evt->mouseButton.x, evt->mouseButton.y};
    }
    if (evt->type == sfEvtMouseMoved)
        vector = (sfVector2i){evt->mouseMove.x, evt->mouseMove.y};
    if (evt->type == sfEvtMouseWheelScrolled) {
        vector = (sfVector2i){evt->mouseWheelScroll.x, evt->mouseWheelScroll.y};
        gm->go.mouse.delta_scroll = evt->mouseWheelScroll.delta;
    }
    if (vector.x == 0 && vector.y == 0)
        return;
    vf = sfRenderWindow_mapPixelToCoords(gm->window, vector, gm->go.ui_view);
    gm->go.mouse.pos = (sfVector2i){vf.x, vf.y};
}

static void keyboard_infos_update(gm_t *gm)
{
    if (gm->go.event.type == sfEvtKeyPressed) {
        gm->go.kb.keys[gm->go.event.key.code] = sfTrue;
    }
    if (gm->go.event.type == sfEvtKeyReleased) {
        gm->go.kb.keys[gm->go.event.key.code] = sfFalse;
    }
}

void event_common(gm_t *gm)
{
    if (gm->go.event.type == sfEvtClosed) {
        sfRenderWindow_close(gm->window);
    } else if (gm->go.event.type == sfEvtResized) {
        gm->config.vmode.width = gm->go.event.size.width;
        gm->config.vmode.height = gm->go.event.size.height;
        viewport_update(gm);
    } else {
        mouse_infos_update(gm);
        keyboard_infos_update(gm);
    }
}
