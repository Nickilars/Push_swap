/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:49:27 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/22 18:45:00 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

void	ft_printlist(t_dlist *list, char *nom_list)
{
	t_node	*ptr;

	ptr = list->head;
	ft_printf("%s || ", nom_list);
	while (ptr)
	{
		//ft_printf("%p = ", ptr);
		ft_printf("%d -> ", *ptr->data);
		//sleep(5);
		ptr = ptr->next;
	}
	ft_printf("NULL\n");
}

void	test_ft(t_pshswp *data)
{
	swap(&data->lst_a);
	ft_printlist(data->lst_a, "Liste a (swap)");
	swap(&data->lst_a);
	ft_printlist(data->lst_a, "Liste a (swap)");
	push(&data->lst_a, &data->lst_b);
	ft_printlist(data->lst_a, "Liste a (push a -> b)");
	ft_printlist(data->lst_b, "Liste b (push a -> b)");
	push(&data->lst_b, &data->lst_a);
	ft_printlist(data->lst_a, "Liste a (push b -> a)");
	ft_printlist(data->lst_b, "Liste b (push b -> a)");
	rotate(&data->lst_a);
	ft_printlist(data->lst_a, "Liste a (rotate)");
	r_rotate(&data->lst_a);
	ft_printlist(data->lst_a, "Liste a (revers_rotate)");
}
