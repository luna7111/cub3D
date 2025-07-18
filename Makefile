#
# Name: Luna y Carol
# File: Makefile
# Created on: Thursday Jul 17, 2025 19:28:48 CEST
#

########################

NAME		:=	cub3D

SRC			:=	src/main.c\

OBJ			:=	$(SRC:%.c=obj/%.o)

CC			:=	cc

CFLAGS		:=	-Wall -Wextra -Werror -Iinclude

LIBFLAGS	:=	-Lmlx -lmlx -lXext -X11 -lm

########################

$(LIBFT)	:=	libft/libft.a
$(LIBFTDIR)	:=	libft

$(MLX)		:=	mlx/libmlx.a
$(MLXDIR)	:=	mlx

$(GCTRL)	:=	gctrl/garbage_control.a
$(GCTRLDIR)	:	gctrl

########################

all: $(NAME)

$(MLX):
	make -C $(MLXDIR)

$(LIBFT):
	make -C  $(LIBFTDIR)

$(GCTRL):
	make -C $(GCTRLDIR)

$(NAME): obj $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFLAGS)

obj:
	mkdir obj
	mkdir obj/src

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

