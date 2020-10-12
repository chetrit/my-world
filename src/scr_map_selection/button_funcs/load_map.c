/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map load button functions
*/

#include "game.h"

static void map_selection_set_strings_info(gm_t *gm)
{
    gm->map_selection.text_boxes.pstrings.strings[0] = gm->maps->infos.name;
    gm->map_selection.text_boxes.pstrings.strings[1] = gm->maps->infos.author;
    gm->map_selection.text_boxes.pstrings.strings[2] = gm->maps->size_str[0];
    gm->map_selection.text_boxes.pstrings.strings[3] = gm->maps->size_str[1];
    sfText_setString(
        gm->map_selection.text_boxes.texts[0], gm->maps->infos.name);
    sfText_setString(
        gm->map_selection.text_boxes.texts[1], gm->maps->infos.author);
    sfText_setString(
        gm->map_selection.text_boxes.texts[2], gm->maps->size_str[0]);
    sfText_setString(
        gm->map_selection.text_boxes.texts[3], gm->maps->size_str[1]);
}

static void map_selection_load_map_infos(gm_t *gm)
{
    my_putnbr_in_str(gm->maps->infos.size.x > 999 ?
        50 : gm->maps->infos.size.x, gm->maps->size_str[0]);
    my_putnbr_in_str(gm->maps->infos.size.y > 999 ?
        50 : gm->maps->infos.size.y, gm->maps->size_str[1]);
    gm->map_selection.text_boxes.pstrings.length[0]
        = my_strlen(gm->maps->infos.name);
    gm->map_selection.text_boxes.pstrings.length[1]
        = my_strlen(gm->maps->infos.author);
    gm->map_selection.text_boxes.pstrings.length[2]
        = my_strlen(gm->maps->size_str[0]);
    gm->map_selection.text_boxes.pstrings.length[3]
        = my_strlen(gm->maps->size_str[1]);
    map_selection_set_strings_info(gm);
}

void map_selection_index_map_increment(gm_t *gm)
{
    gm->maps = gm->maps->prev;
    map_selection_load_map_infos(gm);
}

void map_selection_index_map_decrement(gm_t *gm)
{
    gm->maps = gm->maps->next;
    map_selection_load_map_infos(gm);
}

void map_selection_map_create(gm_t *gm)
{
    map_save_t *new_map = map_save_create(gm->maps->prev, NULL);

    map_save_set_default_infos(new_map);
    new_map->next = gm->maps;
    gm->maps->prev = new_map;
    new_map->prev->next = new_map;
    gm->maps = new_map;
    map_selection_load_map_infos(gm);
}
