/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** move_ennemies.c
*/

#include "def.h"

int change_ennemy_way2(map_t *map, int i)
{
    if (map->ennemy[i].gps == 1 || map->ennemy[i].gps == 3
    || map->ennemy[i].gps == 5)
        if (map->ennemy[i].position.x <= map->way[map->ennemy[i].gps]) {
            map->ennemy[i].gps++;
            return (0);
        }
    if (map->ennemy[i].gps == 7)
        if (map->ennemy[i].position.x >= map->way[map->ennemy[i].gps]) {
            map->ennemy[i].gps++;
            return (0);
        }
    return (1);
}

void *change_ennemy_way(map_t *map, int i)
{
    if (map->ennemy[i].gps == 0 || map->ennemy[i].gps == 4
    || map->ennemy[i].gps == 6 || map->ennemy[i].gps == 8)
        if (map->ennemy[i].position.y >= map->way[map->ennemy[i].gps]) {
            map->ennemy[i].gps++;
            return (0);
        }
    if (map->ennemy[i].gps == 2)
        if (map->ennemy[i].position.y <= map->way[map->ennemy[i].gps]) {
            map->ennemy[i].gps++;
            return (0);
        }
    if (change_ennemy_way2(map, i) == 0)
        return (0);
    return (0);
}

void *find_ennemy_way(map_t *map, int i)
{
    int s = map->menu[1].m_state;

    if (map->ennemy[i].gps % 2 == 0) {
        if (map->ennemy[i].position.y < map->way[map->ennemy[i].gps]) {
            map->ennemy[i].position.y += (float) map->ennemy[i].speed / 10 * s;
            map->ennemy[i].rect.top = 0;
        } else {
            map->ennemy[i].position.y -= (float) map->ennemy[i].speed / 10 * s;
            map->ennemy[i].rect.top = 150;
        }
    } else {
        if (map->ennemy[i].position.x < map->way[map->ennemy[i].gps]) {
            map->ennemy[i].position.x += (float) map->ennemy[i].speed / 10 * s;
            map->ennemy[i].rect.top = 100;
        } else {
            map->ennemy[i].position.x -= (float) map->ennemy[i].speed / 10 * s;
            map->ennemy[i].rect.top = 50;
        }
    }
    return (0);
}

void *move_ennemies(map_t *map)
{
    map->clock.time_m = sfClock_getElapsedTime(map->clock.clock_m);
    map->clock.seconds_m = map->clock.time_m.microseconds / 1000000.0;
    if (map->clock.seconds_m > 0.01) {
        for (int i = 0; i != 3; i++) {
            change_ennemy_way(map, i);
            find_ennemy_way(map, i);
            sfSprite_setPosition(map->ennemy[i].sprite,
            map->ennemy[i].position);
        }
        sfClock_restart(map->clock.clock_m);
    }
    return (0);
}