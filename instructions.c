/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:54:24 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/20 19:48:43 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

/*------------------ Swap ---------------------*/
void	swap(t_list **lst)
{
	t_list	*lst_tmp;

	if (!*lst || !(*lst)->next)
		return ;
	lst_tmp = *lst;
	*lst = (*lst)->next;
	lst_tmp = (*lst)->next;
	*(*lst)->next = *lst_tmp;
}

/*------------------ Push ---------------------*/
void	push(t_list **lst_a, t_list **lst_b)
{
	t_list	*lsta_tmp;
	t_list	*lstb_tmp;

	if (!*lst_b)
	{
		*lst_b = *lst_a;
		*lst_a = (*lst_a)->next;
		(*lst_b)->next = NULL;
	}
	else
	{
		lsta_tmp = *lst_a;
		lstb_tmp = *lst_b;
		*lst_a = *lst_b;
		(*lst_a)->next = lsta_tmp->next;
		*lst_b = lsta_tmp;
		(*lst_b)->next = lstb_tmp->next;
	}
}

/*------------------ Rotate ---------------------*/
void	rotate(t_list **lst)
{
	t_list	*headlst_tmp;
	t_list	*taillst_tmp;

	headlst_tmp = *lst;
	taillst_tmp = ft_lstlast(*lst);
	*lst = (*lst)->next;
	taillst_tmp->next = headlst_tmp;
	headlst_tmp->next = NULL;
}

/*------------------ Reverse Rotate ---------------------*/
void	r_rotate(t_list **lst)
{
	t_list	*new_head_lst;
	t_list	*new_tail_lst;

	new_head_lst = ft_lstlast(*lst);
	new_head_lst->next = *lst;
	*lst = new_head_lst;
	new_tail_lst = ft_lstlast(*lst);
	new_tail_lst->next = NULL;
}
