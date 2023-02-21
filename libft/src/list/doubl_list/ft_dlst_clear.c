/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:10:30 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/20 19:27:58 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_dlst_clear(t_dlist **dlst, void (*del)(void *))
{
	t_node	*ptr;

	if (!*dlst)
		return ;
	ptr = (*dlst)->head;
	while ((*dlst)->head != NULL)
	{
		ptr = (*dlst)->head->next;
		ft_lstdelone((*dlst)->head, del);
		(*dlst)->head = ptr;
	}
	*dlst = NULL;
	free(*dlst);
}
