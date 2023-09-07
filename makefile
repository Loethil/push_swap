# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 14:47:11 by mbatteux          #+#    #+#              #
#    Updated: 2023/08/21 14:47:13 by mbatteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CCC = push_swap.c\
	push_swap_utils.c\
	swap.c\
	push.c\
	rotate.c\
	reverse_rotate.c\
	algo_235.c\
	algo_100.c\
	algo_500.c\
	algo_all.c\
	tri_algo_100.c

OOO = $(CCC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OOO)
	gcc $(OOO) $(FLAG)  -o $(NAME) -g3
.c.o:
	gcc $(FLAG) -c $< -o ${<:.c=.o} -g3
clean:
	rm -f $(OOO)
fclean: clean
	rm -f $(NAME)
re: fclean all

