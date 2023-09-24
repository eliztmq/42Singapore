# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 17:20:18 by elizabethte       #+#    #+#              #
#    Updated: 2023/09/24 21:03:16 by elizabethte      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c print_hex.c print_nbr.c print_str.c \

OFILES = $(SRC:.c=.o)

all : ${NAME}

${NAME} : ${OFILES}
	ar -rc ${NAME} ${OFILES}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f ${OFILES}

fclean : clean
	rm -f ${NAME}

re : fclean all