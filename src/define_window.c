/*
** EPITECH PROJECT, 2019
** define_window
** File description:
** define the window
*/

#include "def.h"

sfVideoMode define_video(sfVideoMode video_mode)
{
    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    return (video_mode);
}

screen_t define_screen(screen_t screen)
{
    screen.video_mode = define_video(screen.video_mode);
    screen.window = sfRenderWindow_create(screen.video_mode,
                    "El Protector",
                    sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(screen.window, 60);
    sfRenderWindow_setMouseCursorVisible(screen.window, sfFalse);
    return (screen);
}
