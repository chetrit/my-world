/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** my_putnbr
*/

#include <stdio.h>
#include "my_utils.h"

static int set_base(int nb)
{
    int base = 1;

    if (nb < 0) {
        while (base * -1 >= nb / 10)
            base *= 10;
    } else {
        while (base <= nb / 10)
            base *= 10;
    }
    return (base);
}

int my_put_nbr(int nb, FILE *file)
{
    int base;
    char char_to_print;

    base = set_base(nb);
    while (base >= 1) {
        char_to_print = nb / base % 10;
        if (char_to_print < 0)
            char_to_print *= -1;
        base /= 10;
        char_to_print += '0';
        fwrite(&char_to_print, 1, 1, file);
    }
    return (0);
}

void my_putnbr_in_str(int nb, char *str)
{
    int base;
    char char_to_print;
    int i = 0;

    base = set_base(nb);
    for (; base >= 1;) {
        char_to_print = nb / base % 10;
        if (char_to_print < 0)
            char_to_print *= -1;
        base /= 10;
        char_to_print += '0';
        str[i++] = char_to_print;
    }
    str[i] = '\0';
}

void my_putnbr_in_end_str(int nb, char *str)
{
    int base;
    char char_to_print;
    int i = my_strlen(str);

    base = set_base(nb);
    for (; base >= 1;) {
        char_to_print = nb / base % 10;
        if (char_to_print < 0)
            char_to_print *= -1;
        base /= 10;
        char_to_print += '0';
        str[i++] = char_to_print;
    }
    str[i] = '\0';
}
