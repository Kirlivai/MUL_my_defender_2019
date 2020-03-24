/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my_runner main
*/

#include "def.h"

int display_desc(int ac, char **av)
{
    if (ac == 2)
        if (my_strcmp(av[1], "-h") == 0) {
            write(1, "USAGE\n\t./my_defender\n" , 21);
            write(1, "OPTIONS\n\t-h\tprint the usage and quit\n", 37);
            write(1, "USER INTERACTIONS\n\tESCAPE_KEY", 29);
            write(1, "\tPause during the party\n", 24);
            write(1, "\tMOUSE\tInteract with the game\n", 30);
            return (0);
        }
    return (1);
}

int main(int ac, char **av, char **env)
{
    screen_t screen;
    map_t map;

    if (display_desc(ac, av) == 0)
        return (0);
    if (!env || !env[0])
        return (84);
    screen = define_screen(screen);
    define_map(&map);
    while (sfRenderWindow_isOpen(screen.window)) {
        sfRenderWindow_display(screen.window);
        if (map.state == 1 || map.state == 2) {
            draw_all(&map, screen.window);
            do_all(&map);
            pause_menu(&map, screen.window);
            win_loose(&map);
            analyse(screen.window, &map);
        } else
            display_menus(&map, screen.window);
    }
    destroy_all(&map);
}