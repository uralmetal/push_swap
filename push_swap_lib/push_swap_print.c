/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:31:56 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/16 17:14:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

static void	print_end(t_int_stack *a, t_int_stack *b)
{
	if (a->size == 0)
		ft_putchar(' ');
	else
		ft_putnbr(a->arr[0]);
	ft_putchar(' ');
	if (b->size == 0)
		ft_putchar(' ');
	else
		ft_putnbr(b->arr[0]);
	ft_putstr("\n_ _\na b\n");
}

void		push_swap_print(const char *header, t_int_stack *a, t_int_stack *b)
{
	unsigned int i;

	if (a == NULL || a->arr == NULL || b == NULL || b->arr == NULL)
		return ;
	printf("\n%s\n", header);
	i = ((a->size > b->size) ? (a->size) : (b->size)) - 1;
	while (i > 0)
	{
		if (i >= a->size)
			ft_putchar(' ');
		else
			ft_putnbr(a->arr[i]);
		ft_putchar(' ');
		if (i >= b->size)
			ft_putchar(' ');
		else
			ft_putnbr(b->arr[i]);
		ft_putchar('\n');
		i--;
	}
	print_end(a, b);
}
