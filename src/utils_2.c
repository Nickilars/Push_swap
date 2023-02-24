/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:53:41 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/24 15:11:04 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_s.h"

static int	check_order(t_dlist *list)
{
	t_node	*node;

	node = list->head;
	while (node->next != NULL)
	{
		if (*node->data < *node->next->data)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

static void	ft_isbigger(t_dlist **list, size_t nbr_min)
{
	t_node	*node;
	t_node	*data;
	size_t	nbr;
	int		nbr_tmp;

	nbr = (*list)->len + 1;
	while (--nbr > 0 && nbr >= nbr_min)
	{
		data = (*list)->head;
		node = (*list)->head;
		nbr_tmp = *data->data;
		while (node != NULL)
		{
			if (*data->data < *node->data && node->norm == 0)
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

static int	ft_issmaller(t_dlist **list)
{
	t_node	*node;
	t_node	*data;
	size_t	nbr;
	int		nbr_tmp;

	nbr = 0;
	while (++nbr < (*list)->len)
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
			return (nbr);
		data->norm = 1;
		*data->data = nbr;
	}
	return (0);
}

static void	normalize_list(t_dlist **list)
{
	size_t	ret;

	ft_printf("\n----------------------------------------------------------------------------------\n");
	ft_printlist(*list, "\nListe a avant normalisation\n");
	ret = ft_issmaller(list);
	ft_isbigger(list, ret);
	ft_printf("\n----------------------------------------------------------------------------------\n");
	ft_printlist(*list, "\nListe a après normalisation\n");
}

void	check_algo(t_pshswp *data)
{
	if (check_order(data->lst_a) == 0)
	{
		normalize_list(&data->lst_a);
		ft_printf("\nLongueur de la liste -> %d\n\n", data->lst_a->len);
		if (data->lst_a->len <= 1)
			return ;
		else if (data->lst_a->len == 2)
			algo_2nb(data->lst_a);
		// else if (data->lst_a->len == 3)
			// algo_3nb(data->lst_a);
		// else if (data->lst_a->len == 4)
			// algo_4nb(data->lst_a);
	}
	ft_printf("\n----------------------------------------------------------------------------------\n");
	ft_printlist(data->lst_a, "\nListe final triée");
}
