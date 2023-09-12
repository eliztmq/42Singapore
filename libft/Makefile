# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 17:37:45 by eteo              #+#    #+#              #
#    Updated: 2023/09/10 22:10:13 by elizabethte      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

CFILES = *.c

OFILES = *.o

all : ${NAME}

${NAME} : ${OFILES}
	ar -rc ${NAME} ${OFILES}

${OFILES} :
	cc -c ${CFLAGS} ${CFILES}

clean :
	rm -f ${OFILES}

fclean : clean
	rm -f ${NAME}

re : fclean all