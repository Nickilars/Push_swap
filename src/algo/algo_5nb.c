/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:53:13 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/07 10:41:32 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/p_s.h"

static int	check_first_is_smallest(t_dlist *list)
{
	t_node	*node;
	t_node	*tmp_node;

	node = list->head->next;
	tmp_node = list->head;
	while (node != NULL)
	{
		if (*tmp_node->data > *node->data)
			return (0);
		node = node->next;
	}
	return (1);
}

static int	ft_search_smallest(t_dlist *list)
{
	t_node	*node;
	t_node	*node_tmp;
	int		i;

	node = list->head;
	node_tmp = list->head;
	while (node != NULL)
	{
		if (*node->data < *node_tmp->data)
			node_tmp = node;
		node = node->next;
	}
	node = list->head;
	i = 1;
	while (node != NULL && *node->data != *node_tmp->data)
	{
		node = node->next;
		i++;
	}
	return (i);
}

static void	ft_push_2nb_to_b(t_pshswp *list)
{
	if (list->a->len > 3)
	{
		if (check_first_is_smallest(list->a) == 0)
		{
			list->index.i = ft_search_smallest(list->a);
			if (list->index.i <= 3)
				while (list->index.i-- > 1)
					rotate_a(&list->a);
			else if (list->index.i > 3 && list->a->len == 5)
				while (list->index.i++ < 6)
					r_rotate_a(&list->a);
			else
				while (list->index.i++ < 5)
					r_rotate_a(&list->a);
			push_b(&list->a, &list->b);
			ft_push_2nb_to_b(list);
		}
		else
		{
			push_b(&list->a, &list->b);
			ft_push_2nb_to_b(list);
		}
	}
	else
		return ;
}

void	algo_5nb(t_pshswp *list)
{
	ft_push_2nb_to_b(list);
	algo_3nb(&list->a);
	push_a(&list->a, &list->b);
	push_a(&list->a, &list->b);
}
