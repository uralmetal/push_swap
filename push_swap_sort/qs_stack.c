/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:39:48 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/05 22:27:31 by rwalder-         ###   ########.fr       */
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

int 	qs_move(t_int_stack *a, t_int_stack *b, int ref_value, int debug_level)
{
	unsigned int i;
	unsigned int size;
	int ret;

	i = 0;
	ret = 0;
	size = a->size;
	while (i < size && a->size != 3)
	{
		if (FIRST(a) > ref_value)
		{
			PB(debug_level)
			ret++;
		}
		else
			RA(debug_level)
		i++;
	}
	return (ret);
}

void	sort_3_elem(t_int_stack *a, t_int_stack *b, int debug_level)
{
	if (FIRST(a) == 0 && SECOND(a) == 2)
		SA(debug_level)
	if (FIRST(a) == 2)
	{
		if(SECOND(a) == 0)
			RA(debug_level)
		else
			SA(debug_level)
	}
	if (FIRST(a) == 1)
	{
		if (SECOND(a) == 2)
			RRA(debug_level)
		else
			SA(debug_level)
	}
}

void	qs_sort_stack(t_int_stack *a, t_int_stack *b, int debug_level)
{
	int med;
	int number;
	int i;
	t_int_stack *move_number;

	move_number = stack_init(); //ToDo: check sort!!!
	if (a->size < 2)
		return ;
	while (a->size > 3)
	{
		med = get_aver_med(a, 0, a->size - 1);
		number = qs_move(a, b, med, debug_level);
		stack_put(move_number, number);
	}
	sort_3_elem(a, b, debug_level);
	if (debug_level == 2)
		stack_print(*move_number);
//	hui_sort(a, b, b->size, debug_level);
	while (move_number->size != 0)
	{
		number = stack_pull(move_number);
		qs_sort_b(a, b, number, debug_level);
		if (debug_level == 2)
			stack_print(*move_number);
	}
	stack_deinit(&move_number);
}
