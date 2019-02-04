/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 12:12:51 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 10:20:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_print(t_int_stack stack)
{
	unsigned int i;

	if (stack.arr == NULL || stack.size == 0)
		return ;
	i = stack.size - 1;
	ft_putstr("-\n");
	while (i > 0)
	{
		ft_putnbr(stack.arr[i--]);
		ft_putchar('\n');
	}
    ft_putnbr(stack.arr[0]);
    ft_putchar('\n');
    ft_putstr("-\n");
	//ft_putchar('\n');
}
