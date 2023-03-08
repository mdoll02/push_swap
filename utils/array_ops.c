/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:49:10 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/08 12:43:53 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*build_array(char **argv, int argc, t_array *array)
{
	int		index;
	int		shift;
	int		*ret;
	char	**numbers;

	index = -1;
	array->len = argc;
	shift = 1;
	numbers = argv;
	if (argc == 2)
	{
		numbers = ft_split(numbers[1], ' ');
		array->len = 0;
		while (numbers[++array->len])
		shift = 0;
	}
	ret = (int *)malloc(sizeof(int) * (array->len - 1));
	if (!ret)
		return (NULL);
	while (++index < array->len - shift)
		ret[index] = ft_atoi(numbers[index + shift]);
	if (argc == 2)
		free (numbers);
	return (ret);
}

void	bubble_sort(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
