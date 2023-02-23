/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:30:09 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/23 11:38:55 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// NEED TO ADD ERROR HANDLING
static int	reverse_rotate(t_stack **stack)
{
	t_stack	*new_first;
	t_stack	*new_second;

	new_second = *stack;
	new_first = ft_lstlast(new_second);
	ft_listadd_front(stack, new_first);
	return (0);
}

int	rra(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
