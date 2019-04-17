/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:18:02 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 09:44:34 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "push_swap_sort.h"
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

static void	selection(int *array, int length)
{
	int	max;
	int	i;
	int	temp;

	while (length > 0)
	{
		max = 0;
		i = 1;
		while (i < length)
		{
			if (array[i] > array[max])
				max = i;
			i++;
		}
		temp = array[length - 1];
		array[length - 1] = array[max];
		array[max] = temp;
		length--;
	}
}

static void	indexing(t_int_stack *a)
{
	int				*sort;
	unsigned int	i;
	unsigned int	j;

	sort = (int*)malloc(sizeof(int) * a->size);
	ft_memcpy(sort, a->arr, sizeof(int) * a->size);
	selection(sort, a->size);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (sort[i] == a->arr[j])
			{
				a->arr[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sort);
}

int			main(int argc, char **argv)
{
	t_int_stack	*a;
	t_int_stack	*b;
	int			debug_level;

	debug_level = 1;
	if (argc <= 1)
		return (0);
	if (push_swap_init(argc, argv, &a, &b) == 0)
	{
		ft_putendl_fd("Error", 2);
		push_swap_deinit(&a, &b);
		return (0);
	}
	indexing(a);
	if (debug_level == 2)
		push_swap_print("Init", a, b);
	qs_sort_stack(a, b, debug_level);
	if (debug_level == 2)
		push_swap_print("Sort", a, b);
	push_swap_deinit(&a, &b);
	return (0);
}
