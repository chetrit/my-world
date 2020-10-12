/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map_selection screen header
*/

#ifndef SCR_MAP_SELECTION_H_
#define SCR_MAP_SELECTION_H_

#include "obj/buttons.h"

typedef struct scr_map_selection_s
{
    sfSprite **sprites;
    obj_buttons_t buttons;
    obj_text_boxes_t text_boxes;
} scr_map_selection_t;

void map_selection_screen_create(gm_t *gm);
void scr_map_selection(gm_t *gm);
void map_selection_map_create(gm_t *gm);

#endif /* !SCR_MAP_SELECTION_H_ */
