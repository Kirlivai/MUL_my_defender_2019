/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** pause_menu2.c
*/

#include "def.h"

void display_pause_restart(map_t *map, sfRenderWindow *win)
{
    if (map->menu[1].button[2].state == 0)
        sfRenderWindow_drawSprite(win, map->menu[1].button[2].button, NULL);
    else if (map->menu[1].button[2].state == 1) {
        map->menu[1].button[2].state = 0;
        restart_game(map);
    }
    else
        sfRenderWindow_drawSprite(win, map->menu[1].button[2].big_button, NULL);
}

void display_quick(map_t *map, sfRenderWindow *win)
{
    if (map->menu[1].button[3].state == 0)
        sfRenderWindow_drawSprite(win, map->menu[1].button[3].button, NULL);
    else if (map->menu[1].button[3].state == 1) {
        map->menu[1].button[3].state = 0;
        map->menu[1].m_state = (map->menu[1].m_state == 1) ? 3 : 1;
    }
    else
        sfRenderWindow_drawSprite(win, map->menu[1].button[3].big_button, NULL);
}

void define_restart_button(map_t *map)
{
    button_t resume;

    resume.button_t = sfTexture_createFromFile("assets/img/restart.png", NULL);
    resume.button = sfSprite_create();
    sfSprite_setTexture(resume.button, resume.button_t, sfTrue);
    resume.position.x = 515;
    resume.position.y = 625;
    sfSprite_setPosition(resume.button, resume.position);
    resume.big_button_t =
    sfTexture_createFromFile("assets/img/big_restart.png", NULL);
    resume.big_button = sfSprite_create();
    sfSprite_setTexture(resume.big_button, resume.big_button_t, sfTrue);
    sfSprite_setPosition(resume.big_button, resume.position);
    resume.size_h = 176;
    resume.size_l = 175;
    resume.state = 0;
    map->menu[1].button[2] = resume;
    map->menu[1].m_state = 1;
}

void define_quick_button(map_t *map)
{
    button_t resume;

    resume.button_t = sfTexture_createFromFile("assets/img/quick.png", NULL);
    resume.button = sfSprite_create();
    sfSprite_setTexture(resume.button, resume.button_t, sfTrue);
    resume.position.x = 1276;
    resume.position.y = 625;
    sfSprite_setPosition(resume.button, resume.position);
    resume.big_button_t =
    sfTexture_createFromFile("assets/img/big_quick.png", NULL);
    resume.big_button = sfSprite_create();
    sfSprite_setTexture(resume.big_button, resume.big_button_t, sfTrue);
    sfSprite_setPosition(resume.big_button, resume.position);
    resume.size_h = 176;
    resume.size_l = 175;
    resume.state = 0;
    map->menu[1].button[3] = resume;
}