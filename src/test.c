/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:49:27 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/24 11:18:41 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_s.h"

void	ft_printlist(t_dlist *list, char *nom_list)
{
	t_node	*ptr;

	ptr = list->head;
	ft_printf("%s || ", nom_list);
	while (ptr)
	{
		//ft_printf("%p = ", ptr);
		ft_printf("%d/%d -> ", *ptr->data, ptr->norm);
		// ft_printf("%d", list->head->norm);
		//sleep(5);
		ptr = ptr->next;
	}
	ft_printf("NULL\n");
}

void	test_ft(t_pshswp *data)
{
	swap_a(&data->lst_a);
	ft_printlist(data->lst_a, "Liste a (swap)");
	swap_a(&data->lst_a);
	ft_printlist(data->lst_a, "Liste a (swap)");
	push_b(&data->lst_a, &data->lst_b);
	ft_printlist(data->lst_a, "Liste a (push a -> b)");
	ft_printlist(data->lst_b, "Liste b (push a -> b)");
	push_a(&data->lst_a, &data->lst_b);
	ft_printlist(data->lst_a, "Liste a (push b -> a)");
	ft_printlist(data->lst_b, "Liste b (push b -> a)");
	rotate_a(&data->lst_a);
	ft_printlist(data->lst_a, "Liste a (rotate)");
	r_rotate_a(&data->lst_a);
	ft_printlist(data->lst_a, "Liste a (revers_rotate)");
}
