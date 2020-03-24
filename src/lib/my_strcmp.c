/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** my_strcmp
*/

int my_strcmp(char *str_a, char *str_b)
{
    int i = 0;
    while ((str_a[i] == str_b[i]) && (str_a[i] != '\0') && (str_b[i] != '\0'))
        i++;
    return (str_a[i] - str_b[i]);
}