/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:29:23 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/04 10:58:16 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

bool	is_sorted(t_stack **stack, int value)
{
	t_stack	*head;
	int		tmp;

	if (stack == NULL)
		return (false);
	if (*stack == NULL)
		return (false);
	head = *stack;
	if (head->value < value)
		return (false);
	while (head->next != NULL)
	{
		tmp = head->value;
		if (tmp > head->next->value)
			return (false);
		head = head->next;
	}
	return (true);
}

int	get_median(t_stack **stack, int max)
{
	t_stack		*head;
	long long	median;
	int			count;

	if (*stack == NULL)
		return (0);
	count = 0;
	head = *stack;
	median = head->value;
	while (head->next != NULL && count <= max)
	{
		head = head->next;
		median += head->value;
		count++;
	}
	if (median != 0)
		median /= number_of_elements(stack);
	return ((int)median);
}

int	get_pos(t_stack **stack, int value)
{
	int		index;
	t_stack	*head;

	if (*stack == NULL)
		return (0);
	index = 1;
	head = *stack;
	while (head->next != NULL)
	{
		if (head->value > value)
			return (index);
		index++;
		head = head->next;
	}
	if (head->value < value)
		index++;
	return (index);
}

int	last_elem(t_stack **stack)
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
