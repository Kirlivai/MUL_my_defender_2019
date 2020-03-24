/*
** EPITECH PROJECT, 2019
** defender
** File description:
** define_ennemies.c
*/

#include "def.h"

void create_koopa(map_t *map)
{
    ennemy_t koopa;
    sfVector2f pos = {1400, 135};
    sfIntRect rect = {0, 0, 45, 47};
    sfVector2f scale = {2, 2};

    koopa.texture = sfTexture_createFromFile("assets/img/koppa_b.png", NULL);
    koopa.sprite = sfSprite_create();
    sfSprite_setTexture(koopa.sprite, koopa.texture, sfTrue);
    koopa.position = pos;
    sfSprite_setPosition(koopa.sprite, pos);
    koopa.rect = rect;
    sfSprite_setTextureRect(koopa.sprite, rect);
    sfSprite_setScale(koopa.sprite, scale);
    koopa.hp = 15;
    koopa.hp_c = 15;
    koopa.speed = 14;
    koopa.speed_c = 14;
    koopa.gps = 0;
    koopa.state = 0;
    koopa.life = initialization_text_life();
    map->ennemy[0] = koopa;
}

void create_knight(map_t *map)
{
    ennemy_t knight;
    sfVector2f pos = {1400, 134};
    sfIntRect rect = {0, 0, 45, 50};
    sfVector2f scale = {2, 2};

    knight.texture = sfTexture_createFromFile("assets/img/knight.png", NULL);
    knight.sprite = sfSprite_create();
    sfSprite_setTexture(knight.sprite, knight.texture, sfTrue);
    knight.position = pos;
    sfSprite_setPosition(knight.sprite, pos);
    knight.rect = rect;
    sfSprite_setTextureRect(knight.sprite, knight.rect);
    sfSprite_setScale(knight.sprite, scale);
    knight.hp = 30;
    knight.hp_c = 30;
    knight.speed = 9;
    knight.speed_c = 9;
    knight.gps = 0;
    knight.state = 0;
    knight.life = initialization_text_life();
    map->ennemy[1] = knight;
}

void create_witch(map_t *map)
{
    ennemy_t witch;
    sfVector2f pos = {1400, 135};
    sfIntRect rect = {0, 0, 45, 47};
    sfVector2f scale = {2, 2};

    witch.texture = sfTexture_createFromFile("assets/img/witch.png", NULL);
    witch.sprite = sfSprite_create();
    sfSprite_setTexture(witch.sprite, witch.texture, sfTrue);
    witch.position = pos;
    sfSprite_setPosition(witch.sprite, pos);
    witch.rect = rect;
    sfSprite_setTextureRect(witch.sprite, witch.rect);
    sfSprite_setScale(witch.sprite, scale);
    witch.hp = 15;
    witch.hp_c = 15;
    witch.speed = 20;
    witch.speed_c = 20;
    witch.gps = 0;
    witch.state = 0;
    witch.life = initialization_text_life();
    map->ennemy[2] = witch;
}

void *define_ennemies(map_t *map)
{
    map->clock.clock_r = sfClock_create();
    map->clock.clock_m = sfClock_create();
    map->clock.clock_t = sfClock_create();
    create_koopa(map);
    create_knight(map);
    create_witch(map);
    return (0);
}