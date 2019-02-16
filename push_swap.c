/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:18:02 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/15 15:27:40 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib/push_swap_lib.h"
#include "push_swap_sort/push_swap_sort.h"
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"


static void selection(int *array, int length)
{
	int max, i, temp;
	while (length > 0)
	{
		max = 0;
		for (i = 1; i < length; i++)
			if (array[i] > array[max])
				max = i;

		temp = array[length-1];
		array[length-1] = array[max];
		array[max] = temp;
		length--;
	}
}

int		main(int argc, char **argv)
{
	t_int_stack *a;
	t_int_stack *b;
	int *sort;
	int i;
	int j;
	char *com;

	if (argc <= 1)
		return (0);
	if (push_swap_init(argc, argv, &a, &b) == 0)
	{
		ft_putendl_fd("Error", 2);
		push_swap_deinit(&a, &b);
		return (0);
	}
	//indexing
	/*
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
	 */
	//
//	push_swap_print("Init", a, b);
	push_swap_sort(a, b);
//	push_swap_print("Sort", a, b);
	return (0);
}