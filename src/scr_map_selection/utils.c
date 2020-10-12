/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_selection screen utils
*/

#include <stdlib.h>
#include "game.h"
#include "screens/init/map_selection.h"

static void map_selection_set_new_strings(gm_t *gm)
{
    for (int i = 0; i < 4; ++i)
        free(gm->map_selection.text_boxes.pstrings.strings[i]);
    gm->map_selection.text_boxes.pstrings.strings[0] = gm->maps->infos.name;
    gm->map_selection.text_boxes.pstrings.strings[1] = gm->maps->infos.author;
    gm->map_selection.text_boxes.pstrings.strings[2] = gm->maps->size_str[0];
    gm->map_selection.text_boxes.pstrings.strings[3] = gm->maps->size_str[1];
    for (int i = 0; i < 4; ++i) {
        gm->map_selection.text_boxes.pstrings.length[i]
            = my_strlen(gm->map_selection.text_boxes.pstrings.strings[i]);
        gm->map_selection.text_boxes.pstrings.position
            = gm->map_selection.text_boxes.pstrings.length[i];
        sfText_setString(gm->map_selection.text_boxes.texts[i],
            gm->map_selection.text_boxes.pstrings.strings[i]);
    }
}

void map_selection_screen_create(gm_t *gm)
{
    gm->map_selection.sprites = gm->go.sprites + 23;
    map_selection_button_create(&gm->map_selection, &gm->go);
    map_selection_text_boxes_create(&gm->map_selection, &gm->go);
    map_selection_set_new_strings(gm);
}
