/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:01:58 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/05 21:59:20 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_int_stack	*stack_copy(t_int_stack **dst, t_int_stack *src)
{
	*dst = stack_init();
	free((*dst)->arr);
	(*dst)->arr = (int *)malloc(sizeof(int) * (src->size + STACK_STEP));
	ft_memcpy((*dst)->arr, src->arr, src->size * sizeof(int));
	(*dst)->size = src->size;
	return (*dst);
}
