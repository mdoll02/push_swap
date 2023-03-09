/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:13:31 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/09 11:02:28 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc == 1 || check_input(argv, argc) == 1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
	{
		if (stack_a)
			free(stack_a);
		if (stack_b)
			free(stack_b);
		return (1);
	}
	*stack_a = NULL;
	*stack_b = NULL;
	if (fill_stack(stack_a, argc, argv) != 1)
		begin_sorting(stack_a, stack_b);
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}

int	fill_stack(t_stack **stack, int argc, char **argv)
{
	int		index;
	t_stack	*new;
	t_array	array;

	array.sorted = build_array(argv, argc, &array.len);
	array.input = build_array(argv, argc, &array.len);
	if (!array.input || !array.sorted)
	{
		if (array.sorted)
			free(array.sorted);
		if (array.input)
			free(array.input);
		return (1);
	}
	array.input = replace_numbers(array.input, array.sorted, array.len);
	index = 0;
	while (index < array.len)
	{
		new = ft_lstnew(array.input[index]);
		ft_listadd_back(stack, new);
		index++;
	}
	free(array.input);
	return (0);
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (tmp == NULL)
		ft_putendl_fd("(NULL)", 1);
	else
	{
		while (tmp)
		{
			write(1, "|", 1);
			ft_putnbr_fd(tmp->value, 1);
			write(1, "|\n", 2);
			tmp = tmp->next;
		}
	}
}

void	ft_free(t_stack **stack)
{
	t_stack	*head;

	if (!*stack)
	{
		free(stack);
		return ;
	}
	while ((*stack)->next != NULL)
	{
		head = (*stack)->next;
		free(*stack);
		*stack = head;
	}
	free(stack);
}
