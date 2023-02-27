/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:50:06 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/27 09:28:06 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	check_for_dupes(char **numbers, int argc)
{
	int	i;
	int	tmp;
	int	j;
	int	start;

	start = 0;
	if (argc == 2)
		start = 1;
	i = start;
	while (numbers[i])
	{
		tmp = ft_atoi(numbers[i]);
		j = start;
		while (numbers[j])
		{
			if (i != j && tmp == ft_atoi(numbers[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_for_number(char **numbers, int argc)
{
	int		i;
	long	tmp;

	i = 1;
	if (argc == 2)
		i = 0;
	while (numbers[i])
	{
		if (is_valid_number(numbers[i]) == 1)
			return (1);
		tmp = ft_atoi(numbers[i]);
		if (tmp > INT32_MAX || tmp < INT32_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	check_input(char **argv, int argc)
{
	char	**numbers;
	int		ret_dupe;
	int		ret_number;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
	}
	else
		numbers = argv;
	ret_number = check_for_number(numbers, argc);
	ret_dupe = check_for_dupes(numbers, argc);
	if (argc == 2)
		free(numbers);
	if (ret_dupe != 0 || ret_number != 0)
		return (1);
	return (0);
}
