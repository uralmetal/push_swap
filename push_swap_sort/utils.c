/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:41:16 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/16 17:22:43 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

int		search_max(t_int_stack *stack, unsigned int len)
{
	unsigned int	i;
	int				max;

	if (len == 0 || stack->size == 0)
		return (0);
	if (len == 1 || stack->size == 1)
		return (FIRST(stack));
	i = 1;
	max = stack->arr[INDEX(0, stack)];
	while ((i < stack->size) && (i < len))
	{
		if (stack->arr[INDEX(i, stack)] > max)
			max = stack->arr[INDEX(i, stack)];
		i++;
	}
	return (max);
}

int		search_min(t_int_stack *stack, unsigned int len)
{
	unsigned int	i;
	int				min;

	if (len == 0 || stack->size == 0)
		return (0);
	if (len == 1 || stack->size == 1)
		return (FIRST(stack));
	i = 1;
	min = stack->arr[INDEX(0, stack)];
	while ((i < stack->size) && (i < len))
	{
		if (stack->arr[INDEX(i, stack)] < min)
			min = stack->arr[INDEX(i, stack)];
		i++;
	}
	return (min);
}
