# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 14:24:37 by mabdessm          #+#    #+#              #
#    Updated: 2024/06/29 11:35:53 by mabdessm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra -Iincludes
RM = rm -rf

SRCS = pushswap/*.c printf/*.c libft/*.c

OBJS = $(SRCS:.c=.o)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean