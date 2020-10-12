/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** tiles highlight
*/

#include "game.h"
#include "map/consts.h"

static const int NB_SIDES = 4;

static bool do_intersect(sfVector2f vert[4], sfVector2f *pos)
{
    bool result = false;

    for (int i = 0, j = NB_SIDES - 1; i < NB_SIDES; j = i++) {
        if (((vert[i].y > pos->y) != (vert[j].y > pos->y)) &&
            (pos->x < (vert[j].x - vert[i].x) * (pos->y - vert[i].y)
            / (vert[j].y - vert[i].y) + vert[i].x)) {
            result = !result;
        }
    }
    return (result);
}

static bool is_on_tile(map_t *map, sfVector2f *pos, int i, int j)
{
    sfVector2f vert[4] = {
        map->data.map_iso[i][j],
        map->data.map_iso[i - 1][j],
        map->data.map_iso[i - 1][j - 1],
        map->data.map_iso[i][j - 1],
    };

    return (do_intersect(vert, pos));
}

void calculate_tiles_highlight(map_t *map, sfVector2i *pos, int range)
{
    sfVector2f adapted_pos = {SCREEN_MID.x + map->params.offset.x + (pos->x -
        SCREEN_MID.x) * map->params.zoom_level.x , (pos->y - SCREEN_MID.y
        ) * map->params.zoom_level.y + map->params.offset.y + SCREEN_MID.y};

    for (int i = map->params.map.y - 1; i > 0; i--) {
        for (int j = map->params.map.x - 1; j > 0; j--) {
            if (is_on_tile(map, &adapted_pos, i, j)) {
                (map->data.highlight_funcs[map->params.tile_highlight_func_id])(
                    map, &((sfVector2i){j, i}), range);
                map->events.is_highlight = true;
                map->events.pos_highlighted_item = (sfVector2i) {j, i};
                map->events.last_range = range;
                return;
            }
        }
    }
    map->events.is_highlight = false;
}

void tile_highlight_logic(gm_t *gm)
{
    map_t *map = &gm->game.map;

    if (gm->game.buttons.id == -1) {
        if (gm->game.tools.is_corner == true) {
            calculate_corner_highlight(map, &gm->go.mouse.pos);
        } else {
            calculate_tiles_highlight(
                map, &gm->go.mouse.pos, gm->game.tools.brush_size);
        }
    } else if (map->events.is_highlight == true) {
        map->events.is_highlight = false;
    }
}
