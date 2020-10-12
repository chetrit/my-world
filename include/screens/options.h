/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options screen header
*/

#ifndef SCR_OPTIONS_H_
#define SCR_OPTIONS_H_

#include "obj/buttons.h"

typedef struct scr_options_s
{
    sfSprite **sprites;
    bool *sprite_is_hidden;
    obj_buttons_t buttons;
    obj_prog_bars_t prog_bars;
    obj_check_boxes_t check_boxes;
    obj_text_boxes_t text_boxes;
} scr_options_t;

void options_screen_create(gm_t *gm);
void scr_options(gm_t *gm);

#endif /* !SCR_OPTIONS_H_ */
