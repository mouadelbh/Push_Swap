# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 17:41:10 by mel-bouh          #+#    #+#              #
#    Updated: 2024/05/18 18:59:38 by mel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Werror -Wextra
SRC= ./mandatory/push_swap.c ./mandatory/algorithm.c ./mandatory/moves.c  \
	./mandatory/utils1.c ./mandatory/utils2.c ./mandatory/utils3.c \
	./mandatory/utils4.c ./mandatory/utils5.c ./mandatory/ft_split.c \
	./mandatory/ft_strjoin.c ./mandatory/checkfunctions.c \
	./ft_printf/ft_format.c ./ft_printf/ft_printf.c ./ft_printf/ft_putchar.c \
	./ft_printf/ft_putnbr.c ./ft_printf/ft_putstr.c
NAME= push_swap

all: $(NAME)

$(NAME): $(SRC)
	@cc $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf *.o
fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
