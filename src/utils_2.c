/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:53:41 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/24 11:46:04 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_s.h"

static void	ft_isbigger(t_dlist **list)
{
	t_node	*node;
	t_node	*data;
	size_t	nbr;
	int		nbr_tmp;

	nbr = (*list)->len + 1;
	while (--nbr > 0)
	{
		data = (*list)->head;
		node = (*list)->head;
		nbr_tmp = *data->data;
		while (node != NULL)
		{
			if (*data->data < *node->data && data->norm == 0)
				data = node;
			node = node->next;
		}
		if (nbr_tmp == *data->data)
		{
			*data->data = nbr;
			return ;
		}
		data->norm = 1;
		*data->data = nbr;
	}
}

static void	ft_issmaller(t_dlist **list)
{
	t_node	*node;
	t_node	*data;
	size_t	nbr;
	int		nbr_tmp;

	nbr = 0;
	while (nbr++ < (*list)->len)
	{
		data = (*list)->head;
		node = (*list)->head;
		nbr_tmp = *data->data;
		while (node != NULL)
		{
			if (*data->data > *node->data && node->norm == 0)
				data = node;
			node = node->next;
		}
		if (nbr_tmp == *data->data)
			return ;
		data->norm = 1;
		*data->data = nbr;
	}
}

static void	normalize_nbr(t_dlist **list)
{
	ft_issmaller(list);
	ft_isbigger(list);
	ft_printlist(*list, "Liste a normalisée ||");
}

void	check_algo(t_pshswp *data)
{
	normalize_nbr(&data->lst_a);
	if (data->lst_a->len <= 1)
		return ;
	else if (data->lst_a->len == 2)
		algo_2nb(data->lst_a);
	// else if (data->lst_a->len == 3)
		// algo_3nb(data->lst_a);
	// else if (data->lst_a->len == 4)
		// algo_4nb(data->lst_a);
}
