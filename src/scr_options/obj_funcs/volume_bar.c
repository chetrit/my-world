/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options button functions
*/

#include "game.h"

void options_prog_bar_function_sound_volume(gm_t *gm)
{
    int width = sfSprite_getTextureRect(gm->options.prog_bars.sprites[1]).width;

    for (int i = 0; i < SOUND_NB; i++) {
        sfSound_setVolume(
            gm->go.sounds[i],
            (float)width / (float)gm->options.prog_bars.size[1].x * 100.0f);
    }
    if (gm->config.is_sound_on) {
        sfSound_play(gm->go.sounds[2]);
    }
}

void options_prog_bar_function_music_volume(gm_t *gm)
{
    int width = sfSprite_getTextureRect(gm->options.prog_bars.sprites[0]).width;

    for (int i = 0; i < MUSIC_NB; i++) {
        sfMusic_setVolume(
            gm->go.musics[i],
            (float)width / (float)gm->options.prog_bars.size[0].x * 100.0f);
    }
}
