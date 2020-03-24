/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** enemies_dmg.c
*/

#include "def.h"

void enemies_dmg(map_t *map)
{
    for (int i = 0; i != 3; i++)
        if (map->ennemy[i].hp <= 0) {
            if (map->ennemy[i].state == 0) {
                sfMusic_stop(map->music.death);
                sfMusic_play(map->music.death);
                map->mana += 5;
            }
            map->ennemy[i].state = 1;
        }
}