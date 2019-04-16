/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:44:02 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/16 16:47:36 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_LIB_H
# define _PUSH_SWAP_LIB_H

# include "stack.h"
# include <stdio.h>

# define INT_MIN (2147483648L)
# define INT_MAX (2147483647)
# define DEBUG_PRINT(lvl,print) DEBUG_LVL_1(lvl,print) DEBUG_LVL_2(lvl, print)
# define DEBUG_LVL_1(lvl,print) if((lvl) == 1) {printf("%s\n", print);}
# define DEBUG_LVL_2(lvl, print) if((lvl) == 2) {push_swap_print(print, a, b);}
# define SA(debug_lvl) {push_swap_sa(a); DEBUG_PRINT(debug_lvl, "sa")}
# define SB(debug_lvl) {push_swap_sb(b); DEBUG_PRINT(debug_lvl, "sb");}
# define SS(debug_lvl) {push_swap_ss(a, b); DEBUG_PRINT(debug_lvl, "ss");}
# define PA(debug_lvl) {push_swap_pa(a, b); DEBUG_PRINT(debug_lvl, "pa")}
# define PB(debug_lvl) {push_swap_pb(a, b); DEBUG_PRINT(debug_lvl, "pb");}
# define RA(debug_lvl) {push_swap_ra(a); DEBUG_PRINT(debug_lvl, "ra");}
# define RB(debug_lvl) {push_swap_rb(b); DEBUG_PRINT(debug_lvl, "rb");}
# define RR(debug_lvl) {push_swap_rr(a, b); DEBUG_PRINT(debug_lvl, "rr");}
# define RRA(debug_lvl) {push_swap_rra(a); DEBUG_PRINT(debug_lvl, "rra");}
# define RRB(debug_lvl) {push_swap_rrb(b); DEBUG_PRINT(debug_lvl, "rrb");}
# define RRR(debug_lvl) {push_swap_rrr(a, b); DEBUG_PRINT(debug_lvl, "rrr");}

int		push_swap_init(int argc, char **argv, t_int_stack **a, t_int_stack **b);
int		push_swap_handler(const char *command, t_int_stack *a, t_int_stack *b);
void	push_swap_print(const char *header, t_int_stack *a, t_int_stack *b);
int		push_swap_sa(t_int_stack *a);
int		push_swap_sb(t_int_stack *b);
int		push_swap_ss(t_int_stack *a, t_int_stack *b);
int		push_swap_pa(t_int_stack *a, t_int_stack *b);
int		push_swap_pb(t_int_stack *a, t_int_stack *b);
int		push_swap_ra(t_int_stack *a);
int		push_swap_rb(t_int_stack *b);
int		push_swap_rr(t_int_stack *a, t_int_stack *b);
int		push_swap_rra(t_int_stack *a);
int		push_swap_rrb(t_int_stack *b);
int		push_swap_rrr(t_int_stack *a, t_int_stack *b);
void	push_swap_deinit(t_int_stack **a, t_int_stack **b);

#endif
