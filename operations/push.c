/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:53:04 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/27 13:59:46 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	push(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*new_first_dst;
	t_stack	*new_first_src;

	new_first_dst = *stack_src;
	new_first_src = (*stack_src)->next;
	if (!stack_src)
		return (-1);
	if (!*stack_src)
		return (-1);
	ft_listadd_front(stack_dst, new_first_dst);
	*stack_src = new_first_src;
	return (0);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return ;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	if (push(stack_a, stack_b) == -1)
		return ;
	ft_putendl_fd("pb", 1);
}
