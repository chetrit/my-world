/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** mem_init
*/

void mem_init(char *str, int len)
{
    while (len-- > 0) {
        *str++ = '\0';
    }
}
