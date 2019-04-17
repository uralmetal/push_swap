/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:33:11 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 09:36:44 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

void		sort_3_elem(t_int_stack *a, t_int_stack *b, int debug_level)
{
	if (FIRST(a) == 0 && SECOND(a) == 2)
		SA(debug_level);
	if (FIRST(a) == 2)
	{
		if (SECOND(a) == 0)
		{
			RA(debug_level);
		}
		else
			SA(debug_level);
	}
	if (FIRST(a) == 1)
	{
		if (SECOND(a) == 2)
		{
			RRA(debug_level);
		}
		else
			SA(debug_level);
	}
}

static void	sort_3_elem_2(t_int_stack *a, t_int_stack *b, int debug_level)
{
	if (FIRST(a) == 1 && SECOND(a) == 3)
		SA(debug_level);
	if (FIRST(a) == 3)
	{
		if (SECOND(a) == 1)
		{
			RA(debug_level);
		}
		else
			SA(debug_level);
	}
	if (FIRST(a) == 2)
	{
		if (SECOND(a) == 3)
		{
			RRA(debug_level);
		}
		else
			SA(debug_level);
	}
}

void		sort_4_elem(t_int_stack *a, t_int_stack *b, int debug_level)
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
