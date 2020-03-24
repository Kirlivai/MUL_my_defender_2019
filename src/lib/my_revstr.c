/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Project
*/

int my_len(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int a;
    char reverse;
    int b;

    a = 0;
    b = my_len(str) - 1;
    while (a < b) {
        reverse = str[a];
        str[a] = str[b];
        str[b] = reverse;
        a++;
        b--;
    }
    return (str);
}
