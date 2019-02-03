/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:56:09 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/03 15:22:33 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_H
# define _STACK_H

# include "../libft/libft.h"

# define STACK_STEP 10
# if STACK_STEP < 1
#  error STACK_STEP must be >= 1
# endif

# define CH_NULL(x) if((x) == NULL) exit (-1);

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
void				stack_print(t_int_stack stack);
void				stack_deinit(t_int_stack **stack);

#endif
