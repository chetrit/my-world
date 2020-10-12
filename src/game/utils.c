/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game utils
*/

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

static int game_manager_create_views(gm_t *gm)
{
    home_screen_create(gm);
    options_screen_create(gm);
    map_selection_screen_create(gm);
    return (game_screen_create(gm));
}

static int game_manager_create_objects(gm_t *gm)
{
    gm->go.mouse = (mouse_t){.pos = {0, 0}, .delta_scroll = 0.0f};
    for (int i = 0; i < sfMouseButtonCount; ++i) {
        gm->go.mouse.buttons[i] = sfFalse;
    }
    return (
        fonts_create_all(gm) != 0
        || musics_create_all(gm) != 0
        || sounds_create_all(gm) != 0
        || sprites_create_all(gm) != 0
        || strings_create_all(gm) != 0
        || texts_create_all(gm) != 0
    );
}

int game_manager_create(gm_t *gm, int ac, char *av[])
{
    config_init(gm);
    gm->game_speed = 1.0f;
    gm->current_screen = SCR_HOME;
    gm->go.clock = sfClock_create();
    if (window_and_view_create(gm) != 0 || load_all_maps(gm, ac, av) != 0
        || game_manager_create_objects(gm) != 0 || gm->go.clock == NULL)
        return (1);
    objs_add_function(gm);
    keyboard_init(gm);
    return (game_manager_create_views(gm));
}

void game_manager_destroy(gm_t *gm)
{
    window_and_view_destroy(gm);
    sfClock_destroy(gm->go.clock);
    sfCircleShape_destroy(gm->game.map.events.highlighted_corner);
    sfConvexShape_destroy(gm->game.map.data.water_tile);
    map_save_destroy_all(gm);
    fonts_destroy_all(gm);
    musics_destroy_all(gm);
    sounds_destroy_all(gm);
    sprites_destroy_all(gm);
    strings_destroy_all(gm);
    texts_destroy_all(gm);
}
