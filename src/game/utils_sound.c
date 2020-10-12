/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** create all sounds needed for the game
*/

#include <stdlib.h>
#include "game.h"

static const char SOUND_PATHS[3][22] = {
    "ressources/Basso.ogg",
    "ressources/Funk.ogg",
    "ressources/Sosumi.ogg",
};

int sounds_create_all(gm_t *gm)
{
    sfSoundBuffer **sound_buffers = malloc(sizeof(sfSoundBuffer *) * SOUND_NB);
    sfSound **sounds = malloc(sizeof(sfSound *) * SOUND_NB);

    if (sound_buffers == NULL || sounds == NULL)
        return (1);
    for (int i = 0; i < SOUND_NB; ++i) {
        sound_buffers[i] = sfSoundBuffer_createFromFile(SOUND_PATHS[i]);
        sounds[i] = sfSound_create();
        if (sound_buffers[i] == NULL || sounds[i] == NULL)
            return (1);
        sfSound_setBuffer(sounds[i], sound_buffers[i]);
    }
    gm->go.sound_buffers = sound_buffers;
    gm->go.sounds = sounds;
    return (0);
}

void sounds_destroy_all(gm_t *gm)
{
    sfSoundBuffer **sound_buffers = gm->go.sound_buffers;
    sfSound **sounds = gm->go.sounds;

    for (int i = 0; i < SOUND_NB; ++i) {
        sfSoundBuffer_destroy(sound_buffers[i]);
        sfSound_destroy(sounds[i]);
    }
    free(sound_buffers);
    free(sounds);
}
