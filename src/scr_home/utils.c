/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** home screen utils
*/

#include <stdlib.h>
#include "game.h"
#include "screens/init/home.h"

void home_screen_create(gm_t *gm)
{
    gm->home.sprites = gm->go.sprites;
    home_button_create(&gm->home, &gm->go);
}
