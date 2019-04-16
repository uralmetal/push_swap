/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:20:44 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/16 17:20:34 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_swap(t_int_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->arr == NULL || stack->size < 2)
		return (0);
	temp = stack->arr[stack->size - 1];
	stack->arr[stack->size - 1] = stack->arr[stack->size - 2];
	stack->arr[stack->size - 2] = temp;
	return (1);
}
