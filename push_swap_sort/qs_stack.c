/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:39:48 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 09:50:42 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

int			get_aver_med(t_int_stack *stack, int begin, int end)
{
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

int			qs_move(t_int_stack *a, t_int_stack *b, int ref_value,
		int debug_level)
{
	unsigned int	i;
	unsigned int	size;
	int				ret;

	i = 0;
	ret = 0;
	size = a->size;
	while (i < size && a->size != 4 && (ret < (int)(size - ref_value)))
	{
		if (FIRST(a) >= ref_value && FIRST(a) > 3)
		{
			PB(debug_level);
			ret++;
		}
		else
			RA(debug_level);
		i++;
	}
	return (ret);
}

static void	a_to_b(t_int_stack *a, t_int_stack *b, t_int_stack *move_number,
		int debug_level)
{
	int			med;
	int			number;

	while (a->size > 4)
	{
		med = get_aver_med(a, 0, a->size);
		(med == 50) ? (med = 62) : (0);
		(med == 31) ? (med = 37) : (0);
		number = qs_move(a, b, med, debug_level);
		stack_put(move_number, number);
	}
}

void		qs_sort_stack(t_int_stack *a, t_int_stack *b, int debug_level)
{
	int			number;
	int			i;
	t_int_stack	*move_number;

	move_number = stack_init();
	if (a->size < 2)
		return ;
	a_to_b(a, b, move_number, debug_level);
	(a->size == 4) ? (sort_4_elem(a, b, debug_level)) : (sort_3_elem(a, b,
			debug_level));
	(debug_level == 2) ? (stack_print(*move_number)) : (0);
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
		(debug_level == 2) ? (stack_print(*move_number)) : (0);
	}
	stack_deinit(&move_number);
}
