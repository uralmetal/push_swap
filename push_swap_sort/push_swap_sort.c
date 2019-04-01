/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:52:41 by rwalder-          #+#    #+#             */
/*   Updated: 2019/03/31 16:46:36 by rwalder-         ###   ########.fr       */
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

static int sorting(t_int_stack *a, t_int_stack *b, int debug_level)
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
	i = 0;
	while (check_sort(a) == 0)
	{
		if (FIRST(a) == min && SECOND(a) == max)
		{
			stack_swap(a);
			DEBUG_PRINT(debug_level, "sa");
			i++;
			if (check_sort(a) == 1)
				break ;
		}
		else if ((FIRST(a) == max) && (a->arr[a->size - 3] == min))
		{
			stack_swap(a);
			DEBUG_PRINT(debug_level, "sa");
			i++;
			if (check_sort(a) == 1)
				break ;
		}
		else if (FIRST(a) > SECOND(a) && !(FIRST(a) == max && SECOND(a) == min))
		{
			stack_swap(a);
			DEBUG_PRINT(debug_level, "sa");
			i++;
			if (check_sort(a) == 1)
				break ;
		}
		stack_rev_rotate(a);
		DEBUG_PRINT(debug_level, "rra");
		i++;
	}
	return (i);
}

void		push_swap_sort(t_int_stack *a, t_int_stack *b, int debug_level)
{
	t_int_stack *temp;
	int a1;
	int a2;

	//printf("%i %i %i\n", FIRST(a), SECOND(a), LAST(a));
	//if (a->size <= 10)
//	a1 = get_aver_med(a, 0, 4);
	qs_sort_stack(a,b);
//	qs(a->arr, 0, a->size - 1);
	//a1 = sorting(a, b, debug_level);
	//printf("iter %i\n", a1);
}