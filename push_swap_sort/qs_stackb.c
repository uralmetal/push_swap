/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_stackb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:44:30 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/08 09:03:02 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

static int count;

int 	qs_move_b(t_int_stack *a, t_int_stack *b, int ref_value, int *size,
		int debug_level)
{
	unsigned int i;
	int ret;
	int end;

	i = 0;
	ret = 0;
	end = *size;
	while (i < end)
	{
		if (FIRST(b) >= ref_value)
		{
			PA(debug_level)
			*size -= 1;
		}
		else
		{
			RB(debug_level)
			ret++;
		}
		i++;
	}
	return (ret);
}

int 	qs_move_b_rev(t_int_stack *a, t_int_stack *b, int ref_value, int *size,
				 int debug_level)
{
	unsigned int i;
	int ret;
	int end;

	i = 0;
	ret = 0;
	end = *size;
	while (i < end)
	{
		RRB(debug_level)
		if (FIRST(b) >= ref_value)
		{
			PA(debug_level)
			*size -= 1;
		}
		i++;
	}
	return (ret);
}

void	sort_2_b(t_int_stack *a, t_int_stack *b, int debug_level)
{
	if (FIRST(b) > SECOND(b))
	{
		PA(debug_level);
		PA(debug_level);
		RA(debug_level);
		RA(debug_level);
	}
	else
	{
		PA(debug_level);
		RA(debug_level);
		PA(debug_level);
		RA(debug_level);
	}
}

void	sort_3_b(t_int_stack *a, t_int_stack *b, int debug_level)
{
	if (!(MAX_3(b) || MIN_3(b)))
		SB(debug_level);
	if (MIN_3(b))
	{
		PA(debug_level);
		RA(debug_level);
		sort_2_b(a, b, debug_level);
	}
	else
	{
		PA(debug_level);
		sort_2_b(a, b, debug_level);
		RA(debug_level);
	}
}

void	qs_sort_b(t_int_stack *a, t_int_stack *b, int size, int debug_level)
{
	int med;
	t_int_stack *move_number;
	t_int_stack *rev_number;
	int num_b;
	int i;

	count = 0;
	//end
	if (size <= 3)
	{
		if (size == 3)
			sort_3_b(a, b, debug_level);
		else if (size == 2)
			sort_2_b(a, b, debug_level);
		else
		{
			PA(debug_level);
			RA(debug_level);
		}
		return ;
	}
	//
	move_number = stack_init();
	rev_number = stack_init();
	while (size > 3)
	{
		med = get_aver_med(b, 0, size);
		i = size;
		num_b = qs_move_b(a, b, med, &size, debug_level);
		stack_put(move_number, i - size);
		stack_put(rev_number, num_b);
		if (size > 3)
		{
			med = get_aver_med(b, b->size - size - 1, b->size - 1);
			i = size;
			num_b = qs_move_b_rev(a, b, med, &size, debug_level);
			stack_put(move_number, i - size);
			stack_put(rev_number, num_b);
		}
	}
	if (debug_level == 2)
		stack_print(*rev_number);
	if (debug_level == 2)
		stack_print(*move_number);
	i = 0;
	num_b = stack_pull(rev_number);
	while (i < num_b)
	{
		RRB(debug_level);
		i++;
	}
	qs_sort_b(a, b, size, debug_level); // handle 3 <= elements
	if (debug_level == 2)
		stack_print(*move_number);
	while (move_number->size != 0)
	{
		num_b = stack_pull(move_number);
		i = 0;
		while (i < num_b)
		{
			PB(debug_level);
			i++;
		}
		qs_sort_b(a, b, num_b, debug_level);
	}
	stack_deinit(&move_number);
}
