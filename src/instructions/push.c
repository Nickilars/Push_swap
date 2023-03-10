/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:10:24 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/27 10:29:33 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/p_s.h"

void	push_a(t_dlist **a, t_dlist **b)
{
	t_node	*node_tmp;

	if (!a || !(*b)->head)
		return ;
	node_tmp = ft_pop_front(b);
	ft_dlst_addfront(a, node_tmp);
	ft_printf("pa\n");
}

void	push_b(t_dlist **a, t_dlist **b)
{
	t_node	*node_tmp;

	if (!b || !(*a)->head)
		return ;
	node_tmp = ft_pop_front(a);
	ft_dlst_addfront(b, node_tmp);
	ft_printf("pb\n");
}
