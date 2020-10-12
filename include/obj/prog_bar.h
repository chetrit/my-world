/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** prog_bar object
*/

#ifndef OBJ_PROG_BAR_H_
#define OBJ_PROG_BAR_H_

typedef struct obj_progression_bars_s
{
    game_func *funcs;
    sfSprite **edge_sprites;
    sfSprite **sprites;
    sfIntRect const *rect;
    sfIntRect const *edge_rect;
    sfVector2f *pos;
    sfVector2f *edge_size;
    sfVector2f *size;
    int state;
    int id;
    int nb;
} obj_prog_bars_t;

void prog_bars_animation(
    obj_prog_bars_t *prog_bars, sfVector2i const *mouse_pos);
void prog_bars_event(gm_t *gm, obj_prog_bars_t *prog_bars, sfEvent *event);

#endif /* !OBJ_PROG_BAR_H_ */
