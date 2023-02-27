/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:03:31 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/27 14:01:40 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 1;
	new->next = NULL;
	return (new);
}

void	ft_listadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	ft_listadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (*stack)
	{
		tmp = ft_lstlast(*stack);
		tmp->next = new;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

t_stack	*ft_lstlast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

int	number_of_elements(t_stack **stack)
{
	int		number_count;
	t_stack	*head;

	if (*stack == NULL)
		return (0);
	number_count = 1;
	head = *stack;
	while (head->next != NULL)
	{
		number_count++;
		head = head->next;
	}
	return (number_count);
}
