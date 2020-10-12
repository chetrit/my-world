/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** main loop
*/

#include <stdlib.h>
#include "game.h"

static game_func const SCREEN_FUNCS[] = {
    &scr_home,
    &scr_game,
    &scr_options,
    &scr_map_selection,
};

static void game_loop(gm_t *gm)
{
    if (gm->config.is_music_on) {
        sfMusic_play(gm->go.musics[1]);
    }
    while (sfRenderWindow_isOpen(gm->window)) {
        if (gm->current_screen != SCR_CLOSE_GAME) {
            gm->game_speed =
                sfClock_restart(gm->go.clock).microseconds / 1000000.0f * 60.0f;
            sfRenderWindow_clear(gm->window, sfBlack);
            SCREEN_FUNCS[gm->current_screen](gm);
            sfRenderWindow_display(gm->window);
        } else {
            sfRenderWindow_close(gm->window);
        }
    }
}

int game_init(int ac, char *av[])
{
    gm_t gm;

    srand((ptrdiff_t)&gm * ac * (ptrdiff_t)av);
    if (game_manager_create(&gm, ac, av) != 0)
        return (1);
    update_obj_from_config(&gm);
    game_loop(&gm);
    map_save_all(&gm);
    config_file_save(&gm);
    game_manager_destroy(&gm);
    return (0);
}
