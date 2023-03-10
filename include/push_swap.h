/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:03:36 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/09 11:02:34 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
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

int		fill_stack(t_stack **stack, int argc, char **argv);
int		*replace_numbers(int *input, int *sorted, int len);

int		*build_array(char **argv, int argc, int *len);
int		*build_sorted_array(char **argv, int argc);
int		*bubble_sort(int *array, int len);

t_stack	*ft_lstnew(int value);
void	ft_listadd_back(t_stack **stack, t_stack *new_s);
void	ft_listadd_front(t_stack **stack, t_stack *new_s);
t_stack	*ft_lstlast(t_stack *head);
int		number_of_elements(t_stack **stack);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
int		ra(t_stack **stack);

void	begin_sorting(t_stack **stack_a, t_stack **stack_b);

void	sort_3(t_stack **stack);
void	sort_5(t_stack **stack_a, t_stack **stack_b, int *border);

int		*get_borders(t_stack **stack);
bool	is_sorted(t_stack **stack, int value);

void	radix(t_stack **a, t_stack **b);

// Unused functions TODO remove?

int		rrb(t_stack **stack);
int		rrr(t_stack **stack_a, t_stack **stack_b);
int		rb(t_stack **stack);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		sb(t_stack **stack_b);
int		sa(t_stack **stack_a);

#endif