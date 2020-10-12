/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** create all object needed for the game
*/

#include <stdlib.h>
#include "game.h"
#include "utils/string.h"

int strings_create_all(gm_t *gm)
{
    char **strings = malloc(sizeof(char *) * STRING_NB);
    int *length = malloc(sizeof(int) * STRING_NB);

    if (strings == NULL || length == NULL)
        return (1);
    for (int i = 0; i < STRING_NB; ++i) {
        strings[i] = malloc(sizeof(char) * (STRING_LENGTH[i] + 2));
        if (strings[i] == NULL)
            return (1);
        mem_init(strings[i], STRING_LENGTH[i] + 2);
        my_strcpy(strings[i], STRING_INIT[i]);
        length[i] = my_strlen(STRING_INIT[i]);
    }
    gm->go.strings = strings;
    gm->go.string_max_length = STRING_LENGTH;
    gm->go.string_length = length;
    gm->go.string_is_num_only = IS_NUMERIC_ONLY;
    return (0);
}

void strings_destroy_all(gm_t *gm)
{
    char **strings = gm->go.strings;

    for (int i = 0; i < STRING_NB - 4; ++i) {
        free(strings[i]);
    }
    free(strings);
    free(gm->go.string_length);
}
