/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:22:20 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 16:20:29 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

int		qs_move_a(t_stacks s, int ref_value, int *size, int debug_level)
{
	int			i;
	int			ret;
	int			end;
	t_int_stack	*a;
	t_int_stack	*b;

	i = -1;
	ret = 0;
	end = *size;
	a = s.a;
	b = s.b;
	while (++i < end)
	{
		if (FIRST(a) > ref_value)
		{
			PB(debug_level);
			*size -= 1;
		}
		else
		{
			RA(debug_level);
			ret++;
		}
	}
	return (ret);
}

int		qs_move_a_rev(t_stacks s, int ref_value, int *size, int debug_level)
{
	int			i;
	int			ret;
	int			end;
	t_int_stack	*a;
	t_int_stack	*b;

	i = 0;
	ret = 0;
	end = *size;
	a = s.a;
	b = s.b;
	while (i < end)
	{
		RRA(debug_level);
		if (FIRST(a) > ref_value)
		{
			PB(debug_level);
			*size -= 1;
		}
		i++;
	}
	return (ret);
}

int		qs_move_b(t_stacks s, int *size, int *sort, int debug_level)
{
	int			i;
	int			ret;
	int			end;
	t_int_stack	*a;
	t_int_stack	*b;

	INIT_MOVE_B;
	while (++i < end)
	{
		if ((LAST(a) + 1) == FIRST(b))
		{
			TO_BOT_A;
		}
		else if (FIRST(b) > s.ref_value)
		{
			PA(debug_level);
			*size -= 1;
		}
		else
		{
			RB(debug_level);
			ret++;
		}
	}
	return (ret);
}

int		qs_move_b_rev(t_stacks s, int ref_value, int *size, int debug_level)
{
	int			i;
	int			sort;
	int			end;
	t_int_stack	*a;
	t_int_stack	*b;

	INIT_REV_B;
	while (++i < end)
	{
		RRB(debug_level);
		if ((LAST(a) + 1) == FIRST(b))
		{
			*size -= 1;
			sort += 1;
			PA(debug_level);
			RA(debug_level);
		}
		else if (FIRST(b) > ref_value)
		{
			PA(debug_level);
			*size -= 1;
		}
	}
	return (sort);
}
