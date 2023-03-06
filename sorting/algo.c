/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:09:33 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/06 11:14:24 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	while (number_of_elements(b) > 0)
	{
		if (is_sorted(a, (*b)->value) == false)
		{
			if ((*b)->next != NULL)
			{
				if ((*b)->next->value > (*b)->value)
					sb(b);
			}
			// if ((*a)->value < (*b)->value)
			// 	rb(b);
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
	while (i-- > 0 && get_pos(a, (*b)->value) > number_of_elements(a) / 2)
	{
		if (*b)
		{
			if ((*b)->value < (*a)->value && last_elem(a) < (*b)->value)
				pa(a, b);
			else if ((*b)->value > (*a)->value && last_elem(a) > (*b)->value)
				pa(a, b);
		}
		rra(a);
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
	while (i-- >= 0)
	{
		if (*b)
		{
			if ((*b)->value < (*a)->value && last_elem(a) < (*b)->value)
			{
				pa(a, b);
				i++;
			}
			if ((*b)->value > (*a)->value && last_elem(a) > (*b)->value)
				pa(a, b);
		}
		ra(a);
	}
}
