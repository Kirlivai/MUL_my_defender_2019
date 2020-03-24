/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** define_menus.c
*/

#include "def.h"

void define_start_menu3(map_t *map)
{
    button_t sound;

    sound.button_t = sfTexture_createFromFile("assets/img/music.png", NULL);
    sound.button = sfSprite_create();
    sfSprite_setTexture(sound.button, sound.button_t, sfTrue);
    sound.position.x = 1700;
    sound.position.y = 0;
    sfSprite_setPosition(sound.button, sound.position);
    sound.big_button_t =
    sfTexture_createFromFile("assets/img/music_n.png", NULL);
    sound.big_button = sfSprite_create();
    sfSprite_setTexture(sound.big_button, sound.big_button_t, sfTrue);
    sfSprite_setPosition(sound.big_button, sound.position);
    sound.state = 0;
    sound.size_h = 175;
    sound.size_l = 175;
    map->menu[0].button[2] = sound;
    define_start_menu4(map);
}

void define_start_menu2(map_t *map)
{
    button_t close;

    close.button_t = sfTexture_createFromFile("assets/img/close.png", NULL);
    close.button = sfSprite_create();
    sfSprite_setTexture(close.button, close.button_t, sfTrue);
    close.position.x = 0;
    close.position.y = 0;
    sfSprite_setPosition(close.button, close.position);
    close.big_button_t =
    sfTexture_createFromFile("assets/img/big_close.png", NULL);
    close.big_button = sfSprite_create();
    sfSprite_setTexture(close.big_button, close.big_button_t, sfTrue);
    sfSprite_setPosition(close.big_button, close.position);
    close.state = 0;
    close.size_h = 120;
    close.size_l = 120;
    map->menu[0].button[1] = close;
    map->menu[0].m_state = 0;
    define_start_menu3(map);
}

void define_start_menu(map_t *map)
{
    button_t start;

    start.button_t = sfTexture_createFromFile("assets/img/play.png", NULL);
    start.button = sfSprite_create();
    sfSprite_setTexture(start.button, start.button_t, sfTrue);
    start.position.x = 800;
    start.position.y = 450;
    sfSprite_setPosition(start.button, start.position);
    start.big_button_t =
    sfTexture_createFromFile("assets/img/big_play.png", NULL);
    start.big_button = sfSprite_create();
    sfSprite_setTexture(start.big_button, start.big_button_t, sfTrue);
    sfSprite_setPosition(start.big_button, start.position);
    start.size_h = 300;
    start.size_l = 300;
    start.state = 0;
    define_start_menu2(map);
    map->menu[0].button[0] = start;
}

void define_menus(map_t *map)
{
    define_start_menu(map);
    map->menu[0].texture = sfTexture_createFromFile("assets/img/bg.png", NULL);
    map->menu[0].sprite = sfSprite_create();
    map->menu[0].music = sfMusic_createFromFile("assets/sounds/title.ogg");
    sfSprite_setTexture(map->menu[0].sprite, map->menu[0].texture, sfTrue);
    define_pause_menu(map);
    define_restart_button(map);
    define_win_menu(map);
    define_lose_menu(map);
    define_quick_button(map);
}