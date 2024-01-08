# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 17:20:18 by elizabethte       #+#    #+#              #
#    Updated: 2024/01/08 15:14:05 by elizabethte      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =  fdf.c\

OFILES = $(SRC:.c=.o)

all : ${NAME}

$(NAME) : $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) $(LIBFT) $(MINILIBX) -Lmlx -lmlx -framework OpenGL -framework AppKit

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