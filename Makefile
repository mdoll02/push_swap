# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 09:27:16 by mdoll             #+#    #+#              #
#    Updated: 2023/02/28 11:30:21 by mdoll            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

CC		:= gcc

CFLAGS	:= -Wall -Wextra -Werror

UTILS   := utils/

OPS		:= operations/

SORT	:= sorting/

SRCS	:=	push_swap.c \
			$(UTILS)list_operations.c $(UTILS)input_check.c \
			$(OPS)swap.c $(OPS)rotate.c $(OPS)reverse_rotate.c $(OPS)push.c \
			$(SORT)start_sorting.c $(SORT)sorting_utils.c

OBJS	:= $(SRCS:.c=.o)

NORM	:= $(shell norminette | grep Error | grep c:)

RM		:= rm -f

b	=	\033[1;30m
r	=	\033[1;31m
g	=	\033[1;32m
y	=	\033[1;33m
bl	=	\033[1;34m
p	=	\033[1;35m
c	=	\033[1;36m
w	=	\033[1;37m
end =	[0m

all:	${NAME}

%.o: %.c
	@ $(CC) -c $(CFLAGS) $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@ echo "${r}compiling Libft${end}"
	@ make all -C ./libft >/dev/null 2>&1
	@ cp ./libft/libft.a .
	@ echo "${bl}compiling program${end}"
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft.a
	@ echo "${g}finished compiling.${end}"
	@ echo "${bl}Use: ./push_swap 1 2 3 4 ... or \"1 2 3 4 ...\" to run the progam${end}"
	@ echo "Norm error in: ${r}" $(NORM) "${end}"

clean:
	@${RM} $(OBJS)
	@make clean -C ./libft
	@ echo "${y}cl${bl}ea${p}ne${c}d!${end}"

fclean:
	@ ${RM} ${NAME}
	@ make fclean -C ./libft
	@ ${RM} libft.a
	@ echo "${y}eve${bl}ryt${p}hi${c}ng${end}"
	@ make clean

re:			fclean all

.PHONY:		all clean fclean re files bonus