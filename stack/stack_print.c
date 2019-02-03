/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:12:51 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/03 12:31:24 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_print(t_int_stack stack)
{
	unsigned int i;

	if (stack.arr == NULL)
		return ;
	i = 0;
	while (i < stack.size)
	{
		ft_putnbr(stack.arr[i++]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
