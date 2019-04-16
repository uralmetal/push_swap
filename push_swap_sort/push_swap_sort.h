/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:35:22 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/16 17:24:33 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_SORT_H
# define _PUSH_SWAP_SORT_H

# include "push_swap_lib.h"

# define INDEX(i,s) ((s->size) - 1 - (i))

int		get_aver_med(t_int_stack *stack, int begin, int end);
void	qs_sort_stack(t_int_stack *a, t_int_stack *b, int debug_level);
void	qs_sort_b(t_int_stack *a, t_int_stack *b, int size, int debug_level);
void	qs_sort_a(t_int_stack *a, t_int_stack *b, int size, int debug_level);
int		search_max(t_int_stack *stack, unsigned int len);
int		search_min(t_int_stack *stack, unsigned int len);
void	sort_2_a(t_int_stack *a, t_int_stack *b, int debug_level);
void	sort_2_b(t_int_stack *a, t_int_stack *b, int debug_level);
int		pre_sort_a(t_int_stack *a, t_int_stack *b, int debug_level, int *size);
int		pre_sort_b(t_int_stack *a, t_int_stack *b, int debug_level, int *size);

#endif
