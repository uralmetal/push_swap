/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:35:22 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 16:27:13 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_SORT_H
# define _PUSH_SWAP_SORT_H

# include "push_swap_lib.h"

typedef struct		s_stacks
{
	t_int_stack		*a;
	t_int_stack		*b;
	int				ref_value;
}					t_stacks;

# define INDEX(i,s) ((s->size) - 1 - (i))
# define FREE_NUMBER {stack_deinit(&rev_number); stack_deinit(&move_number);}
# define INIT_MOVE_B i = -1; ret = 0; end = *size; *sort = 0; a = s.a; b = s.b
# define INIT_REV_B i = -1; end = *size; sort = 0; a = s.a; b = s.b
# define TO_BOT_A *size -= 1; *sort += 1; PA(debug_level); RA(debug_level);
# define WANT_25_STR i = *size; s.ref_value = med

int					get_aver_med(t_int_stack *stack, int begin, int end);
int					qs_move_a(t_stacks s, int ref_value, int *size,
		int debug_level);
int					qs_move_a_rev(t_stacks s, int ref_value, int *size,
		int debug_level);
int					qs_move_b(t_stacks s, int *size, int *sort,
		int debug_level);
int					qs_move_b_rev(t_stacks s, int ref_value, int *size,
		int debug_level);
void				qs_sort_stack(t_int_stack *a, t_int_stack *b,
		int debug_level);
void				qs_sort_b(t_int_stack *a, t_int_stack *b, int size,
		int debug_level);
void				qs_sort_a(t_int_stack *a, t_int_stack *b, int size,
		int debug_level);
int					search_max(t_int_stack *stack, unsigned int len);
int					search_min(t_int_stack *stack, unsigned int len);
void				sort_2_a(t_int_stack *a, t_int_stack *b, int debug_level);
void				sort_3_a(t_int_stack *a, t_int_stack *b, int debug_level);
void				sort_4_a(t_int_stack *a, t_int_stack *b, int debug_level);
void				sort_2_b(t_int_stack *a, t_int_stack *b, int debug_level);
void				sort_3_b(t_int_stack *a, t_int_stack *b, int debug_level);
void				sort_4_b(t_int_stack *a, t_int_stack *b, int debug_level);
void				sort_3_elem(t_int_stack *a, t_int_stack *b,
		int debug_level);
void				sort_4_elem(t_int_stack *a, t_int_stack *b,
		int debug_level);
int					pre_sort_a(t_int_stack *a, t_int_stack *b, int debug_level,
		int *size);
int					pre_sort_b(t_int_stack *a, t_int_stack *b, int debug_level,
		int *size);

#endif
