# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 22:02:13 by elizabethte       #+#    #+#              #
#    Updated: 2024/05/10 05:22:27 by eteo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC =  op_push.c op_revrotate.c op_rotate.c op_swap.c\
init.c exec.c basic.c push_swap.c cost.c least_cost.c push_back.c\

OFILES = $(SRC:.c=.o)

all : ${NAME}

$(NAME) : $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(OFILES) $(LIBFT)

$(OFILES): $(SRC)
	$(CC) $(CFLAGS) -I. -c $^

$(LIBFT):
	@make -C $(LIBFT_PATH) all

clean :
	@make -C $(LIBFT_PATH) clean
	rm -rf $(OFILES)

fclean : clean
	@make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re