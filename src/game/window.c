
/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** window utils
*/

#include "game.h"

/*
** Create window may fail
*/

void viewport_update(gm_t *gm)
{
    sfFloatRect viewport = {0.f, 0.f, 1.f, 1.f};

    float screen_width = gm->config.vmode.width / SCREEN_SIZE.x;
    float screen_height = gm->config.vmode.height / SCREEN_SIZE.y;

    if (screen_width > screen_height) {
        viewport.width = screen_height / screen_width;
        viewport.left = (1.f - viewport.width) / 2.f;
    } else if (screen_width < screen_height) {
        viewport.height = screen_width / screen_height;
        viewport.top = (1.f - viewport.height) / 2.f;
    }
    sfView_setViewport(gm->go.ui_view, viewport);
    sfView_setViewport(gm->go.map_view, viewport);
}

void window_toggle_fullscreen(gm_t *gm)
{
    if (gm->config.mode & sfFullscreen) {
        gm->config.mode = sfDefaultStyle;
    } else {
        gm->config.mode = sfFullscreen;
    }
    sfRenderWindow_close(gm->window);
    gm->window = sfRenderWindow_create(
        gm->config.vmode, gm->config.window_title,
        gm->config.mode, NULL);
    if (gm->window == NULL)
        return;
    sfRenderWindow_setFramerateLimit(gm->window, gm->config.max_fps);
}

void window_and_view_destroy(gm_t *gm)
{
    sfRenderWindow_destroy(gm->window);
    sfView_destroy(gm->go.map_view);
    sfView_destroy(gm->go.ui_view);
}

static void view_init(gm_t *gm)
{
    sfView_setCenter(gm->go.ui_view,
        (sfVector2f){SCREEN_SIZE.x / 2, SCREEN_SIZE.y / 2});
    sfView_setSize(gm->go.ui_view,
        (sfVector2f){SCREEN_SIZE.x, SCREEN_SIZE.y});
    sfView_setCenter(gm->go.map_view,
        (sfVector2f){SCREEN_SIZE.x / 2, SCREEN_SIZE.y / 2});
    sfView_setSize(gm->go.map_view,
        (sfVector2f){SCREEN_SIZE.x, SCREEN_SIZE.y});
}

int window_and_view_create(gm_t *gm)
{
    sfVector2u screen_size;

    gm->window = sfRenderWindow_create(gm->config.vmode,
        gm->config.window_title, gm->config.mode, NULL);
    screen_size = sfRenderWindow_getSize(gm->window);
    gm->go.map_view = sfView_create();
    gm->go.ui_view = sfView_create();
    if (gm->window == NULL || gm->go.map_view == NULL || gm->go.ui_view == NULL)
        return (1);
    sfRenderWindow_setFramerateLimit(gm->window, gm->config.max_fps);
    view_init(gm);
    gm->config.vmode.width = screen_size.x;
    gm->config.vmode.height = screen_size.y;
    viewport_update(gm);
    return (0);
}
