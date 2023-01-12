# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 13:17:26 by mdoll             #+#    #+#              #
#    Updated: 2023/01/12 12:02:31 by mdoll            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = push_swap_lib.a

SRC = 

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

MAIN = ../main.c

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@cp libft/libft.a .
	@mv libft.a $(LIB)
	@ar -rcs $(LIB) $(OBJS)
	@cc $(CFLAGS) $(MAIN) $(LIB) -o $(NAME)
	
clean:
	cd libft && $(MAKE) clean
	rm -f *.o

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(LIB)
	
re: fclean all

#gcc: all clean
#	@gcc $(CFLAGS) -o executable $(MAIN) libftprintf.a
#
#gcco: all clean
#	@gcc $(CFLAGS) -o executable $(MAIN) libftprintf.a
#	@ ./executable
#	
#call: fclean
#	rm -f executable
#
.PHONY: all clean fclean re