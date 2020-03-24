/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** text
*/

#include "def.h"

void draw_text(map_t *m, sfRenderWindow *window)
{
    char *str_m = malloc(sizeof(char) * (2 + count_digit(m->mana)));
    char *mana = int_to_string(m->mana);

    str_m[0] = ':';
    str_m[1] = ' ';
    str_m[2] = '\0';
    str_m = my_strcat(str_m, mana);
    sfText_setString(m->text.mana, str_m);
    sfRenderWindow_drawText(window, m->text.mana, NULL);
    free(str_m);
    free(mana);
}

void draw_life_text(map_t *m, sfRenderWindow *window)
{
    char *life = NULL;
    sfVector2f pos = {0.0, 0.0};
    sfVector2f scale = {0.8, 0.8};

    for (int i = 0; i != 3; i++) {
        if (m->ennemy[i].state == 0) {
            pos = m->ennemy[i].position;
            pos.y -= 50;
            pos.x += 22;
            life = int_to_string(m->ennemy[i].hp);
            sfText_setScale(m->ennemy[i].life.mana, scale);
            sfText_setPosition(m->ennemy[i].life.mana, pos);
            sfText_setString(m->ennemy[i].life.mana, life);
            sfRenderWindow_drawText(window, m->ennemy[i].life.mana, NULL);
        }
    }
    free(life);
}

void draw_round_text(map_t *m, sfRenderWindow *window)
{
    sfVector2f pos = {1525, 975};
    char *str = malloc(sizeof(char) * (9 + count_digit(m->round) + 5));
    char *round = int_to_string(m->round);

    str = my_strcpy(str, "Round : ");
    str = my_strcat(str, round);
    str = my_strcat(str, " - 10");
    sfText_setPosition(m->text_round.mana, pos);
    sfText_setString(m->text_round.mana, str);
    sfRenderWindow_drawText(window, m->text_round.mana, NULL);
    free(str);
    free(round);
}

void draw_text_hp(map_t *m, sfRenderWindow *window)
{
    char *str_l = malloc(sizeof(char) * (7 + count_digit(m->hp)));
    char *life = int_to_string(m->hp);
    sfVector2f pos = {900, 975};

    str_l = my_strcpy(str_l, "LIFE : ");
    str_l = my_strcat(str_l, life);
    sfText_setString(m->text_hp.mana, str_l);
    sfText_setPosition(m->text_hp.mana, pos);
    sfRenderWindow_drawText(window, m->text_hp.mana, NULL);
    free(str_l);
    free(life);
}

void draw_text_score(map_t *m, sfRenderWindow *window)
{
    sfVector2f pos = {500, 875};
    char *str = malloc(sizeof(char) * (13 + count_digit(m->round) + 7));
    char *round = int_to_string(m->round);

    str = my_strcpy(str, "You survived ");
    str = my_strcat(str, round);
    str = my_strcat(str, " rounds");
    sfText_setPosition(m->text_score.mana, pos);
    sfText_setString(m->text_score.mana, str);
    sfRenderWindow_drawText(window, m->text_score.mana, NULL);
    free(str);
    free(round);
}