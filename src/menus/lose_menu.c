/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** lose_menu
*/

#include "def.h"

void display_lose_menu(map_t *map, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, map->menu[3].sprite, NULL);
    if (map->menu[2].button[0].state == 0)
        sfRenderWindow_drawSprite(win, map->menu[2].button[0].button, NULL);
    else if (map->menu[2].button[0].state == 1)
        sfRenderWindow_close(win);
    else
        sfRenderWindow_drawSprite(win, map->menu[2].button[0].big_button, NULL);
}

void define_lose_menu(map_t *map)
{
    map->menu[3].texture =
    sfTexture_createFromFile("assets/img/lose.jpg", NULL);
    map->menu[3].sprite = sfSprite_create();
    sfSprite_setTexture(map->menu[3].sprite, map->menu[3].texture, sfTrue);
    map->menu[3].music =
    sfMusic_createFromFile("assets/sounds/game_over.ogg");
}