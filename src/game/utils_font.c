/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** create all object needed for the game
*/

#include <stdlib.h>
#include "game.h"

static const char FONT_PATHS[1][32] = {
    "ressources/fixed_width_font.ttf"
};

int fonts_create_all(gm_t *gm)
{
    sfFont **fonts = malloc(sizeof(sfFont *) * FONT_NB);

    if (fonts == NULL) {
        return (1);
    }
    for (int i = 0; i < FONT_NB; ++i) {
        fonts[i] = sfFont_createFromFile(FONT_PATHS[i]);
        if (fonts[i] == NULL) {
            return (1);
        }
    }
    gm->go.fonts = fonts;
    return (0);
}

void fonts_destroy_all(gm_t *gm)
{
    sfFont **fonts = gm->go.fonts;

    for (int i = 0; i < FONT_NB; ++i) {
        sfFont_destroy(fonts[i]);
    }
    free(fonts);
}
