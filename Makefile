# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 09:27:16 by mdoll             #+#    #+#              #
#    Updated: 2023/03/09 11:46:38 by kx               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

CC		:= gcc

CFLAGS	:= -Wall -Wextra -Werror

UTILS   := utils/

OPS		:= operations/

SORT	:= sorting/

SRCS	:=	push_swap.c \
			$(UTILS)list_operations.c $(UTILS)input_check.c $(UTILS)array_ops.c\
			$(OPS)swap.c $(OPS)rotate.c $(OPS)reverse_rotate.c $(OPS)push.c \
			$(SORT)start_sorting.c $(SORT)sorting_utils.c
OBJS	:= $(SRCS:.c=.o)

NORM	:= $(shell norminette | grep Error | grep -G "\.[hc]:" | awk '{sub(/:.*$$/, ""); print}' | tr '\n' ',' | sed 's/,$$//')

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
	@ echo -e "${r}compiling Libft${end}"
	@ make all -C ./libft >/dev/null 2>&1
	@ cp ./libft/libft.a .
	@ echo -e "${bl}compiling program${end}"
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft.a
	@ echo -e "${g}finished compiling.${end}"
	@ echo -e "${bl}Use: ./push_swap 1 2 3 4 ... or \"1 2 3 4 ...\" to run the progam${end}"
	@ echo -e "Norm error in: ${r}" $(NORM) "${end}"

clean:
	@${RM} $(OBJS)
	@make clean -C ./libft
	@ echo -e "${y}cl${bl}ea${p}ne${c}d!${end}"

fclean:
	@ ${RM} ${NAME}
	@ make fclean -C ./libft
	@ ${RM} libft.a
	@ echo -e "${y}eve${bl}ryt${p}hi${c}ng${end}"
	@ make clean

re:			fclean all

.PHONY:		all clean fclean re files bonus
