/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** options screen utils
*/

#include <stdlib.h>
#include "game.h"
#include "screens/init/options.h"

void options_screen_create(gm_t *gm)
{
    gm->options.sprites = gm->go.sprites + 8;
    gm->options.sprite_is_hidden = gm->go.sprite_is_hidden + 8;
    options_button_create(&gm->options, &gm->go);
    options_prog_bar_create(&gm->options, &gm->go);
    options_check_box_create(&gm->options, &gm->go);
    options_text_boxes_create(&gm->options, &gm->go);
}
