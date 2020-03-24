/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** cursor.c
*/

#include "def.h"

void display_cursor(map_t *map, sfRenderWindow *win)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);

    map->spell.pos_c.x = mouse.x - 27;
    map->spell.pos_c.y = mouse.y - 18;
    sfSprite_setPosition(map->spell.sprite_c, map->spell.pos_c);
    sfRenderWindow_drawSprite(win, map->spell.sprite_c, NULL);
}

void define_cursor(map_t *map)
{
    map->spell.sprite_c = sfSprite_create();
    map->spell.pos_c.x = 0;
    map->spell.pos_c.x = 0;
    map->spell.texture_c =
    sfTexture_createFromFile("assets/img/cursor.png", NULL);
    sfSprite_setTexture(map->spell.sprite_c, map->spell.texture_c, sfFalse);
    sfSprite_setPosition(map->spell.sprite_c, map->spell.pos_c);
}