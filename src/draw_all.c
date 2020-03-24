/*
** EPITECH PROJECT, 2019
** defender
** File description:
** draw_all.c
*/

#include "def.h"

void draw_ennemies(map_t *map, sfRenderWindow *window)
{
    for (int i = 0; i != 3; i++)
        if (map->ennemy[i].state == 0)
            sfRenderWindow_drawSprite(window, map->ennemy[i].sprite, NULL);
    anim_sprite(map);
}

void draw_towers(map_t *map, sfRenderWindow *window)
{
    for (int i = 0; i != map->nb_tow; i++)
        if (map->tower[i].state != 0) {
            sfRenderWindow_drawSprite(window, map->tower[i].sprite, NULL);
            sfSprite_setPosition(map->tower[i].sprite, map->tower[i].pos);
        }
}

void do_all(map_t *map)
{
    if (map->state == 1) {
        move_ennemies(map);
        tower_attack(map);
        enemies_dmg(map);
        enemies_attack(map);
    }
}

void *draw_all(map_t *map, sfRenderWindow *window)
{
    if (map->music.state == 0) {
        sfMusic_play(map->music.music);
        sfMusic_setLoop(map->music.music, sfTrue);
        map->music.state = 1;
    }
    sfRenderWindow_drawSprite(window, map->sprite, NULL);
    draw_round_text(map, window);
    draw_text_hp(map, window);
    draw_text(map, window);
    draw_ennemies(map, window);
    draw_life_text(map, window);
    draw_towers(map, window);
    next_round(map);
    display_spell(map, window);
    display_cursor(map, window);
    return (0);
}
