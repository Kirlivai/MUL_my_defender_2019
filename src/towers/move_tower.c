/*
** EPITECH PROJECT, 2019
** defender
** File description:
** move_tower.c
*/

#include "def.h"

int check_mana(map_t *map, int nb)
{
    int cost = 0;

    if (map->tower[nb].type == 1)
        cost = 30;
    else if (map->tower[nb].type == 2)
        cost = 20;
    else
        cost = 10;
    if (map->mana - cost < 0) {
        sfMusic_stop(map->music.error);
        sfMusic_play(map->music.error);
        return (0);
    }
    return (1);
}

void *remove_mana(map_t *map, int nb)
{
    if (map->tower[nb].type == 1)
        map->mana -= 30;
    else if (map->tower[nb].type == 2)
        map->mana -= 20;
    else
        map->mana -= 10;
    return (0);
}

int put_tower(map_t *map, sfVector2i mouse_pos)
{
    int n_tower = -5;

    for (int i = 0; i != map->nb_tow; i++) {
        if (map->tower[i].state == 1)
            n_tower = i;
    }
    if (n_tower == -5 || check_mana(map, n_tower) == 0)
        return (0);
    for (int i = 0; i != 8; i++) {
        if (mouse_pos.x >= map->location_x[i] - 20
        && mouse_pos.x <= map->location_x[i] + 20
        && mouse_pos.y >= map->location_y[i] - 20
        && mouse_pos.y <= map->location_y[i] + 20) {
            map->tower[n_tower].state = 2;
            map->location_x[i] = - 500;
            map->location_y[i] = - 500;
            remove_mana(map, n_tower);
        }
    }
    return (0);
}

void *move_tower(map_t *map, sfVector2i mouse_pos, sfRenderWindow *window)
{
    sfEvent event;

    sfRenderWindow_pollEvent(window, &event);
    for (int i = 0; i < map->nb_tow; i++)
        if (map->tower[i].state == 1) {
            map->tower[i].pos.x = mouse_pos.x - 78;
            map->tower[i].pos.y = mouse_pos.y - 98;
        }
    if (event.type == sfEvtMouseButtonReleased) {
        put_tower(map, mouse_pos);
        for (int i = 0; i < map->nb_tow; i++)
            if (map->tower[i].state != 2) {
                map->tower[i].state = 0;
                map->nb_tow--;
            }
    }
    return (0);
}