/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** math animation
*/

#include <stdlib.h>
#include "game.h"
#include "math_funcs.h"

void game_animation_line_by_line(gm_t *gm, math_3d_func *func);

void game_animation_by_time(gm_t *gm, math_3d_func *func);

static const int MATH_FUNC_NB = 14;

static math_3d_func MATH_FUNCS[] = {
    &func_3d_rastigrin_come_back,
    &func_3d_rastigrin,
    &func_3d_water_drop_wave,
    &func_3d_inner_twisted_wave,
    &func_3d_hole,
    &func_3d_sinusoidal,
    &func_3d_cos_sin,
    &func_3d_insane,
    &func_3d_showdown,
    &func_3d_what_the,
    &func_3d_bid_dad,
    &func_3d_simple_but_efficient,
    &func_3d_what_the_sinus,
    &func_3d_why_is_this_possible,
};

static const int MATH_STRUCT_FUNC_NB = 9;

static math_3d_func MATH_STRUCT_FUNCS[] = {
    &func_3d_hole,
    &func_3d_x_y_scalar,
    &func_3d_rastigrin,
    &func_3d_spike_at_the_middle,
    &func_3d_x_y_square,
    &func_3d_sin_pattern,
    &func_3d_round_square_middle,
    &func_3d_sinc_by_sinc,
    &func_3d_bad_butterfly,
};

void game_animation_math_structure(gm_t *gm)
{
    static int math_func_idx = 0;

    if (gm->game.animation.is_active == true) {
        game_animation_line_by_line(gm, MATH_STRUCT_FUNCS + math_func_idx);
    }
    if (gm->game.animation.is_active == false) {
        math_func_idx = (math_func_idx + 1) % MATH_STRUCT_FUNC_NB;
    }
}

void game_animation_math_fun_rand(gm_t *gm)
{
    static int math_func_idx = 0;

    if (gm->game.animation.is_active == true) {
        game_animation_by_time(gm, MATH_FUNCS + math_func_idx);
    }
    if (gm->game.animation.is_active == false) {
        math_func_idx = (math_func_idx + 1) % MATH_FUNC_NB;
    }
}
