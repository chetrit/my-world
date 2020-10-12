/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map init header
*/

#ifndef MAP_DEFS_H_
#define MAP_DEFS_H_

typedef struct map_s map_t;

typedef void (*tile_color_func)(map_t *map, sfColor *color, int i, int j);
typedef void (*tile_highlight_func)(map_t *map, sfVector2i *mid, int range);

typedef struct map_save_info_s
{
    char name[64];
    char author[64];
    sfVector2i size;
} map_save_info_t;

typedef struct map_save_s
{
    struct map_save_s *prev;
    struct map_save_s *next;
    map_save_info_t infos;
    char size_str[2][4];
    float **map_3d;
    char *path;
    bool has_been_load;
} map_save_t;

typedef struct map_iso_parameters_s
{
    sfVector2i map;
    int map_sampling;
    float map_horizontal_angle;
    float map_vertical_angle;
    sfVector2i map_shift;
    int map_btm_coef;
    int map_nb_tiles;
    sfIntRect rect;
    sfVector2f zoom_level;
    sfVector2f offset;
    sfVector2f speed;
    float lowest_point;
    bool is_tile_outline;
    int tile_color_func_id;
    int tile_color_func_nb;
    int tile_highlight_func_id;
    int tile_highlight_func_nb;
} map_iso_parameters_t;

typedef struct map_iso_bottom_s
{
    sfConvexShape **left;
    sfConvexShape **right;
} map_iso_bottom_t;

typedef struct map_iso_data_s
{
    sfVector2f **map_iso;
    sfConvexShape **tiles;
    float **map_3d;
    map_iso_bottom_t bottom;
    sfConvexShape *water_tile;
    tile_color_func *color_funcs;
    tile_highlight_func *highlight_funcs;
} map_iso_data_t;

typedef struct map_iso_events_s
{
    bool is_highlight;
    sfVector2i pos_highlighted_item;
    sfCircleShape *highlighted_corner;
    int last_range;
} map_iso_events_t;

struct map_s
{
    map_iso_parameters_t params;
    map_iso_data_t data;
    map_iso_events_t events;
};

#endif /* !MAP_DEFS_H_ */
