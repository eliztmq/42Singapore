# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 17:37:45 by eteo              #+#    #+#              #
#    Updated: 2023/09/09 18:02:12 by eteo             ###   ########.fr        #
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
