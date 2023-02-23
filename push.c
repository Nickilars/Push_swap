/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:10:24 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/23 10:22:20 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

void	push_a(t_dlist **list_a, t_dlist **list_b)
{
	t_node	*node_tmp;

	if (!list_a || !(*list_b)->head)
		return ;
	node_tmp = ft_pop_front(list_b);
	ft_dlst_addfront(list_a, node_tmp);
	ft_printf("pa\n");
}

void	push_b(t_dlist **list_a, t_dlist **list_b)
{
	t_node	*node_tmp;

	if (!list_b || !(*list_a)->head)
		return ;
	node_tmp = ft_pop_front(list_a);
	ft_dlst_addfront(list_b, node_tmp);
	ft_printf("pb\n");
}
