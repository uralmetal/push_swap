/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:35:22 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/05 19:48:05 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_SORT_H
# define _PUSH_SWAP_SORT_H

#include "push_swap_lib.h"

#define INDEX(i,s) ((s->size) - 1 - (i))

void	push_swap_sort(t_int_stack *a, t_int_stack *b, int debug_level);
void 	qs(int *s_arr, int first, int last);
int 	get_aver_med(t_int_stack *stack, int begin, int end);
void	qs_sort_stack(t_int_stack *a, t_int_stack *b, int debug_level);
void 	qs_sort_b(t_int_stack *a, t_int_stack *b, int size, int debug_level);
//int		qs_sort_push_min(t_int_stack *a, t_int_stack *b, int *size,
//					 int debug_level);
//int		qs_sort_push_max(t_int_stack *a, t_int_stack *b, int *size,
//					  int debug_level);
void 	hui_sort(t_int_stack *a, t_int_stack *b, int num, int debug_level);
void	qs_sort_a(t_int_stack *a, t_int_stack *b, int size, int debug_level);
#endif //_PUSH_SWAP_SORT_H
