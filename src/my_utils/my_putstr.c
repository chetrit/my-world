/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** my_putstr
*/

#include <unistd.h>
#include "game.h"

int my_putstr(char const *str)
{
    int length = my_strlen(str);

    write(1, str, length);
    return (0);
}

int my_putstr_fd(char const *str, int fd)
{
    int length = my_strlen(str);

    write(fd, str, length);
    return (0);
}
