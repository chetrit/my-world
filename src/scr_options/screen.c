/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options screen
*/

#include "game.h"

static const int OPTIONS_SPRITE_NB = 9;
static const int OPTIONS_TEXT_BOXES_NB = 1;

static void options_event_update(gm_t *gm)
{
    while (sfRenderWindow_pollEvent(gm->window, &gm->go.event)) {
        event_common(gm);
        prog_bars_event(gm, &gm->options.prog_bars, &gm->go.event);
        if (gm->options.prog_bars.id == -1) {
            buttons_event(gm, &gm->options.buttons, &gm->go.event);
            check_boxes_event(
                gm, &gm->options.check_boxes, &gm->go.event);
            text_boxes_event(
                gm, &gm->options.text_boxes, &gm->go.event);
        }
    }
}

static void options_display_update(gm_t *gm)
{
    sfRenderWindow_setView(gm->window, gm->go.ui_view);
    for (int i = 0; i < OPTIONS_SPRITE_NB; ++i) {
        sfRenderWindow_drawSprite(gm->window, gm->options.sprites[i], NULL);
    }
    for (int i = 0; i < gm->options.check_boxes.nb; ++i) {
        sfRenderWindow_drawSprite(
            gm->window, gm->options.check_boxes.sprites[i], NULL);
        if (gm->options.check_boxes.is_checked[i] == 1)
            sfRenderWindow_drawSprite(gm->window,
                gm->options.check_boxes.sprites[i + gm->options.check_boxes.nb],
                NULL);
    }
    for (int i = 0; i < OPTIONS_TEXT_BOXES_NB; i++) {
        sfRenderWindow_drawText(
            gm->window, gm->options.text_boxes.texts[i], NULL);
    }
}

void scr_options(gm_t *gm)
{
    options_event_update(gm);
    options_display_update(gm);
}
