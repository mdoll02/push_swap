/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:43:03 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/27 14:04:34 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	begin_sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	elements;
	int	*borders;

	elements = number_of_elements(stack_a);
	borders = get_borders(stack_a);
	printf("min: %d\nmax: %d\n", borders[MIN], borders[MAX]);
	if (elements == 1)
		return ;
	if (elements == 2 && (*stack_a)->value < (*stack_a)->next->value)
		sa(stack_a);
	if (elements == 3)
		sort_3(stack_a, borders[MAX]);
	if (elements == 5)
		sort_5(stack_a, stack_b, borders);
}

void	sort_3(t_stack **stack, int max)
{
	if ((*stack)->value == max)
		ra(stack);
	if ((*stack)->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b, int *border)
{
	while (number_of_elements(stack_b) < 2)
	{
		if ((*stack_a)->value == border[MIN] || \
			(*stack_a)->value == border[MAX])
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
	sort_3(stack_a, border[MAX]);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->value == border[MAX])
		ra(stack_a);
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
}

int	*get_borders(t_stack **stack)
{
	t_stack			*head;
	int				max;
	int				min;
	static int		borders[2];

	head = *stack;
	max = head->value;
	min = head->value;
	while (head->next != NULL)
	{
		head = head->next;
		if (head->value > max)
			max = head->value;
		if (head->value < min)
			min = head->value;
	}
	borders[MIN] = min;
	borders[MAX] = max;
	return (borders);
}
