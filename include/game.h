/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** game header
*/

#ifndef GAME_H_
#define GAME_H_

#ifdef __APPLE__
    #pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include <stdbool.h>

#define UNUSED __attribute__((unused))

#define ABS(nb) (nb < 0 ? -nb : nb)
#define VECTOR2f_SUM(v1, v2) ((sfVector2f){v1->x + v2->x, v1->y + v2->y})
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)

typedef enum
{
    SCR_CLOSE_GAME = -1,
    SCR_HOME,
    SCR_GAME,
    SCR_OPTIONS,
    SCR_MAP_SELECTION,
} SCREEN_IDS;

/*
** Basso.ogg
** Funk.ogg
** Sosumi.ogg
*/
typedef enum
{
    SE_ERROR_1,
    SE_ERROR_2,
    SE_ERROR_3
} SOUND_EFFECTS;

static const sfVector2f SCREEN_SIZE = {1920.0f, 1080.0f};
static const sfVector2f SCREEN_MID = {960.0f, 540.0f};
static const int FONT_NB = 1;
static const int MUSIC_NB = 3;
static const int SOUND_NB = 3;
static const int SPRITE_NB = 78;
static const int STRING_NB = 5;
static const int TEXT_NB = 71;

typedef struct gm_s gm_t;
typedef void (*game_func)(gm_t *gm);

#include "my_utils.h"
#include "obj/buttons.h"
#include "obj/check_boxes.h"
#include "obj/text_boxes.h"
#include "obj/help_boxes.h"
#include "obj/prog_bar.h"
#include "screens/home.h"
#include "screens/game.h"
#include "screens/options.h"
#include "screens/map_selection.h"

typedef struct mouse_s
{
    sfBool buttons[sfMouseButtonCount];
    sfVector2i pos;
    float delta_scroll;
} mouse_t;

typedef struct keyboard_s
{
    game_func *funcs;
    int funcs_idx[sfKeyCount];
    sfBool keys[sfKeyCount];
} keyboard_t;

typedef struct game_objects_s
{
    sfView *map_view;
    sfView *ui_view;
    sfClock *clock;
    sfFont **fonts;
    sfMusic **musics;
    sfSound **sounds;
    sfSoundBuffer **sound_buffers;
    sfTexture *texture;
    sfSprite **sprites;
    bool *sprite_is_hidden;
    sfIntRect const *sprite_rect;
    sfVector2f *sprite_pos;
    sfVector2f *sprite_size;
    char **strings;
    int const *string_max_length;
    int *string_length;
    bool const *string_is_num_only;
    sfText **texts;
    obj_sprite_func *obj_sprite_funcs;
    sprite_collision_func *obj_sprite_collision_funcs;
    sfEvent event;
    mouse_t mouse;
    keyboard_t kb;
} game_objects_t;

typedef struct game_config_s
{
    char window_title[64];
    char config_path[64];
    char maps_path[64];
    char screenshots_path[64];
    sfVideoMode vmode;
    sfWindowStyle mode;
    int max_fps;
    bool vsync;
    bool is_music_on;
    bool is_sound_on;
    bool is_help_box;
} game_config_t;

struct gm_s
{
    sfRenderWindow *window;
    game_config_t config;
    game_objects_t go;
    map_save_t *maps;
    scr_home_t home;
    scr_game_t game;
    scr_options_t options;
    scr_map_selection_t map_selection;
    float game_speed;
    int current_screen;
};

int game_manager_create(gm_t *gm, int ac, char *av[]);
void game_manager_destroy(gm_t *gm);

int load_all_maps(gm_t *gm, int ac, char *av[]);
void map_save(map_save_t *map);
void map_save_all(gm_t *gm);
void convert_map(int ac, char *av[]);
map_save_t *map_save_create(map_save_t *prev, char *path);
void map_save_set_default_infos(map_save_t *map);

void game_move_map(gm_t *gm);

void config_init(gm_t *gm);

void take_screenshot(gm_t *gm);

void window_toggle_fullscreen(gm_t *gm);
void viewport_update(gm_t *gm);

void event_common(gm_t *gm);

void config_file_load(gm_t *gm);
void config_file_save(gm_t *gm);
void update_obj_from_config(gm_t *gm);

int point_is_colliding_rect(
    sfVector2f const *pos, sfVector2f const *size, sfVector2i const *mouse_pos);
int point_is_colliding_rect_left_up(
    sfVector2f const *pos, sfVector2f const *size, sfVector2i const *mouse_pos);

int window_and_view_create(gm_t *gm);
int fonts_create_all(gm_t *gm);
int musics_create_all(gm_t *gm);
int sounds_create_all(gm_t *gm);
int sprites_create_all(gm_t *gm);
int strings_create_all(gm_t *gm);
int texts_create_all(gm_t *gm);
void objs_add_function(gm_t *gm);
int game_map_init(gm_t *gm, map_save_t *map_save);

void window_and_view_destroy(gm_t *gm);
void fonts_destroy_all(gm_t *gm);
void musics_destroy_all(gm_t *gm);
void sounds_destroy_all(gm_t *gm);
void sprites_destroy_all(gm_t *gm);
void strings_destroy_all(gm_t *gm);
void texts_destroy_all(gm_t *gm);
void map_save_destroy_all(gm_t *gm);
void game_map_destroy(map_t *map);

void keyboard_init(gm_t *gm);

void keyboard_map_save(gm_t *gm);
void map_navigation_reset(gm_t *gm);

#endif /* !GAME_H_ */
