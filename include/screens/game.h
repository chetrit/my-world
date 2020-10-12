/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game screen header
*/

#ifndef SCR_GAME_H_
#define SCR_GAME_H_

#include "map.h"
#include "tools.h"

typedef struct animation_s
{
    game_func *funcs;
    int nb;
    int id;
    int is_active;
} animation_t;

typedef struct scr_game_s
{
    sfSprite **sprites;
    bool *sprite_is_hidden;
    map_t map;
    obj_buttons_t buttons;
    obj_help_boxes_t help_boxes;
    animation_t animation;
    tool_t tools;
} scr_game_t;

int game_screen_create(gm_t *gm);
void scr_game(gm_t *gm);

void game_burger_close_all(gm_t *gm);

void game_keyboard_actions_pressed(gm_t *gm, sfEvent *event);
void game_keyboard_actions(gm_t *gm);

void game_tool_brush_dig_or_mountain_add(scr_game_t *game, float value);
void game_tool_brush_dig_or_mountain_replace(scr_game_t *game, float value);

#endif /* !SCR_GAME_H_ */
