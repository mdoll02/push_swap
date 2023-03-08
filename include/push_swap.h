/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:03:36 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/08 12:17:19 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h> // remove when finished --> need to debug perror / fprintf
# include <stdbool.h>

# ifndef MAX
#  define MAX 1
# endif

# ifndef MIN
#  define MIN 0
# endif

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}		t_stack;

typedef struct s_array
{
	int	*input;
	int	*sorted;
	int	len;
}		t_array;

void	ft_free(t_stack **stack);
int		check_input(char **argv, int argc);

void	print_stack(t_stack *stack);
void	fill_stack(t_stack **stack, int argc, char **argv);
int		*build_array(char **argv, int argc, t_array *array);
int		*build_sorted_array(char **argv, int argc);
void	bubble_sort(int *array, int len);

t_stack	*ft_lstnew(int value);
void	ft_listadd_back(t_stack **stack, t_stack *new_s);
void	ft_listadd_front(t_stack **stack, t_stack *new_s);
t_stack	*ft_lstlast(t_stack *head);
int		number_of_elements(t_stack **stack);

int		ss(t_stack **stack_a, t_stack **stack_b);
int		sb(t_stack **stack_b);
int		sa(t_stack **stack_a);

int		ra(t_stack **stack);
int		rb(t_stack **stack);
int		rr(t_stack **stack_a, t_stack **stack_b);

int		rra(t_stack **stack);
int		rrb(t_stack **stack);
int		rrr(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);

void	begin_sorting(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack);
void	sort_5(t_stack **stack_a, t_stack **stack_b, int *border);
int		*get_borders(t_stack **stack);
bool	is_sorted(t_stack **stack, int value);
void	radix(t_stack **a, t_stack **b);

#endif