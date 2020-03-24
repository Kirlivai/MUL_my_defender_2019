/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** define_text
*/

#include "def.h"

text_t initialization_text_score(void)
{
    text_t text_score;
    sfVector2f scale = {2, 2};

    text_score.font = sfFont_createFromFile("assets/ka1.ttf");
    text_score.mana = sfText_create();
    sfText_setFont(text_score.mana, text_score.font);
    sfText_setScale(text_score.mana, scale);
    return (text_score);
}