/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:03:36 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/28 08:58:39 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h> // remove when finished --> need to debug perror / fprintf

# ifndef MAX
#  define MAX 1
# endif

# ifndef MIN
#  define MIN 0
# endif

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}		t_stack;

void	print_stack(t_stack *stack);

// Input Check

int		check_input(char **argv, int argc);

// Init Stack

void	fill_stack(t_stack **stack, char **argv, int argc);

// List Operations

t_stack	*ft_lstnew(int value);
void	ft_listadd_back(t_stack **stack, t_stack *new);
void	ft_listadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_lstlast(t_stack *head);
int		number_of_elements(t_stack **stack);

// Swap

int		ss(t_stack **stack_a, t_stack **stack_b);
int		sb(t_stack **stack_b);
int		sa(t_stack **stack_a);

// Rotate
// NEED TO ADD ERROR HANDLING

int		ra(t_stack **stack);
int		rb(t_stack **stack);
int		rr(t_stack **stack_a, t_stack **stack_b);

// Rervse Rotate
// NEED TO ADD ERROR HANDLING

int		rra(t_stack **stack);
int		rrb(t_stack **stack);
int		rrr(t_stack **stack_a, t_stack **stack_b);

// Push

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);

// Sorting

void	begin_sorting(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack);
void	sort_5(t_stack **stack_a, t_stack **stack_b, int *border);
int		*get_borders(t_stack **stack);

#endif