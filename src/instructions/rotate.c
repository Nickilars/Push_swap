/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:13:44 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/24 10:44:22 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/p_s.h"

void	rotate_a(t_dlist **list)
{
	t_node	*node;

	if (!list || !(*list)->head || (*list)->len < 2)
		return ;
	node = ft_pop_front(list);
	ft_dlst_addback(list, node);
	ft_printf("ra\n");
}

void	rotate_b(t_dlist **list)
{
	t_node	*node;

	if (!list || !(*list)->head || (*list)->len < 2)
		return ;
	node = ft_pop_front(list);
	ft_dlst_addback(list, node);
	ft_printf("rb\n");
}

void	rotate_rr(t_pshswp *data)
{
	rotate_a(&data->lst_a);
	rotate_b(&data->lst_b);
	ft_printf("rr\n");
}
