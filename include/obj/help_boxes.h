/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** help boxes object
*/

#ifndef OBJ_HELP_BOXES_H_
#define OBJ_HELP_BOXES_H_

typedef struct obj_help_boxes_s
{
    sfSprite **sprites;
    bool *sprite_is_hidden;
    sfText **texts;
    int const *button_id_corres;
    int nb;
} obj_help_boxes_t;

#endif /* !OBJ_HELP_BOXES_H_ */
