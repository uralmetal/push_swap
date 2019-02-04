/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:07:26 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 11:16:08 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int     push_swap_rra(t_int_stack *a)
{
	return (stack_rev_rotate(a));
}

int     push_swap_rrb(t_int_stack *b)
{
	return (stack_rev_rotate(b));
}

int     push_swap_rrr(t_int_stack *a, t_int_stack *b)
{
	return (stack_rev_rotate(a) & stack_rev_rotate(b));
}
