/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:13:39 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/07 16:35:37 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix(t_stack **a, t_stack **b)
{
	int	*bo;
	int	bits;
	int	i;
	int	j;

	bits = 0;
	bo = get_borders(a);
	while (bo[MAX] >> bits != 0)
		bits++;
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j <= bo[MAX])
		{
			if ((((*a)->value >> i) & 1) == 1)
				ra(a);
			else
				pb(b, a);
			j++;
		}
		i++;
		while (*b != NULL)
			pa(a, b);
	}
}
