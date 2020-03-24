/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** display_menus.c
*/

#include "def.h"

void display_music(map_t *map, sfRenderWindow *win)
{
    if (map->menu[0].button[2].state == 0) {
        sfRenderWindow_drawSprite(win, map->menu[0].button[2].button, NULL);
        if (map->menu[0].m_state == 2)
            sfMusic_play(map->menu[0].music);
        map->menu[0].m_state = 1;
        map->music.state = 0;
    }
    else if (map->menu[0].button[2].state == 1) {
        sfRenderWindow_drawSprite(win,
        map->menu[0].button[2].big_button, NULL);
        sfMusic_pause(map->menu[0].music);
        map->menu[0].m_state = 2;
        map->music.state = 1;
    }
}

void display_close(map_t *map, sfRenderWindow *win)
{
    if (map->menu[0].button[1].state == 0)
        sfRenderWindow_drawSprite(win, map->menu[0].button[1].button, NULL);
    else if (map->menu[0].button[1].state == 1)
        sfRenderWindow_close(win);
    else
        sfRenderWindow_drawSprite(win, map->menu[0].button[1].big_button, NULL);
}

void display_start(map_t *map, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, map->menu[0].sprite, NULL);
    if (map->menu[0].button[0].state == 0)
        sfRenderWindow_drawSprite(win, map->menu[0].button[0].button, NULL);
    else if (map->menu[0].button[0].state == 1) {
        map->state = 1;
        map->menu[0].button[0].state = 0;
        sfMusic_stop(map->menu[0].music);
    }
    else
        sfRenderWindow_drawSprite(win, map->menu[0].button[0].big_button, NULL);
    if (map->menu[0].m_state == 0) {
        map->menu[0].m_state = 1;
        sfMusic_play(map->menu[0].music);
    }
}

void display_menus2(map_t *map, sfRenderWindow *win)
{
    if (map->state == 4) {
        check_click(map, win);
        display_lose_menu(map, win);
        display_restart_win(map, win);
        draw_text_score(map, win);
    }
    if (map->state == 5) {
        check_click(map, win);
        display_htp_menu(map, win);
    }
}

void display_menus(map_t *map, sfRenderWindow *win)
{
    if (map->state == 0) {
        check_click(map, win);
        display_start(map, win);
        display_close(map, win);
        display_music(map, win);
        display_htp(map, win);
        display_inf(map, win);
    }
    if (map->state == 2)
        check_click(map, win);
    if (map->state == 3) {
        check_click(map, win);
        display_win_menu(map, win);
        display_restart_win(map, win);
    }
    display_menus2(map, win);
    display_cursor(map, win);
}