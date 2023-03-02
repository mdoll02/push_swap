/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:43:03 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/02 10:01:03 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	begin_sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	elements;
	int	*borders;

	elements = number_of_elements(stack_a);
	borders = get_borders(stack_a);
	if (elements == 1)
		return ;
	if (is_sorted(stack_a, (*stack_a)->value) == true)
	{
		printf("already sorted stoopid :)\n");
		return ;
	}
	if (elements == 2 && (*stack_a)->value < (*stack_a)->next->value)
		sa(stack_a);
	if (elements == 3)
		sort_3(stack_a);
	if (elements == 5)
		sort_5(stack_a, stack_b, borders);
	else
		push_to_b(stack_a, stack_b);
}

void	sort_3(t_stack **stack)
{
	int	*borders;

	borders = get_borders(stack);
	if ((*stack)->value == borders[MAX])
		ra(stack);
	if ((*stack)->next->value == borders[MAX])
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
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	border = get_borders(stack_a);
	if ((*stack_a)->value == border[MAX])
		ra(stack_a);
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int	median;

	median = get_median(a, number_of_elements(a));
	pb(b, a);
	while (number_of_elements(a) != 0)
	{
		if ((*a)->value < median)
		{
			pb(b, a);
			rb(b);
		}
		else
			pb(b, a);
	}
	pa(a, b);
	pa(a, b);
	if ((*a)->value > (*a)->next->value)
		sa(a);
	sort(a, b);
}
