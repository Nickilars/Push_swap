/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:04:56 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/07 13:41:55 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/p_s.h"

static int	bit_size(int size)
{
	int	bit_max;

	bit_max = 0;
	while (size >> bit_max)
		bit_max++;
	return (bit_max);
}

void	algo_radix(t_pshswp *list, size_t size, t_dlist **a, t_dlist **b)
{
	int	num;
	int	num2;

	while (list->index.i < bit_size((int)size - 1))
	{
		list->index.j = 0;
		while (list->index.j < (int)size)
		{
			num = *(*a)->head->data;
			num2 = num >> list->index.i;
			if ((num >> list->index.i & 1) == 1)
				rotate_a(a);
			else if ((num >> list->index.i & 1) == 0)
				push_b(a, b);
			list->index.j++;
		}
		while ((*b)->len > 0)
		{
			push_a(a, b);
		}
		list->index.i++;
	}
}
