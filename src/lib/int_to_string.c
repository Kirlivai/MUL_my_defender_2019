/*
** EPITECH PROJECT, 2019
** int_to_string.c
** File description:
** int_to_string
*/

#include <stdlib.h>

char *my_revstr(char *str);

int count_digit(int nb)
{
    int i = 1;
    if (nb < 0) {
        nb = -nb;
    }
    while (nb >= 10) {
        nb /= 10;
        i++;
    }
    return (i);
}

char *int_to_string(int nb)
{
    char *str = malloc(sizeof(char) * (count_digit(nb) + 1));
    int rest = 0;
    int i = 0;

    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    for (; nb != 0; i++) {
        rest = nb % 10;
        str[i] = rest + '0';
        nb = nb / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}