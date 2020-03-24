##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## The supreme makefile
##

## Colors

NO_COLOR=\x1b[0m

OK_COLOR=\x1b[32;01m

ERROR_COLOR=\x1b[31;01m

WARN_COLOR=\x1b[33;01m

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)

ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)

WARN_STRING=$(WARN_COLOR)[WARNINGS]$(NO_COLOR)

##

SRC	=	main.c	\
		src/lib/my_strcmp.c \
		src/lib/my_strcpy.c \
		src/lib/my_strcat.c \
		src/lib/my_revstr.c \
		src/lib/int_to_string.c \
		src/text.c \
		src/define_text.c \
		src/define_window.c	\
		src/event.c	\
		src/draw_all.c	\
		src/maps/define_map.c	\
		src/ennemies/define_ennemies.c	\
		src/towers/add_tower.c	\
		src/towers/move_tower.c	\
		src/towers/tower_attack.c	\
		src/ennemies/animate_sprite.c	\
		src/ennemies/move_ennemies.c \
		src/ennemies/enemies_dmg.c	\
		src/round.c	\
		src/win_loose.c	\
		src/menus/define_menus.c	\
		src/menus/display_menus.c	\
		src/menus/display_menus2.c	\
		src/menus/win_menu.c \
		src/menus/lose_menu.c \
		src/menus/check_button.c	\
		src/menus/check_button2.c	\
		src/menus/pause_menu.c	\
		src/menus/pause_menu2.c	\
		src/menus/start_menu.c	\
		src/towers/spells.c	\
		src/cursor.c	\
		src/restart.c	\
		src/destroy.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

CFLAGS		+=	-Wall -Wextra -I include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "building ... ${OK_STRING}"
	gcc -lm -o  $(NAME) $(OBJ) -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system

clean:
	rm -f $(OBJ)
	@echo -e "removing object files... ${WARN_STRING}"

fclean:	clean
	rm -f $(NAME)
	@echo -e "removing binaries... ${WARN_STRING}"

re:	fclean	all
	@echo -e "removing and rebuilding... ${WARN_STRING}"

