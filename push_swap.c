/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:13:31 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/20 13:54:33 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1 || check_input(argv) == 1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit (1);
	}
	argc++;
	return (0);
}

int	check_input(char **argv)
{
	int		i;
	int		is_nb;
	long	tmp;

	i = 1;
	while (argv[i])
	{
		is_nb = 0;
		if (argv[i][is_nb] == '-')
			is_nb++;
		while (argv[i][is_nb])
		{
			if (argv[i][is_nb] < '0' || argv[i][is_nb] > '9')
			{
				return (1);
			}
			is_nb++;
		}
		tmp = ft_atoi(argv[i]);
		if (tmp > INT32_MAX || tmp < INT32_MIN)
			return (1);
		i++;
	}
	return (0);
}
