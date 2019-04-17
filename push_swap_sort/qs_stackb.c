/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_stackb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:44:30 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 16:22:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

static int			end(t_int_stack *a, t_int_stack *b, int size,
		int debug_level)
{
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
		return (1);
	}
	return (0);
}

static t_int_stack	*a_to_b(t_stacks s, int *size, t_int_stack **move_number,
		int debug_level)
{
	int			med;
	int			sort;
	t_int_stack	*rev_number;
	int			i;
	int			num_b;

	*move_number = stack_init();
	rev_number = stack_init();
	while (*size > 4)
	{
		med = get_aver_med(s.b, 0, *size);
		WANT_25_STR;
		num_b = qs_move_b(s, size, &sort, debug_level);
		stack_put(*move_number, i - *size - sort);
		stack_put(rev_number, num_b);
		if (*size > 4)
		{
			med = get_aver_med(s.b, s.b->size - *size, s.b->size);
			i = *size;
			sort = qs_move_b_rev(s, med, size, debug_level);
			stack_put(*move_number, i - *size - sort);
			stack_put(rev_number, 0);
		}
	}
	return (rev_number);
}

static void			rev_b(t_stacks s, t_int_stack *rev_number, int debug_level)
{
	int			num_b;
	int			i;
	t_int_stack	*a;
	t_int_stack	*b;

	i = 0;
	a = s.a;
	b = s.b;
	num_b = stack_pull(rev_number);
	while (i < num_b && (b->size > 4))
	{
		RRB(debug_level);
		i++;
	}
}

void				qs_sort_b(t_int_stack *a, t_int_stack *b, int size,
		int debug_level)
{
	t_int_stack	*move_number;
	t_int_stack	*rev_number;
	int			rev;
	t_stacks	s;

	if (end(a, b, size, debug_level))
		return ;
	rev = pre_sort_b(a, b, debug_level, &size) + 1;
	s.a = a;
	s.b = b;
	rev_number = a_to_b(s, &size, &move_number, debug_level);
	(debug_level == 2) ? (stack_print(*rev_number)) : (0);
	(debug_level == 2) ? (stack_print(*move_number)) : (0);
	rev_b(s, rev_number, debug_level);
	qs_sort_b(a, b, size, debug_level);
	(debug_level == 2) ? (stack_print(*move_number)) : (0);
	while (move_number->size != 0)
		qs_sort_a(a, b, stack_pull(move_number), debug_level);
	while (--rev > 0)
	{
		RA(debug_level);
	}
	FREE_NUMBER;
}
