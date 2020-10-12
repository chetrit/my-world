/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** zoom management
*/

#include "game.h"

void update_zoom(gm_t *gm)
{
    if (gm->game.map.params.zoom_level.x != 0.0) {
        sfView_zoom(gm->go.map_view, 1.0f / gm->game.map.params.zoom_level.x);
    }
    gm->game.map.params.zoom_level.x -= gm->go.mouse.delta_scroll / 10.0f;
    gm->game.map.params.zoom_level.y -= gm->go.mouse.delta_scroll / 10.0f;
    sfView_zoom(gm->go.map_view, gm->game.map.params.zoom_level.x);
    gm->go.mouse.delta_scroll = 0;
}
