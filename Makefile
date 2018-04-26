# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydumont- <ydumont-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:43:20 by tmerli            #+#    #+#              #
#    Updated: 2017/12/02 21:12:48 by tmerli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH		= libft/
LIB			= libft.a
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
NAME		= fillit
HEAD		= tetriminos.h
SRC			= main.c \
			  ft_alloc.c \
			  ft_checkfile.c \
			  ft_display.c \
			  ft_reset.c \
			  ft_resetx.c \
			  ft_gettetriminos.c \
			  ft_minsize.c \
			  ft_move.c \
			  ft_place.c \
			  ft_readfile.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(HEAD) $(OBJ)
	make -C libft/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBPATH)$(LIB)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $^

clean:
	rm -fv $(OBJ)
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -fv $(NAME)

re: fclean all
