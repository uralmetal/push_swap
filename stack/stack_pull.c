/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:06:04 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/03 12:31:24 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_pull(t_int_stack *stack)
{
	int ret;

	if (stack == NULL || stack->arr == NULL)
		return (0);
	if (stack->size == 0)
		return (0);
	ret = stack->arr[(--stack->size)];
	if ((stack->size % STACK_STEP) == (STACK_STEP - 1))
		if (stack_resize(stack, stack->size + STACK_STEP) == 0)
			exit(-1);
	return (ret);
}
