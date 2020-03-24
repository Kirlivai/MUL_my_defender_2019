/*
** EPITECH PROJECT, 2019
** defender
** File description:
** define_map.c
*/

#include "def.h"

text_t initialization_text(void)
{
    text_t text;
    sfVector2f mana_pos = {980, 37};

    text.font = sfFont_createFromFile("assets/MGS2MENU.TTF");
    text.mana = sfText_create();
    sfText_setFont(text.mana, text.font);
    sfText_setPosition(text.mana, mana_pos);
    return (text);
}

text_t initialization_text_life(void)
{
    text_t text;

    text.font = sfFont_createFromFile("assets/ka1.ttf");
    text.mana = sfText_create();
    sfText_setFont(text.mana, text.font);
    return (text);
}

music_t initialization_music(void)
{
    music_t music;
    music.music = sfMusic_createFromFile("assets/sounds/fire_music.ogg");
    music.error = sfMusic_createFromFile("assets/sounds/error.ogg");
    music.click = sfMusic_createFromFile("assets/sounds/click.ogg");
    music.death = sfMusic_createFromFile("assets/sounds/death.ogg");
    music.frozen = sfMusic_createFromFile("assets/sounds/frozen.ogg");
    music.boom = sfMusic_createFromFile("assets/sounds/boom.ogg");
    return (music);
}

void define_map2(map_t *map)
{
    map->music = initialization_music();
    map->text = initialization_text();
    map->text_round = initialization_text_life();
    map->text_hp = initialization_text_life();
    map->text_score = initialization_text_score();
    map->music.state = 0;
    map->nb_tow = 0;
    map->mana = 15;
    map->hp = 3;
    map->state = 0;
    map->round = 1;
    define_menus(map);
    define_cursor(map);
}

void *define_map(map_t *map)
{
    int pos_x[8] = {278, 357, 300, 1259, 1259, 1631, 1440, 783};
    int pos_y[8] = {352, 665, 982, 258, 594, 590, 905, 302};
    int way[9] = {715, 1070, 175, 440, 460, 155, 830, 420, 1020};

    map->texture = sfTexture_createFromFile("assets/img/map2.png", NULL);
    map->sprite = sfSprite_create();
    sfSprite_setTexture(map->sprite, map->texture, sfFalse);
    define_map2(map);
    for (int i = 0; i != 9; i++)
        map->way[i] = way[i];
    for (int i = 0; i != 8; i++) {
        map->location_x[i] = pos_x[i];
        map->location_y[i] = pos_y[i];
    }
    define_ennemies(map);
    define_spells(map);
    return (0);
}

