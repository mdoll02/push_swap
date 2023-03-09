/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:52:36 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/09 10:33:33 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*new_last;
	t_stack	*new_first;

	new_last = *stack;
	new_first = (*stack)->next;
	new_last->next = NULL;
	*stack = new_first;
	ft_listadd_back(&new_first, new_last);
	return (0);
}

int	ra(t_stack **stack)
{
	rotate(stack);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_stack **stack)
{
	rotate(stack);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
