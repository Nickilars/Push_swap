/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:25:35 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/24 13:09:44 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_node	*ft_pop_front(t_dlist **lst)
{
	t_node	*node;

	if (!lst || !(*lst)->head)
		return (0);
	node = (*lst)->head;
	(*lst)->head = (*lst)->head->next;
	(*lst)->head->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	(*lst)->len--;
	return (node);
}
