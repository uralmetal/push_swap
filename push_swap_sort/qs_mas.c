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