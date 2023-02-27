/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:13:44 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/27 10:39:31 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/p_s.h"

void	rotate_a(t_dlist **a)
{
	t_node	*node;

	if (!a || !(*a)->head || (*a)->len < 2)
		return ;
	node = ft_pop_front(a);
	ft_dlst_addback(a, node);
	ft_printf("ra\n");
}

void	rotate_b(t_dlist **b)
{
	t_node	*node;

	if (!b || !(*b)->head || (*b)->len < 2)
		return ;
	node = ft_pop_front(b);
	ft_dlst_addback(b, node);
	ft_printf("rb\n");
}

void	rotate_rr(t_pshswp *list)
{
	rotate_a(&list->a);
	rotate_b(&list->b);
	ft_printf("rr\n");
}
