/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** math functions
*/

#include <math.h>

float func_3d_sinusoidal(float x, float y)
{
    float value = x * x + y * y;

    return (
        sin(sqrt(value == 0.0 ? 1 : value))
    );
}

float func_3d_water_drop_wave(float x, float y)
{
    float value = x * x + y * y;
    double r = sqrt(value == 0.0 ? 1 : value);

    return (
        exp(-r / 4.0) * sin(3.0 * r) * 15.0
    );
}
