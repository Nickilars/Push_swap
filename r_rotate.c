/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:10:24 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/23 10:24:01 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

void	r_rotate_a(t_dlist **list)
{
	t_node	*node_tmp;

	if (!list || !(*list)->head || (*list)->len < 2)
		return ;
	node_tmp = ft_pop_back(list);
	ft_dlst_addfront(list, node_tmp);
	ft_printf("rra\n");
}

void	r_rotate_b(t_dlist **list)
{
	t_node	*node_tmp;

	if (!list || !(*list)->head || (*list)->len < 2)
		return ;
	node_tmp = ft_pop_back(list);
	ft_dlst_addfront(list, node_tmp);
	ft_printf("rrb\n");
}

void	r_rotate_rr(t_pshswp *data)
{
	r_rotate_a(&data->lst_a);
	r_rotate_a(&data->lst_b);
	ft_printf("rrr\n");
}
