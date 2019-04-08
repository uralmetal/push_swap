/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:04:37 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/03 16:33:42 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int     push_swap_pa(t_int_stack *a, t_int_stack *b)
{
	int temp;

	if (b->size == 0)
		return (0);
	temp = stack_pull(b);
	return stack_put(a, temp);
}

int     push_swap_pb(t_int_stack *a, t_int_stack *b)
{
	int temp;

	if (a->size == 0)
		return (0);
	temp = stack_pull(a);
	return stack_put(b, temp);
}
