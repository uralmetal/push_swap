/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 22:18:57 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/03 12:53:59 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_put(t_int_stack *stack, int value)
{
	if (stack == NULL || stack->arr == NULL)
		return (0);
	stack->arr[(stack->size++)] = value;
	if ((stack->size % STACK_STEP) == 0)
		return (stack_resize(stack, stack->size + STACK_STEP));
	return (1);
}
