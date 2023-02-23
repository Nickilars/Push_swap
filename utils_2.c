/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:53:41 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/23 14:15:33 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

void	check_algo(t_pshswp *data)
{
	if (data->lst_a->len <= 1)
		return ;
	else if (data->lst_a->len == 2)
		algo_2nb(data->lst_a);
	else if (data->lst_a->len == 3)
		algo_3nb(data->lst_a);
	// else if (data->lst_a->len == 4)
		// algo_4nb(data->lst_a);
}

int	normalize_nbr(t_dlist **list)
{
	t_node	*node;
	t_node	*data;
	int		nbr;

	nbr = 1;
	while (nbr < (*list)->len)
	{
		data = (*list)->head;
		while (node != NULL)
		{
			if (*data->data > *node->data)
				data = node;
		}
		*data->data = nbr;
		nbr++;
	}
}
