/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:43:48 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/17 16:16:52 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdelone(t_list *lst, t_dlist *dlst, void (*del)(void *))
{
	if (!lst && !dlst)
		return ;
	if (lst)
	{
		del(lst->data);
		free(lst);
	}
	else
	{
		del(dlst->head->data);
		free(dlst);
	}
}
