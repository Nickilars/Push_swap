/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:58:37 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/27 10:33:42 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/p_s.h"

void	swap_a(t_dlist **a)
{
	t_node	*node_tmp;

	if (!a ||!(*a)->head || (*a)->len < 2)
		return ;
	if ((*a)->len > 2)
	{
		node_tmp = ft_pop_front(a);
		ft_dlst_addnode(a, node_tmp, 2);
	}
	else
	{
		node_tmp = ft_pop_front(a);
		ft_dlst_addback(a, node_tmp);
	}
	ft_printf("sa\n");
}

void	swap_b(t_dlist **b)
{
	t_node	*node_tmp;

	if (!b ||!(*b)->head || (*b)->len < 2)
		return ;
	node_tmp = ft_pop_front(b);
	if ((*b)->len > 2)
		ft_dlst_addnode(b, node_tmp, 2);
	else
		ft_dlst_addback(b, node_tmp);
	ft_printf("sb\n");
}

void	swap_ss(t_pshswp *list)
{
	swap_a(&list->a);
	swap_b(&list->b);
	ft_printf("ss\n");
}
