/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elem_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:11:37 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 11:33:42 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

void	sort_2_a(t_int_stack *a, t_int_stack *b, int debug_level)
{
	if (FIRST(a) > SECOND(a))
		SA(debug_level);
	RA(debug_level);
	RA(debug_level);
}

void	sort_3_a(t_int_stack *a, t_int_stack *b, int debug_level)
{
	if (!(MAX_3(a) || MIN_3(a)))
		SA(debug_level);
	if (MIN_3(a))
	{
		RA(debug_level);
		sort_2_a(a, b, debug_level);
	}
	else
	{
		PB(debug_level);
		sort_2_a(a, b, debug_level);
		PA(debug_level);
		RA(debug_level);
	}
}

void	sort_4_split(t_int_stack *a, t_int_stack *b, int max, int debug_level)
{
	if (FIRST(a) > SECOND(a) && FIRST(b) > SECOND(b))
		SS(debug_level);
	if (FIRST(a) > SECOND(a))
		SA(debug_level);
	if (FIRST(b) > SECOND(b))
		SB(debug_level);
	RA(debug_level);
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

void	sort_4_a(t_int_stack *a, t_int_stack *b, int debug_level)
{
	int min;
	int max;

	min = search_min(a, 4);
	max = search_max(a, 4);
	if (SECOND(a) == min)
		SA(debug_level);
	if (FIRST(a) == min)
	{
		RA(debug_level);
		sort_3_a(a, b, debug_level);
		return ;
	}
	PB(debug_level);
	PB(debug_level);
	sort_4_split(a, b, max, debug_level);
}
