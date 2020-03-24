/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** round.c
*/

#include "def.h"

void enemies_attack(map_t *map)
{
    for (int i = 0; i != 3; i++)
        if (map->ennemy[i].position.x > 398 && map->ennemy[i].position.x < 552
        && map->ennemy[i].position.y > 975 && map->ennemy[i].state == 0) {
            map->ennemy[i].state = 1;
            map->hp -= 1;
        }
}

int next_round(map_t *map)
{
    sfVector2f pos = {1400, 135};

    for (int i = 0; i != 3; i++)
        if (map->ennemy[i].state == 0)
            return (0);
    for (int i = 0; i != 3; i++) {
        map->ennemy[i].hp_c += map->ennemy[i].hp_c / 2.5;
        map->ennemy[i].hp =  map->ennemy[i].hp_c;
        map->ennemy[i].speed =  map->ennemy[i].speed_c;
        map->ennemy[i].position = pos;
        map->ennemy[i].state = 0;
        map->ennemy[i].gps = 0;
    }
    map->round++;
    return (0);
}