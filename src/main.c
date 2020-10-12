/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** main
*/

#include <stddef.h>
#include "my_utils.h"

int game_init(int ac, char *av[]);
void convert_map(int ac, char *av[]);

static void display_usage(void)
{
    my_putstr(
        "Finite terraformer program created with CSFML.\n\n"
        "USAGE\n"
        "\t./my_world [map_path]*\n"
        "\t./my_world --convert map_path [map_path]*\n\n"
        "OPTIONS\n"
        "\t-h print the usage and quit.\n"
    );
}

static int check_envp(char *envp[])
{
    if (envp == NULL) {
        return (1);
    }
    for (; *envp != NULL; ++envp) {
        if (my_strncmp("DISPLAY=", *envp, 8)) {
            return (0);
        }
    }
    return (1);
}

int main(int ac, char *av[], char *envp[])
{
    if (check_envp(envp) != 0) {
        return (84);
    }
    if (ac >= 3 && my_strcmp(av[1], "--convert") == 0) {
        convert_map(ac - 1, av + 1);
        return (0);
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_usage();
        return (0);
    }
    if (game_init(ac - 1, av + 1) != 0) {
        return (84);
    }
    return (0);
}
