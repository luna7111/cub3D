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

CFLAGS	:=	-Wall -Wextra -Werror -Iinclude

########################

all: $(NAME)

$(NAME): obj $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

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

