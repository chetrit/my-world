/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** shortcut
*/

#include "game.h"
#include "my_utils.h"

void map_navigation_reset(gm_t *gm)
{
    sfView_move(gm->go.map_view, (sfVector2f) {
        -gm->game.map.params.offset.x, -gm->game.map.params.offset.y
    });
    if (gm->game.map.params.zoom_level.x != 0.0) {
        sfView_zoom(gm->go.map_view, 1.0f / gm->game.map.params.zoom_level.x);
        sfView_zoom(gm->go.map_view, 1.0f);
    }
    gm->game.map.params.offset.x = 0;
    gm->game.map.params.offset.y = 0;
    gm->game.map.params.zoom_level.x = 1;
    gm->game.map.params.zoom_level.y = 1;
}

void keyboard_map_save(gm_t *gm)
{
    if (gm->maps->path == NULL) {
        gm->maps->path = my_string_merge(
            gm->config.maps_path, gm->maps->infos.name);
    }
    map_save(gm->maps);
}
