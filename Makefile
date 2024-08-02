# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 14:24:37 by mabdessm          #+#    #+#              #
#    Updated: 2024/08/02 15:39:44 by mabdessm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra -Iincludes -fsanitize=address
RM = rm -rf

SRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
		libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
		libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd_back.c \
		libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_lstdelone.c \
		libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_lstmap.c \
		libft/ft_lstnew.c libft/ft_memcpy.c libft/ft_striteri.c \
		libft/ft_lstsize.c libft/ft_memchr.c libft/ft_memcmp.c \
		libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
		libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c \
		libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c \
		libft/ft_strlen.c libft/ft_strrchr.c libft/ft_toupper.c \
		libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c \
		libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c \
		libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c \
		printf/ft_printf.c printf/ft_putchar.c printf/ft_putstr.c \
		printf/ft_strlen.c printf/ft_putunsigned.c printf/ft_putnbr.c \
		printf/ft_putnbr_base.c printf/ft_putnbr_base_p.c \
		pushswap/push_swap.c pushswap/check_errors.c pushswap/index_utils.c \
		pushswap/single_sorting.c pushswap/multi_sorting.c \
		pushswap/sort_small_stack.c pushswap/scan_stack.c \
		pushswap/find_optimal_push.c pushswap/sort_back.c \
		pushswap/sort_big_stack.c

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