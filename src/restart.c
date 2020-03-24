/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** restart.c
*/

#include "def.h"

void restart_game2(map_t *map)
{
    int pos_x[8] = {278, 357, 300, 1259, 1259, 1631, 1440, 783};
    int pos_y[8] = {352, 665, 982, 258, 594, 590, 905, 302};

    map->round = 1;
    map->ennemy[0].hp = 15;
    map->ennemy[0].hp_c = 15;
    map->ennemy[1].hp = 30;
    map->ennemy[1].hp_c = 30;
    map->ennemy[2].hp = 15;
    map->ennemy[2].hp_c = 15;
    map->nb_tow = 0;
    map->mana = 15;
    map->hp = 3;
    map->menu[1].m_state = 1;
    for (int i = 0; i != 8; i++) {
        map->location_x[i] = pos_x[i];
        map->location_y[i] = pos_y[i];
    }
}

void restart_game(map_t *map)
{
    sfVector2f pos = {1400, 135};

    map->state = 0;
    for (int i = 0; i != 3; i++) {
        map->ennemy[i].speed =  map->ennemy[i].speed_c;
        map->ennemy[i].position = pos;
        map->ennemy[i].state = 0;
        map->ennemy[i].gps = 0;
    }
    restart_game2(map);
    sfMusic_stop(map->menu[2].music);
    sfMusic_stop(map->menu[3].music);
    sfMusic_stop(map->music.music);
    sfMusic_play(map->menu[0].music);
}