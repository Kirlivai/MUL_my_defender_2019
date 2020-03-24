/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** destroy
*/

#include "def.h"

void destroy_text(map_t *map)
{
    sfText_destroy(map->text.mana);
    sfText_destroy(map->text_hp.mana);
    sfText_destroy(map->text_round.mana);
}

void destroy_all(map_t *map)
{
    destroy_sprite(map, 3, map->nb_tow);
    sfClock_destroy(map->clock.clock_m);
    sfClock_destroy(map->clock.clock_r);
    destroy_text(map);
    sfMusic_destroy(map->music.music);
    sfMusic_destroy(map->music.error);
    sfMusic_destroy(map->music.click);
    sfMusic_destroy(map->music.death);
    sfMusic_destroy(map->music.boom);
    sfMusic_destroy(map->music.frozen);
    sfMusic_destroy(map->menu[0].music);
    sfMusic_destroy(map->menu[2].music);
    sfMusic_destroy(map->menu[3].music);
}

void destroy_sprite(map_t *map, int nb_e, int nb_t)
{
    for (int i = 0; i != nb_e; i++) {
        sfSprite_destroy(map->ennemy[i].sprite);
        sfTexture_destroy(map->ennemy[i].texture);
    }
    for (int i = 0; i != nb_t; i++) {
        sfSprite_destroy(map->tower[i].sprite);
        sfTexture_destroy(map->tower[i].texture);
    }
    sfSprite_destroy(map->sprite);
    sfTexture_destroy(map->texture);
}