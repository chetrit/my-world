##
## EPITECH PROJECT, 2020
## my_world
## File description:
## Makefile
##

CC ?=		gcc

NAME =		my_world

TEST =		unit_tests

SRC =		src/main.c						\
		src/event.c						\
									\
									\
		src/game/utils.c					\
		src/game/utils_font.c					\
		src/game/utils_music.c					\
		src/game/utils_object.c					\
		src/game/utils_sound.c					\
		src/game/utils_sprite.c					\
		src/game/utils_string.c					\
		src/game/utils_text.c					\
		src/game/loop.c						\
		src/game/config.c					\
		src/game/window.c					\
		src/game/keyboard.c					\
									\
									\
		src/scr_home/screen.c					\
		src/scr_home/utils.c					\
		src/scr_home/button.c					\
		src/scr_home/button_functions.c				\
									\
									\
		src/scr_map_selection/screen.c				\
		src/scr_map_selection/utils.c				\
		src/scr_map_selection/button.c				\
		src/scr_map_selection/text_box.c			\
		src/scr_map_selection/button_funcs/load_map.c		\
		src/scr_map_selection/button_funcs/other.c		\
									\
									\
		src/scr_game/screen.c					\
		src/scr_game/utils.c					\
		src/scr_game/help_box.c					\
		src/scr_game/button.c					\
		src/scr_game/map_init.c					\
		src/scr_game/map_struct_init.c				\
									\
		src/scr_game/keyboard/utils.c				\
		src/scr_game/keyboard/brush_size.c			\
		src/scr_game/keyboard/tiles.c				\
		src/scr_game/keyboard/map.c				\
		src/scr_game/keyboard/shortcut.c			\
									\
		src/scr_game/button_funcs/burger/assets.c		\
		src/scr_game/button_funcs/burger/paint.c		\
		src/scr_game/button_funcs/burger/brush.c		\
		src/scr_game/button_funcs/burger/operate.c		\
		src/scr_game/button_funcs/burger/save.c			\
		src/scr_game/button_funcs/burger/utils.c		\
		src/scr_game/button_funcs/other.c			\
		src/scr_game/button_funcs/animation.c			\
		src/scr_game/button_funcs/tools.c			\
									\
		src/scr_game/animations/wave.c				\
		src/scr_game/animations/rotation.c			\
		src/scr_game/animations/sequence.c			\
		src/scr_game/animations/smooth.c			\
		src/scr_game/animations/math_fun.c			\
		src/scr_game/animations/function_3d.c			\
									\
		src/scr_game/tools/screenshot.c				\
		src/scr_game/tools/utils.c				\
		src/scr_game/tools/brush.c				\
		src/scr_game/tools/terraform.c				\
									\
		src/scr_game/navigation/move.c				\
		src/scr_game/navigation/zoom.c				\
									\
		src/scr_options/screen.c				\
		src/scr_options/utils.c					\
		src/scr_options/button.c				\
		src/scr_options/text_box.c				\
		src/scr_options/prog_bar.c				\
		src/scr_options/check_box.c				\
									\
		src/scr_options/obj_funcs/volume_bar.c			\
		src/scr_options/obj_funcs/button.c			\
		src/scr_options/obj_funcs/check_box.c			\
									\
		src/map/bottom.c					\
		src/map/bottom_computation.c				\
		src/map/map_3d.c					\
		src/map/map_iso.c					\
		src/map/tiles.c						\
		src/map/corners_highlight.c                     	\
									\
		src/map/tile_highlight/utils.c				\
		src/map/tile_highlight/computation.c			\
		src/map/tile_highlight/funcs.c				\
									\
		src/map/tile_coloration/utils.c				\
		src/map/tile_coloration/standard.c			\
		src/map/tile_coloration/epileptic.c			\
									\
		src/map/map_save/save.c					\
		src/map/map_save/load.c					\
		src/map/map_save/utils.c				\
		src/map/map_save/convert.c				\
									\
									\
		src/obj/utils.c						\
		src/obj/button.c					\
		src/obj/check_box.c					\
		src/obj/text_box.c					\
		src/obj/text_box_action.c				\
		src/obj/progression_bar.c				\
		src/obj/resets.c					\
		src/obj/animation_sprite_funcs.c			\
									\
									\
		src/my_utils/my_getnbr.c				\
		src/my_utils/my_strlen.c				\
		src/my_utils/my_putstr.c				\
		src/my_utils/my_put_nbr.c				\
		src/my_utils/my_strcpy.c				\
		src/my_utils/my_strcat.c				\
		src/my_utils/mem_init.c					\
		src/my_utils/my_string_merge.c				\
		src/my_utils/my_strncmp.c				\
		src/my_utils/my_strcmp.c				\
		src/my_utils/my_strdup.c				\
		src/my_utils/get_next_line.c				\
		src/my_utils/my_getnbr_mvptr.c				\
									\
									\
		src/math/funcs.c					\
		src/math/sinc.c						\
		src/math/better.c					\
		src/math/betterer.c					\
		src/math/bettererest.c					\
									\

OBJ =		$(SRC:.c=.o)

CFLAGS +=	-Wall -Wextra

CPPFLAGS +=	-I include/

LDLIBS +=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

TFLAGS =	--coverage -lcriterion

all: 		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDLIBS)

clean:
		$(RM) $(OBJ) *.gcno *.gcda

fclean:		clean
		$(RM) $(NAME) $(TEST)

re:		fclean all

.PHONY: all clean fclean re
