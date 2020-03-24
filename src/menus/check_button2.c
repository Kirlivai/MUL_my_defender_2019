/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** check_button2.c
*/

#include "def.h"

void check_pos_state(map_t *map, sfVector2i mouse_pos)
{
    if (map->state == 0) {
        check_mouse_on(map, mouse_pos, 0, 0);
        check_mouse_on(map, mouse_pos, 0, 1);
        check_mouse_on(map, mouse_pos, 0, 3);
    }
    if (map->state == 2) {
        check_mouse_on(map, mouse_pos, 1, 0);
        check_mouse_on(map, mouse_pos, 1, 1);
        check_mouse_on(map, mouse_pos, 1, 2);
        check_mouse_on(map, mouse_pos, 1, 3);
    }
    if (map->state == 3 || map->state == 4) {
        check_mouse_on(map, mouse_pos, 2, 0);
        check_mouse_on(map, mouse_pos, 2, 1);
    }
    if (map->state == 5)
        check_mouse_on(map, mouse_pos, 4, 0);
}

void check_click_state(map_t *map, sfMouseButtonEvent mouse)
{
    if (map->state == 0) {
        check_click_pos(map, mouse, 0, 0);
        check_click_pos(map, mouse, 0, 1);
        check_click_sound(map, mouse, 0, 2);
        check_click_pos(map, mouse, 0, 3);
        check_click_sound(map, mouse, 0, 4);

    }
    if (map->state == 2) {
        check_click_pos(map, mouse, 1, 0);
        check_click_pos(map, mouse, 1, 1);
        check_click_pos(map, mouse, 1, 2);
        check_click_pos(map, mouse, 1, 3);
    }
    if (map->state == 3 || map->state == 4) {
        check_click_pos(map, mouse, 2, 0);
        check_click_pos(map, mouse, 2, 1);
    }
    if (map->state == 5)
        check_click_pos(map, mouse, 4, 0);
}