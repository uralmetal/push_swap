/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:21:08 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 15:54:30 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int		ft_atoi_with_err(const char *str, int *err)
{
	long	ret;
	long	max_int;
	int		count;
	int		sign;

	ret = 0;
	count = 0;
	sign = 1;
	*err = 0;
	max_int = (str[count] == '-') ? (INT_MIN * -1L) : (INT_MAX);
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	while ((str[count] >= '0') && (str[count] <= '9') && (ret < max_int))
	{
		ret *= 10;
		ret = ret + (str[count++] - '0');
	}
	if (str[count] != '\0' || (ret > max_int))
		*err = 1;
	return (ret * sign);
}

int			push_swap_init(int argc, char **argv, t_int_stack **a, t_int_stack **b)
{
	int i;
	int err;
	int temp;

	i = argc;
	*a = stack_init();
	*b = stack_init();
	while (--i > 0)
	{
		temp = ft_atoi_with_err(argv[i], &err);
		if (err)
			return (0);
		stack_put(*a, temp);
	}
	return (1);
}
