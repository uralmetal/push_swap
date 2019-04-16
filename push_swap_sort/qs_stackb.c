/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_stackb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:44:30 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/16 15:17:09 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

static int count;

int 	qs_move_b(t_int_stack *a, t_int_stack *b, int ref_value, int *size,
		int *sort, int debug_level)
{
	int i;
	int ret;
	int end;

	i = 0;
	ret = 0;
	end = *size;
	*sort = 0;
	while (i < end)
	{
		if ((LAST(a) + 1) == FIRST(b))
		{
			*size -= 1;
			*sort += 1;
			PA(debug_level);
			RA(debug_level);
		}
		else if (FIRST(b) > ref_value)
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
				 int *sort, int debug_level)
{
	int i;
	int ret;
	int end;

	i = 0;
	ret = 0;
	end = *size;
	*sort = 0;
	while (i < end)
	{
		RRB(debug_level)
		if ((LAST(a) + 1) == FIRST(b))
		{
			*size -= 1;
			*sort += 1;
			PA(debug_level);
			RA(debug_level);
		}
		else if (FIRST(b) > ref_value)
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

void	sort_4_b(t_int_stack *a, t_int_stack *b, int debug_level)
{
	int min;
	int max;
	int size_a;
	int size_b;

	min = search_min(b, 4);
	max = search_max(b, 4);

	if ((SECOND(b) == min) && (FIRST(b) != max))
		SB(debug_level);
	if ((SECOND(b) == max) && (FIRST(b) != min))
		SB(debug_level);
	if (FIRST(b) == min)
	{
		PA(debug_level);
		RA(debug_level);
		sort_3_b(a, b, debug_level);
	}
	else if (FIRST(b) == max)
	{
		PA(debug_level);
		sort_3_b(a, b, debug_level);
		RA(debug_level);
	}
	else
	{
		PA(debug_level);
		PA(debug_level);
		size_a = 2;
		size_b = 2;
		{
			if (FIRST(a) > SECOND(a) && FIRST(b) > SECOND(b))
				SS(debug_level);
			if (FIRST(a) > SECOND(a))
				SA(debug_level);
			if (FIRST(b) > SECOND(b))
				SB(debug_level);
		}
		if (FIRST(a) == min)
		{
			RA(debug_level);
			size_a--;
		}
		else if (FIRST(b) == min)
		{
			PA(debug_level);
			RA(debug_level);
			size_b--;
		}
		if (size_a == 1)
		{
			if (FIRST(a) == max)
			{
				sort_2_b(a, b, debug_level);
				RA(debug_level);
			}
			else
			{
				PA(debug_level);
				sort_2_a(a, b, debug_level);
				PA(debug_level);
				RA(debug_level);
			}
		}
		else if (size_b == 1)
		{
			if (FIRST(b) == max)
			{
				sort_2_a(a, b, debug_level);
				PA(debug_level);
				RA(debug_level);
			}
			else
			{
				PA(debug_level);
				sort_2_a(a, b, debug_level);
				RA(debug_level);
			}
		}
	}
}

void	qs_sort_b(t_int_stack *a, t_int_stack *b, int size, int debug_level)
{
	int med;
	t_int_stack *move_number;
	t_int_stack *rev_number;
	int num_b;
	int i;
	int rev;
	int sort;

	count = 0;
	if (size <= 4)
	{
		if (size == 4)
			sort_4_b(a, b, debug_level);
		else if (size == 3)
			sort_3_b(a, b, debug_level);
		else if (size == 2)
			sort_2_b(a, b, debug_level);
		else if (size == 1)
		{
			PA(debug_level);
			RA(debug_level);
		}
		return ;
	}
	rev = pre_sort_b(a, b, debug_level, &size);
	move_number = stack_init();
	rev_number = stack_init();
	while (size > 4)
	{
		med = get_aver_med(b, 0, size);
		i = size;
		num_b = qs_move_b(a, b, med, &size, &sort, debug_level);
		stack_put(move_number, i - size - sort);
		stack_put(rev_number, num_b);
		if (size > 4)
		{
			med = get_aver_med(b, b->size - size, b->size);
			i = size;
			num_b = qs_move_b_rev(a, b, med, &size, &sort, debug_level);
			stack_put(move_number, i - size - sort);
			stack_put(rev_number, num_b);
		}
	}
	if (debug_level == 2)
		stack_print(*rev_number);
	if (debug_level == 2)
		stack_print(*move_number);
	i = 0;
	num_b = stack_pull(rev_number);
	while (i < num_b && (b->size > 4))
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
		qs_sort_a(a, b, num_b, debug_level);
	}
	while (rev > 0)
	{
		RA(debug_level);
		rev--;
	}
	stack_deinit(&rev_number);
	stack_deinit(&move_number);
}
