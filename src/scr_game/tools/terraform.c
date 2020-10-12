/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** terraforming tools
*/

#include "game.h"

static const double BUILD_LIMIT = 15.94f;
static const double BUILD_INCREMENT = 0.15f;

void game_tool_dig_or_mountain_add(gm_t *gm)
{
    double mod = gm->go.mouse.buttons[0] == true
        ? BUILD_INCREMENT : -BUILD_INCREMENT;

    if (gm->go.mouse.buttons[0] == false && gm->go.mouse.buttons[1] == false) {
        return;
    }
    game_tool_brush_dig_or_mountain_add(&gm->game, mod);
}

void game_tool_dig_or_mountain_add_once(gm_t *gm)
{
    static int is_last_call = 1;
    double mod = gm->go.mouse.buttons[0] == true
        ? 1 : -1;

    if (gm->go.mouse.buttons[0] == false && gm->go.mouse.buttons[1] == false) {
        is_last_call = 1;
        return;
    } else if (is_last_call) {
        game_tool_brush_dig_or_mountain_add(&gm->game, mod);
        is_last_call = 0;
    }
}

void game_tool_reset_to_0(gm_t *gm)
{
    if (gm->go.mouse.buttons[0] == false && gm->go.mouse.buttons[1] == false) {
        return;
    }
    game_tool_brush_dig_or_mountain_replace(&gm->game, 0.0f);
}

void game_tool_dig_or_mountain_corner(gm_t *gm)
{
    sfVector2i *index = &gm->game.map.events.pos_highlighted_item;
    double mod = gm->go.mouse.buttons[0] == true
        ? BUILD_INCREMENT : -BUILD_INCREMENT;

    if (gm->go.mouse.buttons[0] == false && gm->go.mouse.buttons[1] == false) {
        return;
    }
    if (gm->game.map.data.map_3d[index->y][index->x] * (mod >= 0 ? 1 : -1)
        < BUILD_LIMIT) {
        gm->game.map.data.map_3d[index->y][index->x] += mod;
    }
}
