/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:40:57 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/27 10:10:48 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/p_s.h"

int	*tab_list(t_dlist *list)
{
	int		*tab;
	int		index;
	t_node	*node;

	index = 0;
	node = list->head;
	tab = malloc(list->len * sizeof(int));
	if (!tab)
		ft_free_arrays(NULL, NULL, "Error, no tab_list malloc");
	while (node)
	{
		tab[index++] = *node->data;
		node = node->next;
	}
	return (tab);
}

void	algo_3nb(t_dlist **list)
{
	int	*tab;

	if (check_order(*list))
		return ;
	tab = tab_list(*list);
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
	{
		swap_a(list);
		rotate_a(list);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		r_rotate_a(list);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		swap_a(list);
	else if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		swap_a(list);
		r_rotate_a(list);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		rotate_a(list);
	free(tab);
}
