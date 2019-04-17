/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:16:49 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 13:18:38 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

static void	sort_4_split_a(t_int_stack *a, t_int_stack *b, int max,
		int debug_level)
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

static void	sort_4_split_b(t_int_stack *a, t_int_stack *b, int max,
		int debug_level)
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

static int	sort_4_mm(t_stacks s, int min, int max, int debug_level)
{
	t_int_stack *a;
	t_int_stack *b;

	a = s.a;
	b = s.b;
	((SECOND(b) == min) && (FIRST(b) != max)) ? (SB(debug_level)) : (0);
	((SECOND(b) == max) && (FIRST(b) != min)) ? (SB(debug_level)) : (0);
	if (FIRST(b) == min)
	{
		PA(debug_level);
		RA(debug_level);
		sort_3_b(a, b, debug_level);
		return (1);
	}
	if (FIRST(b) == max)
	{
		PA(debug_level);
		sort_3_b(a, b, debug_level);
		RA(debug_level);
		return (1);
	}
	PA(debug_level);
	PA(debug_level);
	return (0);
}

void		sort_4_b(t_int_stack *a, t_int_stack *b, int debug_level)
{
	int			min;
	int			max;
	t_stacks	stacks;

	min = search_min(b, 4);
	max = search_max(b, 4);
	stacks.a = a;
	stacks.b = b;
	if (sort_4_mm(stacks, min, max, debug_level))
		return ;
	(FIRST(a) > SECOND(a) && FIRST(b) > SECOND(b)) ? (SS(debug_level)) : (0);
	(FIRST(a) > SECOND(a)) ? (SA(debug_level)) : (0);
	(FIRST(b) > SECOND(b)) ? (SB(debug_level)) : (0);
	if (FIRST(a) == min)
	{
		RA(debug_level);
		sort_4_split_a(a, b, max, debug_level);
	}
	else if (FIRST(b) == min)
	{
		PA(debug_level);
		RA(debug_level);
		sort_4_split_b(a, b, max, debug_level);
	}
}
