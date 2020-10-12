/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** home screen header
*/

#ifndef SCR_HOME_H_
#define SCR_HOME_H_

#include "obj/buttons.h"

typedef struct scr_home_s
{
    sfSprite **sprites;
    obj_buttons_t buttons;
} scr_home_t;

void home_screen_create(gm_t *gm);
void scr_home(gm_t *gm);

#endif /* !SCR_HOME_H_ */
