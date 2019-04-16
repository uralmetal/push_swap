/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:17:41 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/16 16:31:44 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int		push_swap_handler(const char *command, t_int_stack *a, t_int_stack *b)
{
	if (a == NULL || a->arr == NULL || b == NULL || b->arr == NULL)
		return (0);
	if (ft_strcmp(command, "sa") == 0)
		return (push_swap_sa(a));
	else if (ft_strcmp(command, "sb") == 0)
		return (push_swap_sa(b));
	else if (ft_strcmp(command, "ss") == 0)
		return (push_swap_ss(a, b));
	else if (ft_strcmp(command, "pa") == 0)
		return (push_swap_pa(a, b));
	else if (ft_strcmp(command, "pb") == 0)
		return (push_swap_pb(a, b));
	else if (ft_strcmp(command, "ra") == 0)
		return (push_swap_ra(a));
	else if (ft_strcmp(command, "rb") == 0)
		return (push_swap_rb(b));
	else if (ft_strcmp(command, "rr") == 0)
		return (push_swap_rr(a, b));
	else if (ft_strcmp(command, "rra") == 0)
		return (push_swap_rra(a));
	else if (ft_strcmp(command, "rrb") == 0)
		return (push_swap_rrb(b));
	else if (ft_strcmp(command, "rrr") == 0)
		return (push_swap_rrr(a, b));
	return (0);
}
