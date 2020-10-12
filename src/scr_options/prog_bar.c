/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options prog bar init
*/

#include <stdlib.h>
#include "game.h"

static const int OPTIONS_BAR_NB = 2;
static const int SPRITE_OFFSET = 10;

void options_prog_bar_function_music_volume(gm_t *gm);

void options_prog_bar_function_sound_volume(gm_t *gm);

static const game_func OPTIONS_BAR_FUNCS[] = {
    &options_prog_bar_function_music_volume,
    &options_prog_bar_function_sound_volume,
};

void options_prog_bar_create(scr_options_t *scr, game_objects_t *go)
{
    scr->prog_bars = (obj_prog_bars_t){
        (game_func *)OPTIONS_BAR_FUNCS,
        go->sprites + SPRITE_OFFSET,
        go->sprites + OPTIONS_BAR_NB + SPRITE_OFFSET,
        go->sprite_rect + SPRITE_OFFSET,
        go->sprite_rect + OPTIONS_BAR_NB + SPRITE_OFFSET,
        go->sprite_pos + SPRITE_OFFSET,
        go->sprite_size + SPRITE_OFFSET,
        go->sprite_size + OPTIONS_BAR_NB + SPRITE_OFFSET,
        0,
        -1,
        OPTIONS_BAR_NB
    };
}
