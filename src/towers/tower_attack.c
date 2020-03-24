/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower_attack.c
*/

#include "def.h"

void *check_range(map_t *map, int i)
{
    int xma = map->tower[i].pos.x + 300;
    int xmi = map->tower[i].pos.x - 300;
    int yma = map->tower[i].pos.y + 300;
    int ymi = map->tower[i].pos.y - 230;

    for (int j = 0; j != 3; j++)
        if (map->ennemy[j].position.x > xmi && map->ennemy[j].position.x < xma
        && map->ennemy[j].position.y < yma && map->ennemy[j].position.y > ymi) {
            map->ennemy[j].hp -= map->tower[i].damage;
            if (map->tower[i].type == 1
            && map->ennemy[j].speed > map->ennemy[j].speed / 2 + 3)
                map->ennemy[j].speed -= 1;
        }
    return (0);
}

void *tower_attack(map_t *map)
{
    map->clock.time_t = sfClock_getElapsedTime(map->clock.clock_t);
    map->clock.seconds_t = map->clock.time_t.microseconds / 1000000.0;
    if (map->clock.seconds_t > (2.3 / map->menu[1].m_state)) {
        for (int i = 0; i != map->nb_tow; i++)
            if (map->tower[i].state == 2)
                check_range(map, i);
        sfClock_restart(map->clock.clock_t);
    }
    return (0);
}