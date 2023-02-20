/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:24:18 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/20 18:12:28 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_list	*ft_pop_back(t_dlist *lst)
{
	t_list	*ptr;

	if (!lst)
		return (0);
	ptr = lst->tail;
	lst->tail = lst->tail->prev;
	lst->tail->next = NULL;
	return (ptr);
}
