/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:10:24 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/27 10:31:25 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/p_s.h"

void	r_rotate_a(t_dlist **a)
{
	t_node	*node_tmp;

	if (!a || !(*a)->head || (*a)->len < 2)
		return ;
	node_tmp = ft_pop_back(a);
	ft_dlst_addfront(a, node_tmp);
	ft_printf("rra\n");
}

void	r_rotate_b(t_dlist **b)
{
	t_node	*node_tmp;

	if (!b || !(*b)->head || (*b)->len < 2)
		return ;
	node_tmp = ft_pop_back(b);
	ft_dlst_addfront(b, node_tmp);
	ft_printf("rrb\n");
}

void	r_rotate_rr(t_pshswp *list)
{
	r_rotate_a(&list->a);
	r_rotate_b(&list->b);
	ft_printf("rrr\n");
}
