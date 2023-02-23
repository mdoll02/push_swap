/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:55:55 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/23 10:29:32 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*tmp_adress;

	if (!stack)
		return (-1);
	if (!*stack || (*stack)->next == NULL)
		return (-1);
	tmp_adress = (*stack)->next->next;
	ft_listadd_front(stack, (*stack)->next);
	(*stack)->next->next = tmp_adress;
	return (0);
}

int	sa(t_stack **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_stack **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (sa(stack_a) == -1 || sb(stack_b) == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	return (0);
}
