/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** keyboard header
*/

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

/*
** sfKeyEscape,
** sfKeyLControl,
** sfKeyLShift,
** sfKeyLAlt,
** sfKeyLSystem,
** sfKeyRControl,
** sfKeyRShift,
** sfKeyRAlt,
** sfKeyRSystem,
** sfKeyMenu,
** sfKeyLBracket,
** sfKeyRBracket,
** sfKeySemicolon,
** sfKeyComma,
** sfKeyPeriod,
** sfKeyQuote,
** sfKeySlash,
** sfKeyBackslash,
** sfKeyTilde,
** sfKeyEqual,
** sfKeyHyphen,
** sfKeySpace,
** sfKeyEnter,
** sfKeyBackspace,
** sfKeyTab,
** sfKeyPageUp,
** sfKeyPageDown,
** sfKeyEnd,
** sfKeyHome,
** sfKeyInsert,
** sfKeyDelete,
*/

void options_check_boxes_function_music_on_off(gm_t *gm);
void options_check_boxes_function_sound_on_off(gm_t *gm);
void options_check_boxes_function_help_box_on_off(gm_t *gm);

void brush_size_increment(gm_t *gm);
void brush_size_decrement(gm_t *gm);

void tile_outline_toggle(gm_t *gm);

void home_button_function_quit_game(gm_t *gm);

void map_smooth_reset(gm_t *gm);
void map_end_animation(gm_t *gm);

static game_func KEYBOARD_FUNCS[sfKeyCount] = {
    /* ALPHANUM KEYS */
    NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    &tile_outline_toggle,
    NULL,
    &map_tile_highlighting_func_id_decrement,
    &map_tile_highlighting_func_id_increment,
    &map_tile_coloration_func_id_decrement,
    &map_tile_coloration_func_id_increment,
    NULL,
    &brush_size_decrement,
    &brush_size_increment,
    NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL,
    /* NUM KEYS */
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    /* OTHER, SEE LINE 12 to 42 */
    /* escape */
    &home_button_function_quit_game,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL,
    &map_smooth_reset,
    NULL,
    &map_end_animation,
    NULL, NULL, NULL, NULL, NULL,
    NULL,
    /* OP KEYS: +, -, *, / */
    NULL, NULL, NULL, NULL,
    /* ARROW KEYS: LEFT, RIGHT, UP, DOWN */
    NULL, NULL, NULL, NULL,
    /* NUMPAD KEYS*/
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    /* F KEYS */
    &options_check_boxes_function_music_on_off,
    &options_check_boxes_function_sound_on_off,
    &options_check_boxes_function_help_box_on_off,
    NULL, NULL, NULL, NULL, NULL, NULL,
    &window_toggle_fullscreen,
    &window_toggle_fullscreen,
    &take_screenshot,
    NULL, NULL, NULL,
    /* pause key */
    NULL,
};

#endif /* !KEYBOARD_H_ */
