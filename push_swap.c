/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:13:31 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/20 15:45:38 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1 || check_input(argv, argc) == 1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit (1);
	}
	return (0);
}

static int	is_valid_number(char *number)
{
	int		is_nb;

	is_nb = 0;
	if (number[is_nb] == '-')
		is_nb++;
	while (number[is_nb])
	{
		if (number[is_nb] < '0' || number[is_nb] > '9')
		{
			return (1);
		}
		is_nb++;
	}
	return (0);
}

int	check_input(char **argv, int argc)
{
	int		i;
	long	tmp;
	char	**numbers;

	i = 1;
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
	}
	else
		numbers = argv;
	while (numbers[i])
	{
		if (is_valid_number(numbers[i]) == 1)
			return (1);
		tmp = ft_atoi(numbers[i]);
		if (tmp > INT32_MAX || tmp < INT32_MIN)
			return (1);
		i++;
	}
	if (argc == 2)
		free(numbers);
	return (0);
}
