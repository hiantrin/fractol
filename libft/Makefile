# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 17:31:33 by hiantrin          #+#    #+#              #
#    Updated: 2020/02/19 00:59:59 by hiantrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC=ft_memset.c ft_bzero.c ft_memcpy.c  ft_memccpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c \
	ft_memdel.c\
	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	ft_strcmp.c ft_strncmp.c ft_atoi.c \
	 ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c \
	 ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c \
	ft_itoa.c \
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_strstrcount.c ft_lenstr.c get_next_line.c

OUT=$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc 

all: $(NAME)

$(NAME): $(OUT)
	@ar rc $(NAME) $(OUT)
	@ranlib $(NAME)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c -o $@  $<

clean:
	@/bin/rm -f $(OUT)

fclean:	clean
	@/bin/rm -f $(NAME)

re: fclean all