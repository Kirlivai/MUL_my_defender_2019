/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_menus2
*/

#include "def.h"

void display_inf(map_t *map, sfRenderWindow *win)
{
    if (map->menu[0].button[4].state == 0) {
        sfRenderWindow_drawSprite(win, map->menu[0].button[4].button, NULL);
    }
    else if (map->menu[0].button[4].state == 1) {
        sfRenderWindow_drawSprite(win,
        map->menu[0].button[4].big_button, NULL);
    }
}