/*
** EPITECH PROJECT, 2020
** my_word
** File description:
** corners_highlighting
*/

#include <stdbool.h>
#include <math.h>
#include "game.h"

static const int INTERSECT_RADIUS = 20;

/*
** MOUSE POS TO DIVIDE
*/

bool is_on_corner(sfVector2f pos_map, sfVector2f *pos)
{
    float dif1 = fabs(pos->x - pos_map.x);
    float dif2 = fabs(pos->y - pos_map.y);

    if (dif1 * dif1 + dif2 * dif2 < INTERSECT_RADIUS * INTERSECT_RADIUS) {
        return (true);
    } else {
        return (false);
    }
}

void calculate_corner_highlight(map_t *map, sfVector2i *pos)
{
    sfVector2f adapted_pos = {SCREEN_MID.x + map->params.offset.x + (pos->x -
        SCREEN_MID.x) * map->params.zoom_level.x , (pos->y - SCREEN_MID.y
        ) * map->params.zoom_level.y + map->params.offset.y + SCREEN_MID.y};

    for (int i = map->params.map.y - 1; i >= 0; i--) {
        for (int j = map->params.map.x - 1; j >= 0; j--) {
            if (is_on_corner(map->data.map_iso[i][j], &adapted_pos)) {
                sfCircleShape_setPosition(map->events.highlighted_corner,
                (sfVector2f){map->data.map_iso[i][j].x - INTERSECT_RADIUS / 4,
                map->data.map_iso[i][j].y - INTERSECT_RADIUS / 4});
                map->events.is_highlight = true;
                map->events.pos_highlighted_item = (sfVector2i) {j, i};
                return;
            }
        }
    }
    map->events.is_highlight = false;
}

void draw_highlighted_corner(gm_t *gm)
{
    if (gm->game.map.events.is_highlight) {
        sfRenderWindow_drawCircleShape(
            gm->window, gm->game.map.events.highlighted_corner, NULL
        );
    }
}
