/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:39:48 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/01 20:30:17 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

int 	get_aver_med(t_int_stack *stack, int begin, int end)
{
	t_int_stack *temp;
	int med;
	int ret;

	stack_copy(&temp, stack);
	qs(temp->arr, INDEX(end,stack), INDEX(begin,stack));
//	stack_print(*temp);
	med = (INDEX(end,stack) + INDEX(begin,stack)) / 2;
	ret = temp->arr[med];
	stack_deinit(&temp);
	return (ret);
}

void 	qs_move(t_int_stack *a, t_int_stack *b, int ref_value)
{
	unsigned int i;
	unsigned int size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		if (FIRST(a) >= ref_value)
			push_swap_pb(a, b);
		push_swap_ra(a);
		i++;
	}
}

void	sort(t_int_stack *a)
{

}

void	qs_sort_stack(t_int_stack *a, t_int_stack *b)
{
	int med;

	while (a->size > 3)
	{
		med = get_aver_med(a, 0, a->size - 1);
		qs_move(a, b, med);
		push_swap_print("moving", a, b);
	}

}
