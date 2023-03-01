/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:09:33 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/01 16:13:38 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_high(t_stack **a, t_stack **b)
{
	int	pos;
	int	i;

	i = 0;
	while (number_of_elements(a) < number_of_elements(b))
	{
		pa(a, b);
		if (is_sorted(a) == false)
		{
			pb(b, a);
			pos = get_pos(a, (*b)->value);
			print_stack(*a);
			printf("pos: %d nb: %d elem: %d\n", pos, (*b)->value, number_of_elements(a));
			while (i < pos - 1)
			{
				ra(a);
				i++;
			}
			pa(a, b);
			while (i > 0)
			{
				rra(a);
				i--;
			}
			print_stack(*a);
			printf("----------\n");
		}
	}
	print_stack(*a);
	printf("----------\n");
	print_stack(*b);
}

void	sort_low(t_stack **a, t_stack **b)
{
	int	*border;

	while (number_of_elements(a) < number_of_elements(b))
	{
		pa(a, b);
		border = get_borders(a);
		if ((*a)->value == border[MAX])
			ra(a);
	}
}
