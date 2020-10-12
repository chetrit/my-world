/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** map header
*/

#ifndef MATH_FUNCS_H_
#define MATH_FUNCS_H_

typedef float (*math_3d_func)(float x, float y);

void game_animation_from_middle(gm_t *gm, math_3d_func *func);

float func_3d_x_y_scalar(float x, float y);
float func_3d_rastigrin(float j, float i);
float func_3d_x_y_square(float x, float y);
float func_3d_spike_at_the_middle(float x, float y);
float func_3d_sin_pattern(float x, float y);
float func_3d_round_square_middle(float x, float y);
float func_3d_sinc_by_sinc(float x, float y);
float func_3d_bad_butterfly(float x, float y);

float func_3d_inner_twisted_wave(float x, float y);
float func_3d_water_drop_wave(float x, float y);
float func_3d_sinusoidal(float x, float y);
float func_3d_cos_sin(float x, float y);
float func_3d_insane(float x, float y);
float func_3d_showdown(float x, float y);
float func_3d_what_the(float x, float y);
float func_3d_bid_dad(float x, float y);
float func_3d_simple_but_efficient(float x, float y);
float func_3d_what_the_sinus(float x, float y);
float func_3d_hole(float x, float y);
float func_3d_rastigrin_come_back(float x, float y);
float func_3d_why_is_this_possible(float x, float y);

#endif /* !MATH_FUNCS_H_ */
