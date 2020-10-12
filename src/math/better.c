/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** math functions
*/

#include <math.h>

float func_3d_inner_twisted_wave(float x, float y)
{
    float value = x * x + y * y;
    double r = sqrt(value == 0.0 ? 1 : value);
    float denominator = (1.0 + r) * (x * sin(4 * r) + y * cos(4 * r));

    return (
        denominator == 0.0 ? 0.0 / 0.0 : 1.0 / denominator
    );
}

float func_3d_rastigrin_come_back(float x, float y)
{
    return (
        cos(2.0 * M_PI * x)
        + cos(2.0 * M_PI * y)
    );
}

float func_3d_why_is_this_possible(float x, float y)
{
    float denominator = (x * sin(x) + y * sin(y) < 0) * y;

    return (
        denominator == 0.0 ? 0.0 / 0.0 : 1.0 / denominator
    );
}

float func_3d_simple_but_efficient(float x, float y)
{
    float denominator = (y * x * x * x) * y;

    return (
        denominator == 0.0 ? 0.0 / 0.0 : 1.0 / denominator
    );
}

float func_3d_what_the_sinus(float x, float y)
{
    return (
        3.0 * x * sin(y / 2.0)
    );
}
