/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_selection screen
*/

#include "game.h"

static const int MAP_SELECTION_SPRITE_NB = 12;

static void map_selection_event_update(gm_t *gm)
{
    while (sfRenderWindow_pollEvent(gm->window, &gm->go.event)) {
        event_common(gm);
        buttons_event(gm, &gm->map_selection.buttons, &gm->go.event);
        text_boxes_event(
            gm, &gm->map_selection.text_boxes, &gm->go.event);
        if (gm->go.event.type == sfEvtKeyPressed
            && gm->go.event.key.code == sfKeyN
            && gm->go.event.key.control == sfTrue)
            map_selection_map_create(gm);
    }
}

static void map_selection_display_update(gm_t *gm)
{
    sfRenderWindow_setView(gm->window, gm->go.ui_view);
    for (int i = 0; i < MAP_SELECTION_SPRITE_NB; i++) {
        sfRenderWindow_drawSprite(
            gm->window, gm->map_selection.sprites[i], NULL);
    }
    for (int i = 0; i < 4; ++i) {
        sfRenderWindow_drawText(
            gm->window, gm->map_selection.text_boxes.texts[i], NULL);
    }
}

void scr_map_selection(gm_t *gm)
{
    map_selection_event_update(gm);
    map_selection_display_update(gm);
}
