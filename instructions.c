/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:54:24 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/22 15:15:32 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

/*------------------ Swap ---------------------*/
void	swap(t_dlist **lst)
{
	t_node	*node_tmp;

	if (!lst ||!(*lst)->head || !(*lst)->head->next)
		return ;
	node_tmp = ft_pop_front(lst);
	if ((*lst)->len > 2)
		ft_dlst_add(lst, node_tmp, 2);
	else
		ft_dlst_addback(lst, node_tmp);
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
void	rotate(t_dlist **lst)
{
	t_node	*node;

	if (!lst || !(*lst)->head)
		return ;
	node = ft_pop_front(lst);
	ft_dlst_addback(lst, node);
}

/*------------------ Reverse Rotate ---------------------*/
void	r_rotate(t_dlist **lst)
{
	t_node	*node_tmp;

	if (!lst || !(*lst)->head)
		return ;
	node_tmp = ft_pop_back(lst);
	ft_dlst_addfront(lst, node_tmp);
}
