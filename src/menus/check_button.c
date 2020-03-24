/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** check_button.c
*/

#include "def.h"

void check_mouse_on(map_t *map, sfVector2i mouse, int m, int b)
{
    int size_y = map->menu[m].button[b].size_h;
    int size_x = map->menu[m].button[b].size_l;

    if (mouse.x > map->menu[m].button[b].position.x
    && mouse.x < map->menu[m].button[b].position.x + size_x
    && mouse.y > map->menu[m].button[b].position.y
    && mouse.y < map->menu[m].button[b].position.y + size_y)
        map->menu[m].button[b].state = 2;
    else
        map->menu[m].button[b].state = 0;
}

void check_click_pos(map_t *map, sfMouseButtonEvent event, int m, int b)
{
    int size_x = map->menu[m].button[b].size_l;
    int size_y = map->menu[m].button[b].size_h;

    if (event.x > map->menu[m].button[b].position.x
    && event.x < map->menu[m].button[b].position.x + size_x
    && event.y > map->menu[m].button[b].position.y
    && event.y < map->menu[m].button[b].position.y + size_y) {
        map->menu[m].button[b].state = 1;
        sfMusic_stop(map->music.click);
        sfMusic_play(map->music.click);
    }
}

void check_click_sound(map_t *map, sfMouseButtonEvent event, int m, int b)
{
    int size_y = map->menu[m].button[b].size_h;
    int size_x = map->menu[m].button[b].size_l;

    if (event.x > map->menu[m].button[b].position.x
    && event.x < map->menu[m].button[b].position.x + size_x
    && event.y > map->menu[m].button[b].position.y
    && event.y < map->menu[m].button[b].position.y + size_y) {
        if (map->menu[m].button[b].state == 1)
            map->menu[m].button[b].state = 0;
        else
            map->menu[m].button[b].state = 1;
        sfMusic_stop(map->music.click);
        sfMusic_play(map->music.click);
    }
}

void check_click(map_t *map, sfRenderWindow *win)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);
    sfKeyCode esc = sfKeyEscape;

    while (sfRenderWindow_pollEvent(win, &event) == sfTrue) {
        if (event.type == sfEvtMouseButtonPressed)
            check_click_state(map, event.mouseButton);
        else {
            check_pos_state(map, mouse_pos);
        }
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (sfKeyboard_isKeyPressed(esc) == sfTrue && map->state == 2)
            map->state = 1;
    }
}