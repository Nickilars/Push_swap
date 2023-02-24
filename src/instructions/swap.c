/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:58:37 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/24 10:44:26 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/p_s.h"

void	swap_a(t_dlist **list)
{
	t_node	*node_tmp;

	if (!list ||!(*list)->head || (*list)->len < 2)
		return ;
	node_tmp = ft_pop_front(list);
	if ((*list)->len > 2)
		ft_dlst_addnode(list, node_tmp, 2);
	else
		ft_dlst_addback(list, node_tmp);
	ft_printf("sa\n");
}

void	swap_b(t_dlist **list)
{
	t_node	*node_tmp;

	if (!list ||!(*list)->head || (*list)->len < 2)
		return ;
	node_tmp = ft_pop_front(list);
	if ((*list)->len > 2)
		ft_dlst_addnode(list, node_tmp, 2);
	else
		ft_dlst_addback(list, node_tmp);
	ft_printf("sb\n");
}

void	swap_ss(t_pshswp *data)
{
	swap_a(&data->lst_a);
	swap_b(&data->lst_b);
	ft_printf("ss\n");
}
