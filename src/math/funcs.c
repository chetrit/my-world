/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** math functions
*/

#include <math.h>

float func_3d_x_y_scalar(float x, float y)
{
    return (
        sqrt(x * x + y * y)
    );
}

float func_3d_rastigrin(float x, float y)
{
    return (
        sqrt(x * x + y * y)
        + cos(2.0 * M_PI * x)
        + cos(2.0 * M_PI * y)
    );
}

float func_3d_x_y_square(float x, float y)
{
    return (
        (x * x + y * y) / 35.0f - 10.0f
    );
}

float func_3d_sin_pattern(float x, float y)
{
    return (
        sin(x * x + y * y - 5.0) * 5.0f + 10.0f
    );
}

float func_3d_hole(float a, float b)
{
    return (
        sqrt(a * a + b * b) + 3.0 * cos(sqrt(a * a + b * b)) + 5.0 / 10.0 - 20.0
    );
}
