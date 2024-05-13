# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 17:41:10 by mel-bouh          #+#    #+#              #
#    Updated: 2024/05/13 15:47:28 by mel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= push_swap.c utils.c ft_split.c ft_strjoin.c checkfunctions.c
NAME= push_swap

all: $(NAME)

$(NAME): $(SRC)
	cc -Wall -Werror -Wextra $(SRC) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
