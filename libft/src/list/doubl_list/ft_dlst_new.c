/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:10:54 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/20 18:12:23 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_dlist	*ft_dlst_new(void)
{
	t_dlist	*new_list;

	new_list = malloc(sizeof(t_dlist));
	if (!new_list)
		return (NULL);
	new_list->len = 0;
	new_list->head = NULL;
	new_list->tail = NULL;
	return (new_list);
}
