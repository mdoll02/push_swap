/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:49:10 by mdoll             #+#    #+#             */
/*   Updated: 2023/03/08 14:08:26 by mdoll            ###   ########.fr       */
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
	ret = (int *)malloc(sizeof(int) * (*len - 1));
	if (!ret)
		return (NULL);
	while (++index < *len)
		ret[index] = (int) ft_atoi(numbers[index]);
	if (argc == 2)
		free (numbers);
	return (ret);
}

#define CHECK_ARRAY(msg, array) \
{ \
	int index = 0;\
	while (array[index])\
	{\
		printf(#msg": %d\n", array[index]);\
		index++;\
	}\
}                               \//TODO: REMOVE

void	bubble_sort(int *array, int len)
{
	int			i;
	int			j;
	int			temp;

	i = 0;
	printf("len: %d\n", len);
	CHECK_ARRAY(before bubble sort, array)
	while (i < len - 1)
	{
		j = i;
		while (j < len - 1)
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
	CHECK_ARRAY(bubble sort, array)
}
