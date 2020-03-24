/*
** EPITECH PROJECT, 2019
** defender
** File description:
** add_tower.c
*/

#include "def.h"

void add_tower2(tower_t *tower, sfMouseButtonEvent event)
{
    tower->pos.x = event.x - 78;
    tower->pos.y = event.y - 98;
    tower->sprite = sfSprite_create();
    tower->state = 1;
}

void add_tower(map_t *map, int a, sfMouseButtonEvent event)
{
    tower_t tower;

    add_tower2(&tower, event);
    if (a == 1) {
        tower.damage = 7;
        tower.type = 1;
        tower.texture = sfTexture_createFromFile("assets/img/tower3.png", NULL);
    }
    else if (a == 2) {
        tower.damage = 7;
        tower.type = 2;
        tower.texture = sfTexture_createFromFile("assets/img/tower2.png", NULL);
    } else {
        tower.damage = 3;
        tower.type = 3;
        tower.texture = sfTexture_createFromFile("assets/img/tower1.png", NULL);
    }
    sfSprite_setTexture(tower.sprite, tower.texture, sfFalse);
    map->tower[map->nb_tow] = tower;
    map->nb_tow++;
}