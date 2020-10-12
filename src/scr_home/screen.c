/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** home screen
*/

#include "game.h"

static const int HOME_SPRITE_NB = 8;

static void home_event_update(gm_t *gm)
{
    while (sfRenderWindow_pollEvent(gm->window, &gm->go.event)) {
        event_common(gm);
        buttons_event(gm, &gm->home.buttons, &gm->go.event);
    }
}

static void home_display_update(gm_t *gm)
{
    sfRenderWindow_setView(gm->window, gm->go.ui_view);
    for (int i = 0; i < HOME_SPRITE_NB; i++) {
        sfRenderWindow_drawSprite(
            gm->window, gm->home.sprites[i], NULL);
    }
}

void scr_home(gm_t *gm)
{
    home_event_update(gm);
    home_display_update(gm);
}
