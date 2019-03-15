/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:56:09 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/20 11:18:20 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_H
# define _STACK_H

# include "../libft/libft.h"

# define STACK_STEP 1
# if STACK_STEP < 1
#  error STACK_STEP must be >= 1
# endif

# define CH_NULL(x) if((x) == NULL) exit (-1);
# define DEBUG_PRINT(lvl,print) DEBUG_LVL_1(lvl,print) DEBUG_LVL_2(lvl, print)
# define DEBUG_LVL_1(lvl,print) if((lvl) == 1) {printf("%s\n", print);}
# define DEBUG_LVL_2(lvl, print) if((lvl) == 2) {push_swap_print(print, a, b);}
# define FIRST(stack) ((stack)->arr[(stack)->size - 1])
# define SECOND(stack) ((stack)->arr[(stack)->size - 2])
# define LAST(stack) ((stack)->arr[0])

typedef struct		s_int_stack
{
	int				*arr;
	unsigned int	size;
}					t_int_stack;

t_int_stack			*stack_init(void);
int					stack_resize(t_int_stack *stack, unsigned int new_size);
int					stack_put(t_int_stack *stack, int value);
int					stack_pull(t_int_stack *stack);
int					stack_rotate(t_int_stack *stack);
int					stack_rev_rotate(t_int_stack *stack);
int 				stack_swap(t_int_stack *stack);
void				stack_print(t_int_stack stack);
t_int_stack 		*stack_copy(t_int_stack **dst, t_int_stack *src);
void				stack_deinit(t_int_stack **stack);

#endif
