/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:54:24 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/22 18:47:00 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

/*------------------ Swap ---------------------*/
void	swap(t_dlist **list)
{
	t_node	*node_tmp;

	if (!list ||!(*list)->head || !(*list)->head->next)
		return ;
	node_tmp = ft_pop_front(list);
	if ((*list)->len > 2)
		ft_dlst_addnode(list, node_tmp, 2);
	else
		ft_dlst_addback(list, node_tmp);
}

/*------------------ Push ---------------------*/
void	push(t_dlist **lst_a, t_dlist **lst_b)
{
	t_node	*node_tmp;

	if (!lst_b || !(*lst_a)->head)
		return ;
	node_tmp = ft_pop_front(lst_a);
	ft_dlst_addfront(lst_b, node_tmp);
}

/*------------------ Rotate ---------------------*/
void	rotate(t_dlist **list)
{
	t_node	*node;

	if (!list || !(*list)->head)
		return ;
	node = ft_pop_front(list);
	ft_dlst_addback(list, node);
}

/*------------------ Reverse Rotate ---------------------*/
void	r_rotate(t_dlist **list)
{
	t_node	*node_tmp;

	if (!list || !(*list)->head || (*list)->len < 2)
		return ;
	node_tmp = ft_pop_back(list);
	ft_dlst_addfront(list, node_tmp);
}
