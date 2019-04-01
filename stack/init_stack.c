/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:55:21 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/03 12:50:28 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_int_stack	*stack_init(void)
{
	t_int_stack *ret;

	if ((ret = (t_int_stack*)malloc(sizeof(t_int_stack))) == NULL)
	{
		exit(-1);
	}
	if ((ret->arr = (int*)malloc(sizeof(int) * STACK_STEP)) == NULL)
	{
		free(ret);
		exit(-1);
	}
	ret->size = 0;
	return (ret);
}
