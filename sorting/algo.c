/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:09:33 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/04 09:59:19 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	while (number_of_elements(b) > 0)
	{
		if (is_sorted(a, (*b)->value) == false)
		{
			if (get_pos(a, (*b)->value) <= number_of_elements(a) / 2)
				sort_from_top(a, b);
			else
				sort_from_bottom(a, b);
		}
		else
			pa(a, b);
	}
}

void	sort_from_top(t_stack **a, t_stack **b)
{
	int	pos;
	int	i;

	i = 0;
	pos = get_pos(a, (*b)->value);
	while (i < pos - 1)
	{
		ra(a);
		i++;
	}
	pa(a, b);
	while (i > 0)
	{
		if (*b)
		{
			if ((*b)->value < (*a)->value) // && get_last_element(a) < (*b)->value)
				pa(a, b);
			if ((*b)->value > (*a)->value) // && get_last_element(a) > (*b)->value)
				pa(a, b);
		}
		rra(a);
		i--;
	}
}

void	sort_from_bottom(t_stack **a, t_stack **b)
{
	int	pos;
	int	i;

	i = 0;
	pos = get_pos(a, (*b)->value);
	while (i < number_of_elements(a) - pos + 1)
	{
		rra(a);
		i++;
	}
	pa(a, b);
	while (i >= 0)
	{
		// if ((*b)->value > (*a)->value && get_last_element(a) > (*b)->value)
		// 	pa(a, b);
		ra(a);
		i--;
	}
}

int	get_last_element(t_stack **stack)
{
	t_stack	*head;

	if (stack == NULL)
		return (0);
	if (*stack == NULL)
		return (0);
	head = *stack;
	while (head->next != NULL)
		head = head->next;
	return (head->value);
}
