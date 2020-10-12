/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game screen utils
*/

#include <stdlib.h>
#include "game.h"
#include "screens/init/game.h"

int game_screen_create(gm_t *gm)
{
    gm->game.sprites = gm->go.sprites + 35;
    gm->game.sprite_is_hidden = gm->go.sprite_is_hidden + 35;
    game_button_create(&gm->game, &gm->go);
    game_help_box_create(&gm->game, &gm->go);
    gm->game.animation = (animation_t){
        GAME_ANIMATION_FUNCS, GAME_ANIMATION_NB, 0, 0
    };
    gm->game.tools = (tool_t){
        GAME_TOOL_FUNCS, GAME_TOOL_TYPE, GAME_TOOL_NB, 0, 0, false, 0
    };
    return (game_map_init_struct(&gm->game.map)
        || game_map_init(gm, gm->maps));
}
