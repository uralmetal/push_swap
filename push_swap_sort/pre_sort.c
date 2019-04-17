/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:17:16 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 09:24:49 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

int			pre_sort_a(t_int_stack *a, t_int_stack *b, int debug_level,
		int *size)
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

static int	pre_sort_b_top(t_int_stack *a, t_int_stack *b, int debug_level,
		int *size)
{
	int moved;

	moved = 0;
	if (b->size > 1 && (LAST(a) + 1) == SECOND(b))
		SB(debug_level);
	if ((LAST(a) + 1) == FIRST(b))
	{
		moved = 1;
		*size -= 1;
		PA(debug_level);
		RA(debug_level);
	}
	return (moved);
}

int			pre_sort_b(t_int_stack *a, t_int_stack *b, int debug_level,
		int *size)
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
		if (pre_sort_b_top(a, b, debug_level, size) == 1)
			continue ;
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
