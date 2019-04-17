/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elem_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:36:55 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 13:17:14 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

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
