# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 13:08:00 by iengels           #+#    #+#              #
#    Updated: 2023/10/23 15:59:06 by iengels          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_handler.c		\
		ft_print_utils.c	\
		ft_printf.c			\
		ft_putfloat.c		\
		ft_putnbr.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -gdwarf-2 -Wall -Wextra -Werror -std=c99

all: $(NAME)

$(NAME):	$(OBJ)                                                                   
			ar rcs  $(NAME) $(OBJ)    

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf  $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
