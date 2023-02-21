/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:24:18 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/20 19:43:50 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_node	*ft_pop_back(t_dlist *lst)
{
	t_node	*node;

	if (!lst)
		return (0);
	node = lst->tail;
	if ()
	lst->tail = lst->tail->prev;
	lst->tail->next = NULL;
	lst->len--;
	return (node);
}
