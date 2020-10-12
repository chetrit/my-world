/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game screen
*/

#include "game.h"

static const int GAME_SPRITE_NB = 41;

static void game_event_update(gm_t *gm)
{
    while (sfRenderWindow_pollEvent(gm->window, &gm->go.event)) {
        if (gm->go.event.type == sfEvtMouseButtonReleased
            || (gm->go.event.type == sfEvtMouseButtonPressed
            && gm->game.buttons.id == -1))
            game_burger_close_all(gm);
        event_common(gm);
        buttons_event(gm, &gm->game.buttons, &gm->go.event);
        game_keyboard_actions_pressed(gm, &gm->go.event);
    }
}

static void game_logic_update(gm_t *gm)
{
    if (gm->game.animation.is_active == 1) {
        (gm->game.animation.funcs[gm->game.animation.id])(gm);
    }
    game_keyboard_actions(gm);
    game_move_map(gm);
    set_tiles(gm);
    bottom_computation(&gm->game.map);
    tool_logic(gm);
    if (gm->go.mouse.delta_scroll != 0.0f) {
        update_zoom(gm);
    }
    map_iso_update(&gm->game.map);
    tile_highlight_logic(gm);
}

static void game_display_update(gm_t *gm)
{
    sfRenderWindow_setView(gm->window, gm->go.ui_view);
    sfRenderWindow_drawSprite(gm->window, gm->game.sprites[0], NULL);
    sfRenderWindow_setView(gm->window, gm->go.map_view);
    draw_tiles(gm);
    bottom_draw(gm);
    if (gm->game.tools.is_corner == true)
        draw_highlighted_corner(gm);
    sfRenderWindow_setView(gm->window, gm->go.ui_view);
    for (int i = 1; i < GAME_SPRITE_NB; i++) {
        if (gm->game.sprite_is_hidden[i] == false)
            sfRenderWindow_drawSprite(gm->window, gm->game.sprites[i], NULL);
    }
    if (gm->config.is_help_box && gm->game.buttons.id > 0) {
        sfRenderWindow_drawSprite(
            gm->window, gm->game.help_boxes.sprites[0], NULL);
        for (int j = 0; j < 2; ++j)
            sfRenderWindow_drawText(gm->window, gm->game.help_boxes.texts[
                (gm->game.buttons.id - 1) * 2 + j], NULL);
        sfRenderWindow_drawSprite(gm->window, gm->go.sprites[77], NULL);
    }
}

void scr_game(gm_t *gm)
{
    game_event_update(gm);
    game_logic_update(gm);
    game_display_update(gm);
}
