/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** define_win
*/

#include "def.h"

void display_restart_win(map_t *map, sfRenderWindow *win)
{
    if (map->menu[2].button[1].state == 0) {
        sfRenderWindow_drawSprite(win, map->menu[2].button[1].button, NULL);
    }
    else if (map->menu[2].button[1].state == 1) {
        map->menu[2].button[1].state = 0;
        restart_game(map);
    }
    else
        sfRenderWindow_drawSprite(win, map->menu[2].button[1].big_button, NULL);
}

void display_win_menu(map_t *map, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, map->menu[2].sprite, NULL);
    if (map->menu[2].button[0].state == 0)
        sfRenderWindow_drawSprite(win, map->menu[2].button[0].button, NULL);
    else if (map->menu[2].button[0].state == 1)
        sfRenderWindow_close(win);
    else
        sfRenderWindow_drawSprite(win, map->menu[2].button[0].big_button, NULL);
}

void define_win_menu2(map_t *map)
{
    button_t restart;

    restart.button_t = sfTexture_createFromFile("assets/img/replay.png", NULL);
    restart.button = sfSprite_create();
    sfSprite_setTexture(restart.button, restart.button_t, sfTrue);
    restart.position.x = 740;
    restart.position.y = 350;
    sfSprite_setPosition(restart.button, restart.position);
    restart.big_button_t =
    sfTexture_createFromFile("assets/img/big_replay.png", NULL);
    restart.big_button = sfSprite_create();
    sfSprite_setTexture(restart.big_button, restart.big_button_t, sfTrue);
    sfSprite_setPosition(restart.big_button, restart.position);
    restart.state = 0;
    restart.size_h = 150;
    restart.size_l = 421;
    map->menu[2].button[1] = restart;
    map->menu[2].m_state = 0;
    map->menu[2].music = sfMusic_createFromFile("assets/sounds/win.ogg");
}

void define_win_menu(map_t *map)
{
    button_t exit;

    map->menu[2].texture = sfTexture_createFromFile("assets/img/win.jpg", NULL);
    map->menu[2].sprite = sfSprite_create();
    sfSprite_setTexture(map->menu[2].sprite, map->menu[2].texture, sfTrue);
    exit.button_t = sfTexture_createFromFile("assets/img/exit.png", NULL);
    exit.button = sfSprite_create();
    sfSprite_setTexture(exit.button, exit.button_t, sfTrue);
    exit.position.x = 740;
    exit.position.y = 600;
    sfSprite_setPosition(exit.button, exit.position);
    exit.big_button_t =
    sfTexture_createFromFile("assets/img/big_exit.png", NULL);
    exit.big_button = sfSprite_create();
    sfSprite_setTexture(exit.big_button, exit.big_button_t, sfTrue);
    sfSprite_setPosition(exit.big_button, exit.position);
    exit.state = 0;
    exit.size_h = 150;
    exit.size_l = 421;
    define_win_menu2(map);
    map->menu[2].button[0] = exit;
}