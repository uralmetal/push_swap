/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:06:22 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 11:07:22 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int     push_swap_ra(t_int_stack *a)
{
	return (stack_rotate(a));
}

int     push_swap_rb(t_int_stack *b)
{
	return (stack_rotate(b));
}

int     push_swap_rr(t_int_stack *a, t_int_stack *b)
{
	return (stack_rotate(a) & stack_rotate(b));
}
