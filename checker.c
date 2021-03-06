/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:16:39 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/17 16:51:59 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

static int	read_input(t_int_stack *a, t_int_stack *b)
{
	char	*com;

	while (get_next_line(0, &com) > 0)
	{
		if (com[0] == '\0')
			break ;
		if (push_swap_handler(com, a, b) == 0)
		{
			ft_putendl_fd("Error", 2);
			push_swap_deinit(&a, &b);
			ft_strdel(&com);
			return (1);
		}
		ft_strdel(&com);
	}
	ft_strdel(&com);
	return (0);
}

static int	stacks_init(int argc, char **argv, t_int_stack **a, t_int_stack **b)
{
	if (push_swap_init(argc, argv, a, b) == 0)
	{
		ft_putendl_fd("Error", 2);
		push_swap_deinit(a, b);
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_int_stack	*a;
	t_int_stack	*b;
	int			i;

	if (argc <= 1)
	{
		printf("usage: %s num_1 num_2 ...", argv[0]);
		return (0);
	}
	if (stacks_init(argc, argv, &a, &b))
		return (0);
	if (read_input(a, b))
		return (0);
	i = a->size;
	while (--i > 1)
		if (a->arr[i] > a->arr[i - 1])
		{
			ft_putendl("KO");
			push_swap_deinit(&a, &b);
			return (0);
		}
	(b->size != 0) ? (ft_putendl("KO")) : (ft_putendl("OK"));
	push_swap_deinit(&a, &b);
	return (0);
}
