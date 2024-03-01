# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 17:20:18 by elizabethte       #+#    #+#              #
#    Updated: 2024/03/01 05:37:41 by eteo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./mlx_linux
MINILIBX = $(MINILIBX_PATH)/libmlx.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC =  fdf.c grid.c line.c mouse.c rotate.c window.c\

OFILES = $(SRC:.c=.o)

all : ${NAME}

$(NAME) : $(LIBFT) $(MINILIBX) $(OFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(MINILIBX) $(OFILES) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(OFILES): $(SRC)
	$(CC) $(CFLAGS) -c $^

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(MINILIBX):
	@make -C $(MINILIBX_PATH) all

clean :
	@make -C $(LIBFT_PATH) clean
	@make -C $(MINILIBX_PATH) clean
	rm -f $(OFILES)

fclean : clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MINILIBX_PATH) clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re