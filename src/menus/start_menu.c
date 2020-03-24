/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** start_menu.c
*/

#include "def.h"

void display_htp(map_t *map, sfRenderWindow *win)
{
    if (map->menu[0].button[3].state == 0)
        sfRenderWindow_drawSprite(win, map->menu[0].button[3].button, NULL);
    else if (map->menu[0].button[3].state == 1) {
        map->menu[0].button[3].state = 0;
        map->state = 5;
    }
    else
        sfRenderWindow_drawSprite(win, map->menu[0].button[3].big_button, NULL);
}

void display_htp_menu(map_t *map, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, map->menu[4].sprite, NULL);
    if (map->menu[4].button[0].state == 0)
        sfRenderWindow_drawSprite(win, map->menu[4].button[0].button, NULL);
    else if (map->menu[4].button[0].state == 1) {
        map->menu[4].button[0].state = 0;
        map->state = 0;
    }
    else
        sfRenderWindow_drawSprite(win, map->menu[4].button[0].big_button, NULL);
}

void define_htp_menu(map_t *map)
{
    button_t htp;

    map->menu[4].texture = sfTexture_createFromFile("assets/img/htp.png", NULL);
    map->menu[4].sprite = sfSprite_create();
    sfSprite_setTexture(map->menu[4].sprite, map->menu[4].texture, sfTrue);
    htp.button_t = sfTexture_createFromFile("assets/img/left.png", NULL);
    htp.button = sfSprite_create();
    sfSprite_setTexture(htp.button, htp.button_t, sfTrue);
    htp.position.x = 0;
    htp.position.y = 850;
    sfSprite_setPosition(htp.button, htp.position);
    htp.big_button_t =
    sfTexture_createFromFile("assets/img/big_left.png", NULL);
    htp.big_button = sfSprite_create();
    sfSprite_setTexture(htp.big_button, htp.big_button_t, sfTrue);
    sfSprite_setPosition(htp.big_button, htp.position);
    htp.state = 0;
    htp.size_h = 175;
    htp.size_l = 175;
    map->menu[4].button[0] = htp;
}

void define_start_menu4(map_t *map)
{
    button_t htp;

    htp.button_t = sfTexture_createFromFile("assets/img/howtop.png", NULL);
    htp.button = sfSprite_create();
    sfSprite_setTexture(htp.button, htp.button_t, sfTrue);
    htp.position.x = 0;
    htp.position.y = 930;
    sfSprite_setPosition(htp.button, htp.position);
    htp.big_button_t =
    sfTexture_createFromFile("assets/img/big_htp.png", NULL);
    htp.big_button = sfSprite_create();
    sfSprite_setTexture(htp.big_button, htp.big_button_t, sfTrue);
    sfSprite_setPosition(htp.big_button, htp.position);
    htp.state = 0;
    htp.size_h = 86;
    htp.size_l = 292;
    map->menu[0].button[3] = htp;
    define_htp_menu(map);
    define_start_menu5(map);
}

void define_start_menu5(map_t *map)
{
    button_t inf;

    inf.button_t = sfTexture_createFromFile("assets/img/inf_n.png", NULL);
    inf.button = sfSprite_create();
    sfSprite_setTexture(inf.button, inf.button_t, sfTrue);
    inf.position.x = 1250;
    inf.position.y = 540;
    sfSprite_setPosition(inf.button, inf.position);
    inf.big_button_t =
    sfTexture_createFromFile("assets/img/inf.png", NULL);
    inf.big_button = sfSprite_create();
    sfSprite_setTexture(inf.big_button, inf.big_button_t, sfTrue);
    sfSprite_setPosition(inf.big_button, inf.position);
    inf.state = 0;
    inf.size_h = 176;
    inf.size_l = 175;
    map->menu[0].button[4] = inf;
}