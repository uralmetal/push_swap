/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:39:48 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/16 15:00:48 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

int 	get_aver_med(t_int_stack *stack, int begin, int end)
{
//	t_int_stack *temp;
	int		med;
	long	sum;
	int		i;
	int		nul;

	i = begin;
	sum = 0;
	nul = 0;
	while (i < end)
	{
		sum += stack->arr[INDEX(i, stack)];
		if (stack->arr[INDEX(i, stack)] == 0)
			nul = 1;
		i++;
	}
	if (nul == 0)
		med = (int)(sum / (end - begin));
	else
		med = (int)(sum / (end - begin - 1));
	return (med);
}

int 	qs_move(t_int_stack *a, t_int_stack *b, int ref_value, int debug_level)
{
	unsigned int i;
	unsigned int size;
	int ret;

	i = 0;
	ret = 0;
	size = a->size;
	while (i < size && a->size != 4 && (ret < (int)(size - ref_value)))
	{
		if (FIRST(a) >= ref_value && FIRST(a) > 3)
		{
			PB(debug_level)
			ret++;
		}
		else
			RA(debug_level);
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

void	sort_3_elem_2(t_int_stack *a, t_int_stack *b, int debug_level)
{
	if (FIRST(a) == 1 && SECOND(a) == 3)
	SA(debug_level)
	if (FIRST(a) == 3)
	{
		if(SECOND(a) == 1)
		RA(debug_level)
		else
		SA(debug_level)
	}
	if (FIRST(a) == 2)
	{
		if (SECOND(a) == 3)
		RRA(debug_level)
		else
		SA(debug_level)
	}
}

void	sort_4_elem(t_int_stack *a, t_int_stack *b, int debug_level)
{
	if (FIRST(a) == 0)
	{
		PB(debug_level);
		sort_3_elem_2(a, b, debug_level);
		PA(debug_level);
		return ;
	}
	if (FIRST(a) == 3)
	{
		PB(debug_level);
		sort_3_elem(a, b, debug_level);
		PA(debug_level);
		RA(debug_level);
		return ;
	}
	if (SECOND(a) == 0 || SECOND(a) == 3)
	{
		SA(debug_level);
	}
	else if (LAST(a) == 0 || LAST(a) == 3)
		RRA(debug_level);
	sort_4_elem(a, b, debug_level);
}

int		pre_sort_a(t_int_stack *a, t_int_stack *b, int debug_level, int *size)
{
	int ret;
	int moved;

	ret = 0;
	moved = 1;
	if (*size == 0 || a->size == 0)
		return (0);
	while (moved && *size > 0)
	{
		moved = 0;
		if (a->size > 1 && (LAST(a) + 1) == SECOND(a))
			SA(debug_level);
		if ((LAST(a) + 1) == FIRST(a))
		{
			moved = 1;
			*size -= 1;
			RA(debug_level);
			continue ;
		}
	}
	return (ret);
}

int		pre_sort_b(t_int_stack *a, t_int_stack *b, int debug_level, int *size)
{
	int ret;
	int moved;

	ret = 0;
	moved = 1;
	if (*size == 0 || b->size == 0)
		return (0);
	while (moved && *size > 0)
	{
		moved = 0;
		if (b->size > 1 && (LAST(a) + 1) == SECOND(b))
			SB(debug_level);
		if ((LAST(a) + 1) == FIRST(b))
		{
			moved = 1;
			*size -= 1;
			PA(debug_level);
			RA(debug_level);
			continue ;
		}
		if (b->size > 1 && (LAST(a) + *size) == SECOND(b))
			SB(debug_level);
		if ((LAST(a) + *size) == FIRST(b))
		{
			moved = 1;
			*size -= 1;
			ret++;
			PA(debug_level);
			continue ;
		}
	}
	return (ret);
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
	while (a->size > 4)
	{
		med = get_aver_med(a, 0, a->size);
		if (med == 50)
			med = 62;
		if (med == 31)
			med = 37;
		number = qs_move(a, b, med, debug_level);
		stack_put(move_number, number);
	}
	if (a->size == 4)
		sort_4_elem(a, b, debug_level);
	else
		sort_3_elem(a, b, debug_level);
	if (debug_level == 2)
		stack_print(*move_number);
	while (move_number->size != 0)
	{
		number = stack_pull(move_number);
		i = pre_sort_b(a, b, debug_level, &number);
		qs_sort_b(a, b, number, debug_level);
		while (i > 0)
		{
			RA(debug_level);
			i--;
		}
		if (debug_level == 2)
			stack_print(*move_number);
	}
	stack_deinit(&move_number);
}
