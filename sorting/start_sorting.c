/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:43:03 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/07 16:31:25 by mdoll            ###   ########.fr       */
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
		ft_free(stack_a);
		ft_free(stack_b);
		exit(0);
	}
	if (elements == 2)
		sa(stack_a);
	else if (elements == 3)
		sort_3(stack_a);
	else if (elements == 5)
		sort_5(stack_a, stack_b, borders);
	else
		radix(stack_a, stack_b);
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

void	sort_5(t_stack **a, t_stack **b, int *border)
{
	while (number_of_elements(b) < 2)
	{
		if ((*a)->value == border[MIN] || \
			(*a)->value == border[MAX])
			pb(b, a);
		else
			ra(a);
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
	border = get_borders(a);
	if ((*a)->value == border[MAX])
		ra(a);
	else
	{
		sa(a);
		ra(a);
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int	median;

	median = get_median(a, number_of_elements(a));
	pb(b, a);
	while (number_of_elements(a) > 3)
	{
		if ((*a)->value < median)
		{
			pb(b, a);
			rb(b);
		}
		else
			pb(b, a);
		pb(b, a);
	}
	sort_3(a);
	sort(a, b);
}
