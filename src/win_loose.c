/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** win_loose.c
*/

#include "def.h"

void win_loose(map_t *map)
{
    if (map->hp <= 0) {
        sfMusic_stop(map->music.music);
        if (map->menu[0].button[2].state != 1)
            sfMusic_play(map->menu[3].music);
        map->state = 4;
    }
    if (map->round > 10 && map->menu[0].button[4].state != 1) {
        sfMusic_stop(map->music.music);
        if (map->menu[0].button[2].state != 1)
            sfMusic_play(map->menu[2].music);
        map->state = 3;
    }
}