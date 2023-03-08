/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:49:10 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/08 14:39:09 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*build_array(char **argv, int argc, int *len)
{
	int		index;
	int		*ret;
	char	**numbers;

	index = -1;
	*len = argc - 1;
	numbers = argv;
	if (argc == 2)
	{
		numbers = ft_split(numbers[1], ' ');
		*len = 0;
		while (numbers[++*len])
			;
	}
	else
		numbers++;
	ret = (int *)malloc(sizeof(int) * (*len));
	if (!ret)
		return (NULL);
	while (++index < *len)
		ret[index] = (int) ft_atoi(numbers[index]);
	if (argc == 2)
		free (numbers);
	return (ret);
}

int	*replace_numbers(int *input, int *sorted, int len)
{
	int	index;
    int	j;

	sorted = bubble_sort(sorted, len);
	index = 0;
	while (index < len)
	{
		j = 0;
		while (j < len)
		{
			if (input[index] == sorted[j])
			{
				input[index] = j;
				break ;
			}
			j++;
		}
		index++;
	}
	return (input);
}

int	*bubble_sort(int *array, int len)
{
	int			i;
	int			j;
	int			temp;

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
	return (array);
}
