/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:55:37 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 10:57:11 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int     push_swap_sa(t_int_stack *a)
{
	return (stack_swap(a));
}

int     push_swap_sb(t_int_stack *b)
{
	return (stack_swap(b));
}

int     push_swap_ss(t_int_stack *a, t_int_stack *b)
{
	return (stack_swap(a) & stack_swap(b));
}
