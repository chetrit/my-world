/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my_utils.h"

char *my_string_merge(char *str1, char *str2)
{
    char *new = malloc(sizeof(char) * (my_strlen(str1)
        + my_strlen(str2) + 1));

    my_strcpy(new, str1);
    my_strcat(new, str2);
    return (new);
}

char *get_last_occ_slash(char *str)
{
    char *tmp = str;

    while (*tmp != '\0') {
        if (*tmp == '/') {
            str = tmp + 1;
        }
        ++tmp;
    }
    return (str);
}
