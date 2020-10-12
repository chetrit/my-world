/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map header
*/

#ifndef MAP_H_
#define MAP_H_

#include "map/defs.h"

//INIT
int game_map_init_struct(map_t *map);
sfVector2f **malloc_2d_map(int nb_rows, int nb_cols);
void map_iso_update(map_t *map);
float **generate_map_3d(sfVector2i dim);
int map_3d_realloc(
    float ***map_3d, const sfVector2i *size, const sfVector2i *new_size);
void map_3d_destroy(float **map_3d, const sfVector2i *size);
//CALC
sfVector2f project_iso_point(int x, int y, float z, map_t *map);

//LOGIC
void set_tiles(gm_t *gm);
void set_tile_range_color(map_t *map, sfVector2i *mid, int range);
void calculate_tiles_highlight(map_t *map, sfVector2i *pos, int range);
void calculate_corner_highlight(map_t *map, sfVector2i *pos);
void bottom_computation(map_t *map);
void bottom_fix_point_init_right(map_t *map);
void bottom_fix_point_init_left(map_t *map);
void water_tile_set_point(map_t *map);

void update_zoom(gm_t *gm);

void tile_highlight_logic(gm_t *gm);

void map_tile_coloration_func_id_increment(gm_t *gm);
void map_tile_coloration_func_id_decrement(gm_t *gm);
void map_tile_highlighting_func_id_increment(gm_t *gm);
void map_tile_highlighting_func_id_decrement(gm_t *gm);

//DISPLAY
void draw_map_iso(gm_t *gm);
void bottom_draw(gm_t *gm);
void draw_special_bottom(gm_t *gm);
void draw_tiles(gm_t *gm);
void draw_highlighted_tile(gm_t *gm);
void draw_highlighted_corner(gm_t *gm);

#endif /* !MAP_H_ */
