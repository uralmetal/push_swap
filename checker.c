/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:16:39 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/04 15:48:44 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib/push_swap_lib.h"
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

int		main(int argc, char **argv)
{

	t_int_stack *a;
	t_int_stack *b;
	int i;
	char *com;

	if (argc <= 1)
		return (0);
	if (push_swap_init(argc, argv, &a, &b) == 0)
	{
		ft_putendl_fd("Error", 2);
		push_swap_deinit(&a, &b);
		return (0);
	}
	while(get_next_line(0, &com) > 0)
	{
		if (com[0] == '\0')
			break ;
		if (push_swap_handler(com, a, b) == 0)
		{
			ft_putendl_fd("Error", 2);
			push_swap_deinit(&a, &b);
			return (0);
		}
		ft_strdel(&com);
	}
	i = a->size;
	while (--i > 1)
		if (a->arr[i] > a->arr[i - 1])
		{
			ft_putendl("KO");
			push_swap_deinit(&a, &b);
			return (0);
		}
	ft_putendl("OK");
	push_swap_deinit(&a, &b);
	return (0);
}