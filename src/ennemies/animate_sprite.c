/*
** EPITECH PROJECT, 2019
** MUL_200
** File description:
** animate_sprite.c
*/

#include "def.h"

void *anim_sprite(map_t *map)
{
    if (map->state == 2)
        return (0);
    map->clock.time = sfClock_getElapsedTime(map->clock.clock_r);
    map->clock.seconds = map->clock.time.microseconds / 1000000.0;
    if (map->clock.seconds > 0.3) {
        for (int i = 0; i != 3; i++)
            if (map->ennemy[i].rect.left + 50 <= 145)
                map->ennemy[i].rect.left += 49;
            else
                map->ennemy[i].rect.left = 0;
        sfClock_restart(map->clock.clock_r);
    }
    for (int i = 0; i != 3; i++)
        sfSprite_setTextureRect(map->ennemy[i].sprite, map->ennemy[i].rect);
    return (0);
}