/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** button object
*/

#ifndef OBJ_BUTTONS_H_
#define OBJ_BUTTONS_H_

typedef void (*obj_sprite_func)(sfSprite *sprite, sfIntRect rect, int state);
typedef int (*sprite_collision_func)(
    sfVector2f const *pos, sfVector2f const *size, sfVector2i const *mouse_pos);

typedef enum collision_type_s
{
    RECT_LEFT,
    RECT_CENTER,
    CIRCLE_CENTER,
} collision_type_e;

typedef struct obj_buttons_s
{
    game_func *funcs;
    sfSprite **sprites;
    bool *sprite_is_hidden;
    int const *hover_func_ids;
    collision_type_e const *collision_types;
    sfSound **sounds;
    sfIntRect const *rects;
    sfVector2f *pos;
    sfVector2f *size;
    int state;
    int id;
    int nb;
} obj_buttons_t;

void buttons_event(gm_t *gm, obj_buttons_t *buttons, sfEvent *event);
void buttons_update_rect(obj_buttons_t *buttons, int id, int state);
void buttons_animation(gm_t *gm, obj_buttons_t *buttons);
void buttons_reset(gm_t *gm, obj_buttons_t *buttons);

#endif /* !OBJ_BUTTONS_H_ */
