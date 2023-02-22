/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:03:36 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/22 14:41:32 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h> // remove when finished --> need to debug perror / fprintf

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}		t_stack;

// Input Check

int		check_input(char **argv, int argc);

// Init Stack

void	fill_stack(t_stack **stack, char **argv, int argc);

// List Operations

t_stack	*ft_lstnew(int value);
void	ft_listadd_back(t_stack **stack, t_stack *new);
void	ft_listadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_lstlast(t_stack *head);
void	print_stack(t_stack *stack);

// Swap

int		ss(t_stack **stack_a, t_stack **stack_b);
int		sb(t_stack **stack_b);
int		sa(t_stack **stack_a);

#endif