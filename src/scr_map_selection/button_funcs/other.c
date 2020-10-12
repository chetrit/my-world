/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_selection button functions
*/

#include <stdlib.h>
#include "game.h"
#include "my_utils.h"

static void map_selection_update_zoom_pos(gm_t *gm)
{
    if (gm->game.map.params.zoom_level.x != 0.0) {
        sfView_zoom(gm->go.map_view, 1.0f / gm->game.map.params.zoom_level.x);
    }
    gm->game.map.params.zoom_level.x =
        (gm->maps->infos.size.x + gm->maps->infos.size.y) / 25.f;
    gm->game.map.params.zoom_level.y = (
        (gm->maps->infos.size.x + gm->maps->infos.size.y) / 25.f);
    sfView_move(gm->go.map_view, (sfVector2f) {
            -gm->game.map.params.offset.x,
            -gm->game.map.params.offset.y,
    });
    gm->game.map.params.offset.x = 0.f;
    gm->game.map.params.offset.y = gm->maps->infos.size.y * 10.f + 50.f;
    sfView_move(gm->go.map_view, gm->game.map.params.offset);
    sfView_zoom(gm->go.map_view, gm->game.map.params.zoom_level.x);
}

void map_selection_button_function_go_scr_game(gm_t *gm)
{
    sfVector2i new_size = {my_getnbr(gm->maps->size_str[0]),
        my_getnbr(gm->maps->size_str[1])};

    new_size.x = new_size.x == 0 ? 2 : new_size.x;
    new_size.y = new_size.y == 0 ? 2 : new_size.y;
    if (gm->maps->infos.size.x != new_size.x
        || gm->maps->infos.size.y != new_size.y) {
        if (map_3d_realloc(&gm->maps->map_3d, &gm->maps->infos.size,
                &new_size) != 0) {
            return;
        }
    }
    gm->maps->infos.size = new_size;
    game_map_destroy(&gm->game.map);
    game_map_init(gm, gm->maps);
    gm->maps->has_been_load = true;
    buttons_reset(gm, &gm->map_selection.buttons);
    buttons_animation(gm, &gm->game.buttons);
    map_selection_update_zoom_pos(gm);
    gm->current_screen = SCR_GAME;
}

void map_selection_button_function_go_scr_home(gm_t *gm)
{
    buttons_reset(gm, &gm->map_selection.buttons);
    buttons_animation(gm, &gm->home.buttons);
    gm->current_screen = SCR_HOME;
}
