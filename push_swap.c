/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:13:31 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/08 16:23:09 by mdoll            ###   ########.fr       */
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
		return (1);
	*stack_a = NULL;
	fill_stack(stack_a, argc, argv);
	*stack_b = NULL;
	begin_sorting(stack_a, stack_b);
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}

void	fill_stack(t_stack **stack, int argc, char **argv)
{
	int		index;
	int		j;
	t_stack	*new;
	t_array	array;

	array.sorted = build_array(argv, argc, &array.len);
	array.input = build_array(argv, argc, &array.len);
	if (!array.input || !array.sorted)
	{
		ft_free(stack);
		if (array.sorted)
			free(array.sorted);
		if (array.input)
			free(array.input);
		exit (1);
	}
	array.sorted = bubble_sort(array.sorted, array.len);
	index = 0;
	while (index < array.len)
	{
		j = 0;
		while (j < array.len)
		{
			if (array.input[index] == array.sorted[j])
			{
				array.input[index] = j;
				break ;
			}
			j++;
		}
		index++;
	}
	index = 0;
	while (index < array.len)
	{
		new = ft_lstnew(array.input[index]);
		ft_listadd_back(stack, new);
		index++;
	}
	free(array.input);
	free(array.sorted);
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
