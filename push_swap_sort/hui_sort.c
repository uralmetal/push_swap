/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hui_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:43:30 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/05 20:03:02 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

void hui_sort(t_int_stack *a, t_int_stack *b, int num, int debug_level)
{
	int min;
	int max;
	int i;
	int trig;

	max = a->size + num - 1;
	min = a->size;
	while (num != 0)
	{
		trig = 0;
		while (b->size > 0 && (FIRST(b) == min))
		{
			PA(debug_level);
			RA(debug_level);
			min++;
			num--;
			trig = 1;
		}
		while (b->size > 0 && (FIRST(b) == max))
		{
			PA(debug_level)
			max -= 1;
			num--;
			trig = 1;
		}
		if (trig == 0)
		{
			i++;
			if (i <= num && i > 0)
				RB(debug_level)
			else if (i <= 0)
				RRB(debug_level)
			else
			{
				i *= -1;
				RRB(debug_level);
			}
		}
	}
	while (max < a->size - 1)
	{
		RA(debug_level);
		max++;
	}
}