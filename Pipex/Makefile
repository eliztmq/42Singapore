# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 17:20:18 by elizabethte       #+#    #+#              #
#    Updated: 2023/11/25 10:46:55 by elizabethte      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =  \

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