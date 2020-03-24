/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** pause_menu.c
*/

#include "def.h"

void define_pause_menu2(map_t *map)
{
    button_t resume;

    map->menu[1].texture =
    sfTexture_createFromFile("assets/img/table.png", NULL);
    map->menu[1].sprite = sfSprite_create();

    resume.button_t = sfTexture_createFromFile("assets/img/exit.png", NULL);
    resume.button = sfSprite_create();
    sfSprite_setTexture(resume.button, resume.button_t, sfTrue);
    resume.position.x = 770;
    resume.position.y = 550;
    sfSprite_setPosition(resume.button, resume.position);
    resume.big_button_t =
    sfTexture_createFromFile("assets/img/big_exit.png", NULL);
    resume.big_button = sfSprite_create();
    sfSprite_setTexture(resume.big_button, resume.big_button_t, sfTrue);
    sfSprite_setPosition(resume.big_button, resume.position);
    resume.size_h = 150;
    resume.size_l = 421;
    resume.state = 0;
    map->menu[1].button[1] = resume;
}

void define_pause_menu(map_t *map)
{
    button_t resume;
    sfVector2f position = {500, 200};

    resume.button_t = sfTexture_createFromFile("assets/img/resume.png", NULL);
    resume.button = sfSprite_create();
    sfSprite_setTexture(resume.button, resume.button_t, sfTrue);
    resume.position.x = 770;
    resume.position.y = 300;
    sfSprite_setPosition(resume.button, resume.position);
    resume.big_button_t =
    sfTexture_createFromFile("assets/img/big_resume.png", NULL);
    resume.big_button = sfSprite_create();
    sfSprite_setTexture(resume.big_button, resume.big_button_t, sfTrue);
    sfSprite_setPosition(resume.big_button, resume.position);
    resume.size_h = 150;
    resume.size_l = 421;
    resume.state = 0;
    map->menu[1].button[0] = resume;
    define_pause_menu2(map);
    sfSprite_setTexture(map->menu[1].sprite, map->menu[1].texture, sfTrue);
    sfSprite_setPosition(map->menu[1].sprite, position);
}

void display_resume(map_t *map, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, map->menu[1].sprite, NULL);
    if (map->menu[1].button[0].state == 0)
        sfRenderWindow_drawSprite(win, map->menu[1].button[0].button, NULL);
    else if (map->menu[1].button[0].state == 1) {
        map->menu[1].button[0].state = 0;
        map->state = 1;
    }
    else
        sfRenderWindow_drawSprite(win, map->menu[1].button[0].big_button, NULL);
}

void display_exit(map_t *map, sfRenderWindow *win)
{
    if (map->menu[1].button[1].state == 0)
        sfRenderWindow_drawSprite(win, map->menu[1].button[1].button, NULL);
    else if (map->menu[1].button[1].state == 1) {
        sfRenderWindow_close(win);
    }
    else
        sfRenderWindow_drawSprite(win, map->menu[1].button[1].big_button, NULL);
}

void pause_menu(map_t *map, sfRenderWindow *win)
{
    if (map->state == 2) {
        sfClock_restart(map->clock.clock_t);
        display_resume(map, win);
        display_exit(map, win);
        display_pause_restart(map, win);
        display_quick(map, win);
        check_click(map, win);
    }
    display_cursor(map, win);
}