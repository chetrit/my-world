/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    while (*src != '\0')
        *dest++ = *src++;
    *dest = '\0';
    return (dest);
}
