# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 17:20:18 by elizabethte       #+#    #+#              #
#    Updated: 2024/01/03 17:42:31 by eteo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =  fdf.c\

OFILES = $(SRC:.c=.o)

all : ${NAME}

$(NAME) : $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(OFILES) $(LIBFT)

$(OFILES): $(SRC)
	$(CC) $(CFLAGS) -c $^

$(LIBFT):
	@make -C $(LIBFT_PATH) all

clean :
	@make -C $(LIBFT_PATH) clean
	rm -f $(OFILES)

fclean : clean
	@make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re