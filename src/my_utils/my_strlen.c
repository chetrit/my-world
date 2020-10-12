/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    char const *tmp = str;

    while (*tmp)
        tmp++;
    return (tmp - str);
}
