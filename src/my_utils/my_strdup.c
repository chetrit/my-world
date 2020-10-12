/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** strdup
*/

#include <stdlib.h>

char *my_strdup(char *str)
{
    char *temp;
    char *new_str;
    int len = 0;

    while (str[len])
        len++;
    new_str = malloc(len + 1);
    temp = new_str;
    while (*str != '\0')
        *temp++ = *str++;
    *temp = '\0';
    return (new_str);
}
