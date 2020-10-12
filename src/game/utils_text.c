/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** create all object needed for the game
*/

#include <stdlib.h>
#include "game.h"
#include "utils/text.h"

int texts_create_all(gm_t *gm)
{
    sfText **texts = malloc(sizeof(sfText *) * TEXT_NB);
    if (texts == NULL)
        return (1);
    for (int i = 0; i < TEXT_NB; ++i) {
        texts[i] = sfText_create();
        if (texts[i] == NULL)
            return (1);
        sfText_setFont(texts[i], gm->go.fonts[TEXT_FONT_ID[i]]);
        sfText_setCharacterSize(texts[i], TEXT_CHAR_SIZE[i]);
        sfText_setString(texts[i], TEXT_STRING_DEFAULT[i][0] == -1 ?
            gm->go.strings[i == 0 ? 0 : 1] : TEXT_STRING_DEFAULT[i]);
        sfText_setOrigin(texts[i], (sfVector2f){
            TEXT_SIZE[i].x / 2.0f, TEXT_SIZE[i].y / 2.0f});
        sfText_setPosition(texts[i], TEXT_POS[i]);
        sfText_setLetterSpacing(texts[i], TEXT_SPACING_FACTOR[i]);
        sfText_setColor(texts[i], sfBlack);
    }
    gm->go.texts = texts;
    return (0);
}

void texts_destroy_all(gm_t *gm)
{
    sfText **texts = gm->go.texts;

    for (int i = 0; i < TEXT_NB; ++i) {
        sfText_destroy(texts[i]);
    }
    free(texts);
}
