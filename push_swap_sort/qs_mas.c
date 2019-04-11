/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_mas.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:04:36 by rwalder-          #+#    #+#             */
/*   Updated: 2019/04/01 20:20:59 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sort.h"

void qs(int *s_arr, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = s_arr[(left + right) / 2];
		do
		{
			while (s_arr[left] > middle) left++;
			while (s_arr[right] < middle) right--;
			if (left <= right)
			{
				int tmp = s_arr[left];
				s_arr[left] = s_arr[right];
				s_arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		qs(s_arr, first, right);
		qs(s_arr, left, last);
	}
}

int		*bubble_sort(int *array, int array_size)
{
	int i = 0;
	int buf;
	char swap_cnt = 0;

	if (array_size == 0)
		return (0);
	while (i < array_size)
	{
		if (i + 1 != array_size && array[i] > array[i + 1])
		{
			buf = array[i];
			array[i] = array[i + 1];
			array[i + 1] = buf;
			swap_cnt = 1;
		}
		i++;
		if (i == array_size && swap_cnt == 1)
		{
			swap_cnt = 0;
			i = 0;
		}
	}
	return (array);
}
