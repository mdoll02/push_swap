/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:13:31 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/23 11:39:24 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack(stack_a, argv, argc);
	print_stack(*stack_a);
	rra(stack_a);
	rra(stack_a);
	rra(stack_a);
	print_stack(*stack_a);
	return (0);
}

void	fill_stack(t_stack **stack, char **argv, int argc)
{
	char	**numbers;
	int		index;
	t_stack	*new;

	index = 0;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
	{
		index = 1;
		numbers = argv;
	}
	while (numbers[index])
	{
		new = ft_lstnew(ft_atoi(numbers[index]));
		ft_listadd_back(stack, new);
		index++;
	}
	if (argc == 2)
		free(numbers);
}
