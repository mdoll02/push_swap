/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:30:09 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/27 09:28:19 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// NEED TO ADD ERROR HANDLING
static int	reverse_rotate(t_stack **stack)
{
	t_stack	*new_first;
	t_stack	*new_second;
	t_stack	*new_last;

	new_second = *stack;
	new_first = ft_lstlast(new_second);
	new_last = *stack;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	new_last->next = NULL;
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
