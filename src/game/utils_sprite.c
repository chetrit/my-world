/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** create all sprites needed for the game
*/

#include <stdlib.h>
#include "game.h"
#include "utils/sprite.h"

static int sprites_init_all(
    gm_t *gm, sfVector2f *pos, sfVector2f *size, bool *sprite_is_hidden)
{
    sfSprite **sprites = malloc(sizeof(sfSprite *) * SPRITE_NB);

    if (sprites == NULL)
        return (1);
    for (int i = 0; i < SPRITE_NB; ++i) {
        pos[i] = SPRITE_POS[i];
        size[i] = (sfVector2f){
            SPRITE_RECTS[i].width / 2.0f, SPRITE_RECTS[i].height / 2.0f};
        sprites[i] = sfSprite_create();
        if (sprites[i] == NULL)
            return (1);
        sfSprite_setTexture(sprites[i], gm->go.texture, sfTrue);
        sfSprite_setTextureRect(sprites[i], SPRITE_RECTS[i]);
        sfSprite_setOrigin(sprites[i], size[i]);
        sfSprite_setPosition(sprites[i], pos[i]);
        sprite_is_hidden[i] = SPRITE_IS_HIDDEN[i];
    }
    gm->go.sprites = sprites;
    return (0);
}

int sprites_create_all(gm_t *gm)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) * SPRITE_NB);
    sfVector2f *size = malloc(sizeof(sfVector2i) * SPRITE_NB);
    bool *sprite_is_hidden = malloc(sizeof(bool) * SPRITE_NB);

    gm->go.texture = sfTexture_createFromFile(SPRITE_SHEET_PATH, NULL);
    if (pos == NULL || size == NULL || sprite_is_hidden == NULL
        || gm->go.texture == NULL)
        return (1);
    gm->go.sprite_is_hidden = sprite_is_hidden;
    gm->go.sprite_rect = SPRITE_RECTS;
    gm->go.sprite_pos = pos;
    gm->go.sprite_size = size;
    return (sprites_init_all(gm, pos, size, sprite_is_hidden));
}

void sprites_destroy_all(gm_t *gm)
{
    sfSprite **sprites = gm->go.sprites;

    sfTexture_destroy(gm->go.texture);
    for (int i = 0; i < SPRITE_NB; ++i) {
        sfSprite_destroy(sprites[i]);
    }
    free(sprites);
    free(gm->go.sprite_pos);
    free(gm->go.sprite_size);
}
