/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:41:02 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/03 12:43:50 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_rev_rotate(t_int_stack *stack)
{
	unsigned int	i;
	int				temp;

	if (stack == NULL || stack->arr == NULL)
		return (0);
	i = 0;
	temp = stack->arr[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = temp;
	return (1);
}
