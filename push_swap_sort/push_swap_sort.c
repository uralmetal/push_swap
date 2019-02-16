/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:52:41 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/16 18:10:22 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

static int	check_sort(t_int_stack *stack)
{
	int i;

	i = stack->size;
	while (--i > 1)
		if (stack->arr[i] > stack->arr[i - 1])
			return (0);
	if (stack->arr[1] > stack->arr[0])
		return (0);
	return (1);
}

void		push_swap_sort(t_int_stack *a, t_int_stack *b)
{
	int min;
	int max;
	int i;

	i = 0;
	min = a->arr[0];
	max = a->arr[0];
	while (i < a->size)
	{
		if (min > a->arr[i])
			min = a->arr[i];
		if (max < a->arr[i])
			max = a->arr[i];
		i++;
	}
	while (check_sort(a) == 0)
	{
		if (a->arr[a->size - 1] > a->arr[a->size - 2])
		{
			push_swap_sa(a);
			push_swap_print("sa", a, b);
//			printf("sa\n");
			if (check_sort(a) == 1)
				return ;
		}
		if (a->arr[a->size - 1] == min && a->arr[a->size - 2] == max)
		{
			push_swap_sa(a);
			push_swap_print("sa min & max", a, b);
//			printf("sa\n");
			if (check_sort(a) == 1)
				return ;
		}
		push_swap_rra(a);
		push_swap_print("rra", a, b);
//		printf("ra\n");
	}
}