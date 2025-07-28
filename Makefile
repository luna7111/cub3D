#
# Name: Luna y Carol
# File: Makefile
# Created on: Thursday Jul 17, 2025 19:28:48 CEST
#

########################

NAME		:=	cub3D

SRC			:=	src/main.c\
				src/parser/attributes.c\
				src/parser/attributes_aux.c\
				src/parser/file_loading.c

OBJ			:=	$(SRC:%.c=obj/%.o)

CC			:=	cc

CFLAGS		:=	-Iinclude -Wall -Wextra -Werror

LIBFLAGS	:=	-Lmlx -lmlx -lXext -lX11 -lm

########################

LIBFT		:=	libft/libft.a
LIBFTDIR	:=	libft

MLX			:=	mlx/libmlx.a
MLXDIR		:=	mlx

GCTRL		:=	gctrl/garbage_control.a
GCTRLDIR	:=	gctrl

########################

all: $(NAME)

$(MLX):
	make -C $(MLXDIR)

$(LIBFT):
	make -C  $(LIBFTDIR)

$(GCTRL):
	make -C $(GCTRLDIR)

$(NAME): obj $(MLX) $(GCTRL) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(GCTRL) $(LIBFT) -o $(NAME) $(LIBFLAGS)

obj:
	mkdir obj

obj/%.o: %.c
	install -Dv /dev/null $@
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

