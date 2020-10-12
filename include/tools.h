/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** tools screen header
*/

#ifndef TOOLS_H_
#define TOOLS_H_

typedef enum tool_type_s {
    TOOL_TILE,
    TOOL_CORNER,
} tool_type_e;

typedef struct tool_s
{
    game_func *funcs;
    tool_type_e const *tool_type;
    int nb;
    int new_id;
    int id;
    bool is_corner;
    int brush_size;
} tool_t;

void tool_logic(gm_t *gm);

#endif /* !TOOLS_H_ */
