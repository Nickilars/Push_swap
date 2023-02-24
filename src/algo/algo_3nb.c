/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:40:57 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/24 13:21:35 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/p_s.h"

void	algo_3nb(t_dlist *list)
{
	if (list->head->data < list->head->next->data
		&& list->tail->prev->data < list->tail->data)
		return ;
	else if (list->head->data > list->head->next->data
		&& list->tail->data > list->tail->prev->data
		&& list->tail->data > list->head->data)
	{
		return ;
	}
}
