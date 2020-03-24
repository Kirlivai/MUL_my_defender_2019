/*
** EPITECH PROJECT, 2019
** my_runner .h
** File description:
** .h
*/

#ifndef MY_H
#define MY_H

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window/Event.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct screen_t screen_t;
struct screen_t
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
};

typedef struct text
{
    sfFont *font;
    sfText *mana;
} text_t;

typedef struct music
{
    sfMusic* music;
    sfMusic* error;
    sfMusic* click;
    sfMusic* death;
    sfMusic* boom;
    sfMusic* frozen;
    int state;
} music_t;

typedef struct ennemy_t ennemy_t;
struct ennemy_t
{
    sfSprite *sprite;
    sfTexture *texture;
    text_t life;
    sfVector2f position;
    sfIntRect rect;
    int hp;
    int hp_c;
    int speed;
    int speed_c;
    int gps;
    int state;
};

typedef struct clockg_t clockg_t;
struct clockg_t
{
    sfTime time;
    float seconds;
    sfClock *clock_r;
    sfTime time_m;
    float seconds_m;
    sfClock *clock_m;
    sfTime time_t;
    float seconds_t;
    sfClock *clock_t;
};

typedef struct tower_t tower_t;
struct tower_t
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int damage;
    int state;
    int type;
};

typedef struct button_t button_t;
struct button_t
{
    sfTexture *button_t;
    sfSprite *button;
    sfTexture *big_button_t;
    sfSprite *big_button;
    sfVector2f position;
    int state;
    int size_h;
    int size_l;
};

typedef struct menu_t menu_t;
struct menu_t
{
    sfTexture *texture;
    sfSprite *sprite;
    sfMusic* music;
    int m_state;
    button_t button[5];
};

typedef struct spell_t spell_t;
struct spell_t
{
    sfTexture *texture;
    sfSprite *sprite;
    int state;
    sfVector2f pos;
    sfTexture *texture_c;
    sfSprite *sprite_c;
    sfVector2f pos_c;
};

typedef struct map_t map_t;
struct map_t
{
    text_t text;
    text_t text_round;
    text_t text_hp;
    text_t text_score;
    music_t music;
    sfTexture *texture;
    sfSprite *sprite;
    int way[9];
    int mana;
    tower_t tower[8];
    ennemy_t ennemy[3];
    spell_t spell;
    menu_t menu[6];
    clockg_t clock;
    int nb_tow;
    int location_x[8];
    int location_y[8];
    int round;
    int hp;
    int state;
};

//lib
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char *str_a, char *str_b);
char *my_revstr(char *str);
char *int_to_string(int nb);
int count_digit(int nb);

// Check user input:
int analyse(sfRenderWindow *window, map_t *map);
void check_click(map_t *map, sfRenderWindow *win);
void check_pos_state(map_t *map, sfVector2i mouse_pos);
void check_click_state(map_t *map, sfMouseButtonEvent mouse);
void check_mouse_on(map_t *map, sfVector2i mouse, int m, int b);
void check_click_pos(map_t *map, sfMouseButtonEvent event, int m, int b);
void check_click_sound(map_t *map, sfMouseButtonEvent event, int m, int b);

// Define structures:
screen_t define_screen(screen_t screen);
void *define_map(map_t *map);
void *define_ennemies(map_t *map);
void define_menus(map_t *map);
void define_pause_menu(map_t *map);
void define_start_menu4(map_t *map);
void define_start_menu5(map_t *map);
void define_win_menu(map_t *map);
void define_win_menu2(map_t *map);
void display_win_menu(map_t *map, sfRenderWindow *win);
void define_start_menu2(map_t *map);
void define_restart_button(map_t *map);
void define_lose_menu(map_t *map);
void define_quick_button(map_t *map);
void define_spells(map_t *map);
void define_cursor(map_t *map);

// Towers:
void add_tower(map_t *map, int a, sfMouseButtonEvent event);
void *move_tower(map_t *map, sfVector2i mouse_pos, sfRenderWindow *window);
void *tower_attack(map_t *map);

// Text:
void draw_text(map_t *m, sfRenderWindow *window);
void draw_text_gm(map_t m);
text_t initialization_text_life(void);
void draw_life_text(map_t *m, sfRenderWindow *window);
void draw_round_text(map_t *m, sfRenderWindow *window);
void draw_text_hp(map_t *m, sfRenderWindow *window);
void draw_text_score(map_t *m, sfRenderWindow *window);
text_t initialization_text_score(void);

// Main loop:
void *draw_all(map_t *map, sfRenderWindow *window);
void do_all(map_t *map);
void *anim_sprite(map_t *map);
void *move_ennemies(map_t *map);
void enemies_dmg(map_t *map);
int next_round(map_t *map);
void enemies_attack(map_t *map);
void win_loose(map_t *map);
void display_menus(map_t *map, sfRenderWindow *win);
void pause_menu(map_t *map, sfRenderWindow *win);
void restart_game(map_t *map);
void display_htp(map_t *map, sfRenderWindow *win);
void display_htp_menu(map_t *map, sfRenderWindow *win);
void display_restart_win(map_t *map, sfRenderWindow *win);
void display_pause_restart(map_t *map, sfRenderWindow *win);
void display_lose_menu(map_t *map, sfRenderWindow *win);
void display_quick(map_t *map, sfRenderWindow *win);
void display_inf(map_t *map, sfRenderWindow *win);
int display_spell(map_t *map, sfRenderWindow *win);
void throw_spell(map_t *map, sfMouseButtonEvent event);
int grab_spell(map_t *map, sfMouseButtonEvent event);
void display_cursor(map_t *map, sfRenderWindow *win);

// Music sfml:
sfMusic *sfMusic_createFromFile(const char *filename);
void sfMusic_destroy (sfMusic *music);
void sfMusic_play(sfMusic *music);
void sfMusic_setLoop(sfMusic *music, sfBool loop);
void sfSound_destroy (sfSound *sound);
void sfSound_play (sfSound *sound);
void sfMusic_pause (sfMusic *music);
sfSoundBuffer *sfSoundBuffer_createFromFile (const char *filename);
sfSound *sfSound_create (void);
void sfMusic_stop (sfMusic *music);
void sfSound_setBuffer (sfSound *sound, const sfSoundBuffer *buffer);
void sfSoundBuffer_destroy (sfSoundBuffer *soundBuffer);

// Destroy
void destroy_all(map_t *map);
void destroy_sprite(map_t *map, int nb_e, int nb_t);
#endif
