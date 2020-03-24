/*
** EPITECH PROJECT, 2019
** event.c
** File description:
** events of the game
*/

#include "def.h"

int change_tower(map_t *map, int i)
{
    if (map->mana < 10 || map->tower[i].type == 1) {
        sfMusic_stop(map->music.error);
        sfMusic_play(map->music.error);
        return (0);
    }
    map->tower[i].type -= 1;
    if (map->tower[i].type == 2) {
        map->tower[i].damage = 7;
        map->tower[i].type = 2;
        map->tower[i].texture =
        sfTexture_createFromFile("assets/img/tower2.png", NULL);
    } else {
        map->tower[i].damage = 7;
        map->tower[i].type = 1;
        map->tower[i].texture =
        sfTexture_createFromFile("assets/img/tower3.png", NULL);
    }
    sfSprite_setTexture(map->tower[i].sprite, map->tower[i].texture, sfFalse);
    map->mana -= 10;
    return (0);
}

int upgrade_towers(map_t *map, sfMouseButtonEvent event)
{
    int posx = 0;
    int posy = 0;

    for (int i = 0; i != map->nb_tow; i++) {
        posx = map->tower[i].pos.x;
        posy = map->tower[i].pos.y;
        if (event.x > posx - 150 && event.x < posx + 150
        && event.y > posy - 150 && event.y < posy + 150
        && map->tower[i].state == 2)
            change_tower(map, i);
    }
    return (0);
}

int manage_mouse_click(sfMouseButtonEvent event, map_t *map)
{
    if (map->spell.state != 0) {
        throw_spell(map, event);
        return (0);
    }
    if (map->nb_tow < 8) {
        if (event.x < 171 && event. y < 171)
            add_tower(map, 1, event);
        if (event.x > 205 && event.x < 333 && event.y < 171)
            add_tower(map, 2, event);
        if (event.x > 380 && event.x < 534 && event.y < 171)
            add_tower(map, 3, event);
    }
    upgrade_towers(map, event);
    grab_spell(map, event);
    return (0);
}

int analyse(sfRenderWindow *window, map_t *map)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfKeyCode esc = sfKeyEscape;

    while (sfRenderWindow_pollEvent(window, &event) == sfTrue) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (map->state == 1) {
            if (event.type == sfEvtMouseButtonPressed)
                manage_mouse_click(event.mouseButton, map);
            move_tower(map, mouse_pos, window);
        }
        if (sfKeyboard_isKeyPressed(esc) == sfTrue && map->state == 1)
            map->state = 2;
    }
    return (0);
}
