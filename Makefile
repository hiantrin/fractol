# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 12:45:44 by hiantrin          #+#    #+#              #
#    Updated: 2020/02/19 01:00:19 by hiantrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =  fractol.c julia.c zoom.c help.c hook.c

OUT=$(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: lib $(NAME)


lib:
	make -C libft

$(NAME): $(OUT)
	$(CC) $(CFLAGS) $(OUT) -L./libft -lft -o $(NAME) \
	-L /usr/local/lib -lmlx -framework OpenGl -framework AppKit

%.o : %.c fractol.h
	$(CC) $(CFLAGS) -c -o $@  $<

clean:
	@make clean -C libft
	@/bin/rm -f $(OUT)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
