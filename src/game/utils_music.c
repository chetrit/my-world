/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** create all object needed for the game
*/

#include <stdlib.h>
#include "game.h"

static const char MUSIC_PATHS[3][40] = {
    "ressources/mario_galaxy_music.ogg",
    "ressources/chompsworks_galaxy_smg2.ogg",
    "ressources/hint_tv_smg2.ogg",
};

static const sfBool MUSIC_IS_LOOP[] = {
    sfTrue, sfTrue, sfTrue,
};

int musics_create_all(gm_t *gm)
{
    sfMusic **musics = malloc(sizeof(sfMusic *) * MUSIC_NB);

    if (musics == NULL)
        return (1);
    for (int i = 0; i < MUSIC_NB; ++i) {
        musics[i] = sfMusic_createFromFile(MUSIC_PATHS[i]);
        if (musics[i] == NULL)
            return (1);
        sfMusic_setLoop(musics[i], MUSIC_IS_LOOP[i]);
    }
    gm->go.musics = musics;
    return (0);
}

void musics_destroy_all(gm_t *gm)
{
    sfMusic **musics = gm->go.musics;

    for (int i = 0; i < MUSIC_NB; ++i) {
        sfMusic_destroy(musics[i]);
    }
    free(musics);
}
