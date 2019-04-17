/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_stackb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:44:30 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 15:08:50 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

static int			end(t_int_stack *a, t_int_stack *b, int size,
		int debug_level)
{
	if (size <= 4)
	{
		if (size == 4)
			sort_4_a(a, b, debug_level);
		else if (size == 3)
			sort_3_a(a, b, debug_level);
		else if (size == 2)
			sort_2_a(a, b, debug_level);
		else if (size == 1)
		{
			RA(debug_level);
		}
		return (1);
	}
	return (0);
}

static t_int_stack	*a_to_b(t_stacks s, int *size, t_int_stack **move_number,
		int debug_level)
{
	t_int_stack	*rev_number;
	int			med;
	int			i;
	int			num_b;

	*move_number = stack_init();
	rev_number = stack_init();
	while (*size > 4)
	{
		med = get_aver_med(s.a, 0, *size);
		i = *size;
		num_b = qs_move_a(s, med, size, debug_level);
		stack_put(*move_number, i - *size);
		stack_put(rev_number, num_b);
		if (*size > 4)
		{
			med = get_aver_med(s.a, s.a->size - *size, s.a->size);
			i = *size;
			num_b = qs_move_a_rev(s, med, size, debug_level);
			stack_put(*move_number, i - *size);
			stack_put(rev_number, num_b);
		}
	}
	return (rev_number);
}

static void			rev_a(t_stacks s, t_int_stack *rev_number, int debug_level)
{
	int			i;
	int			num_b;
	t_int_stack	*a;
	t_int_stack	*b;

	i = 0;
	a = s.a;
	b = s.b;
	num_b = stack_pull(rev_number);
	while (i < num_b)
	{
		RRA(debug_level);
		i++;
	}
}

void				qs_sort_a(t_int_stack *a, t_int_stack *b, int size,
		int debug_level)
{
	t_int_stack	*move_number;
	t_int_stack	*rev_number;
	int			rev;
	t_stacks	s;

	if (end(a, b, size, debug_level))
		return ;
	s.a = a;
	s.b = b;
	rev = pre_sort_a(a, b, debug_level, &size) + 1;
	move_number = NULL;
	rev_number = a_to_b(s, &size, &move_number, debug_level);
	(debug_level == 2) ? (stack_print(*rev_number)) : (0);
	(debug_level == 2) ? (stack_print(*move_number)) : (0);
	rev_a(s, rev_number, debug_level);
	qs_sort_a(a, b, size, debug_level);
	(debug_level == 2) ? (stack_print(*move_number)) : (0);
	while (move_number->size != 0)
		qs_sort_b(a, b, stack_pull(move_number), debug_level);
	while (--rev > 0)
	{
		PA(debug_level);
		RA(debug_level);
	}
	FREE_NUMBER;
}
