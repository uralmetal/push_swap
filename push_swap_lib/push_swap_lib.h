/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:20:58 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 15:54:09 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_LIB_H
# define _PUSH_SWAP_LIB_H

# include "../stack/stack.h"
# include <stdio.h>

# define INT_MIN (-2147483648)
# define INT_MAX (2147483647)

//sa sb ss pa pb ra rb rr rra rrb rrr
int     push_swap_init(int argc, char **argv, t_int_stack **a, t_int_stack **b);
int 	push_swap_handler(const char *command, t_int_stack *a, t_int_stack *b);
void	push_swap_print(const char *header, t_int_stack *a, t_int_stack *b);
int     push_swap_sa(t_int_stack *a);
int     push_swap_sb(t_int_stack *b);
int     push_swap_ss(t_int_stack *a, t_int_stack *b);
int     push_swap_pa(t_int_stack *a, t_int_stack *b);
int     push_swap_pb(t_int_stack *a, t_int_stack *b);
int     push_swap_ra(t_int_stack *a);
int     push_swap_rb(t_int_stack *b);
int     push_swap_rr(t_int_stack *a, t_int_stack *b);
int     push_swap_rra(t_int_stack *a);
int     push_swap_rrb(t_int_stack *b);
int     push_swap_rrr(t_int_stack *a, t_int_stack *b);
void    push_swap_deinit(t_int_stack **a, t_int_stack **b);

#endif
