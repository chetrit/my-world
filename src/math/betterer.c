/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** math functions
*/

#include <math.h>

float func_3d_bid_dad(float x, float y)
{
    float denominator = (3.0 + x * x + y * x);

    return (
        denominator == 0.0 ? 0.0 / 0.0 :
            12.0 * cos((x * x + y * x) / 4.0) / denominator
    );
}

float func_3d_what_the(float x, float y)
{
    float value = x * x + y * y;
    double z = exp(sqrt(value == 0.0 ? 1 : value)) - 5.0;

    return (
        z
    );
}

float func_3d_showdown(float x, float y)
{
    float value = x * x + y * y;
    double r = sqrt(value == 0.0 ? 1 : value);

    return (
        cos(r * M_PI / 2.0) - 2.0
    );
}

float func_3d_insane(float x, float y)
{
    double f1 = x * x + y * y;
    float denominator = (2.0 * (f1 * 6.28 + 1));

    return (
        denominator == 0.0 ? 0.0 / 0.0 : cos(f1 * 12.0) / denominator
    );
}

float func_3d_cos_sin(float x, float y)
{
    return (
        (cos(y) + sin(x)) * sin(y + x)
    );
}
