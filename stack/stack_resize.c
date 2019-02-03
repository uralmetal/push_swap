/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 22:21:28 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/03 12:31:49 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_resize(t_int_stack *stack, unsigned int new_size)
{
	int *temp;

	if (stack == NULL || stack->arr == NULL)
		return (0);
	if (stack->size == new_size)
		return (1);
	CH_NULL(temp = (int*)malloc(sizeof(int) * new_size));
	ft_memcpy(temp, stack->arr, sizeof(int) * ((new_size > stack->size) ?
	(stack->size) : (new_size)));
	ft_memdel((void**)&(stack->arr));
	stack->arr = temp;
	return (1);
}
