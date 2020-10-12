/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** math functions with sinc
*/

#include <math.h>

static double sinc(const double x)
{
    if (x == 0) {
        return (1);
    } else {
        return (sin(x) / x);
    }
}

float func_3d_spike_at_the_middle(int x, int y)
{
    return ((float) (
        sinc(sqrt(x * x + y * y))) * 20.0f + 10.0f
    );
}

float func_3d_round_square_middle(int x, int y)
{
    return ((float) (
        sinc(x*x) * sinc(y*y)
        ) * 50.0f + 10.0f
    );
}

float func_3d_sinc_by_sinc(int x, int y)
{
    return ((float) (
        sinc(x) * sinc(y)
        ) * 30.0f + 10.0f
    );
}

float func_3d_bad_butterfly(int x, int y)
{
    return ((float) (
        sinc( (x - y) / ((x + y  == 0 ? 1 : x + y)) )
        ) * 10.0f + 10.0f
    );
}
