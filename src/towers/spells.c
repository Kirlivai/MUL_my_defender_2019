/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** spells.c
*/

#include "def.h"

void define_spells(map_t *map)
{
    map->spell.pos.x = 0;
    map->spell.pos.y = 0;
    map->spell.state = 0;
    map->spell.sprite = sfSprite_create();
    map->spell.texture =
    sfTexture_createFromFile("assets/img/circle.png", NULL);
    sfSprite_setTexture(map->spell.sprite, map->spell.texture, sfFalse);
    sfSprite_setPosition(map->spell.sprite, map->spell.pos);
}

int display_spell(map_t *map, sfRenderWindow *win)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);

    if (map->spell.state != 1 && map->spell.state != 2)
        return (0);
    map->spell.pos.x = mouse_pos.x - 150;
    map->spell.pos.y = mouse_pos.y - 140;
    sfSprite_setPosition(map->spell.sprite, map->spell.pos);
    sfRenderWindow_drawSprite(win, map->spell.sprite, NULL);
    return (0);
}

void spell_action(map_t *map, int i)
{
    if (map->spell.state == 1) {
        map->ennemy[i].hp -= map->ennemy[i].hp_c / 3;
        sfMusic_stop(map->music.boom);
        sfMusic_play(map->music.boom);
    }
    if (map->spell.state == 2) {
        if (map->ennemy[i].speed > map->ennemy[i].speed_c / 2)
            map->ennemy[i].speed -= map->ennemy[i].speed / 2.3;
        sfMusic_stop(map->music.frozen);
        sfMusic_play(map->music.frozen);
    }
}

void throw_spell(map_t *map, sfMouseButtonEvent event)
{
    int pos_x = 0;
    int pos_y = 0;

    for (int i = 0; i != 3; i++) {
        pos_x = map->ennemy[i].position.x;
        pos_y = map->ennemy[i].position.y;
        if (event.x > pos_x - 150 && event.x < pos_x + 150
        && event.y > pos_y - 150 && event.y < pos_y + 150)
            spell_action(map, i);
    }
    map->spell.state = 0;
    map->mana -= 5;
}

int grab_spell(map_t *map, sfMouseButtonEvent event)
{
    if (map->mana < 5) {
        sfMusic_stop(map->music.error);
        sfMusic_play(map->music.error);
        return (0);
    }
    if (event.x > 1757 && event.x < 1902 && event.y > 76 && event.y < 153) {
        if (map->spell.state == 0)
            map->spell.state = 1;
        else
            map->spell.state = 0;
    }
    if (event.x > 1757 && event.x < 1902 && event.y > 185 && event.y < 331) {
        if (map->spell.state == 0)
            map->spell.state = 2;
        else
            map->spell.state = 0;
    }
    return (0);
}