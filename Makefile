# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 01:15:49 by nakhalil          #+#    #+#              #
#    Updated: 2025/05/05 15:13:17 by nakhalil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft
LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = srcs/main.c \
      srcs/parsing/parsing_main.c \
      srcs/parsing/parsing_normalize.c \
      srcs/parsing/parsing_split.c \
      srcs/parsing/parsing_validation.c \
      srcs/operations/operations_a.c \
      srcs/operations/operations_b.c \
      srcs/sorting/sort_small.c \
      srcs/sorting/sort_chunk.c \
      srcs/utils/utils.c \
      srcs/error/error.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)
      
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re