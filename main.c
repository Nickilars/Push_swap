/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:13:42 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/22 15:32:55 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

void	ft_printlist(t_dlist **list, char *nom_list)
{
	t_node	*ptr;

	ptr = (*list)->head;
	ft_printf("%s || ", nom_list);
	while (ptr->next != NULL)
	{
		ft_printf("%d -> ", *ptr->data);
		ptr = ptr->next;
	}
	ft_printf("NULL\n");
}

void	test_ft(t_pshswp *data)
{
	swap(&data->lst_a);
	ft_printlist(&data->lst_a, "Liste a (swap)");
	// push(&data->lst_a, &data->lst_b);
	// ft_printlist(data->lst_a, "Liste a (push a -> b)");
	// ft_printlist(data->lst_b, "Liste b (push a -> b)");
	// push(&data->lst_b, &data->lst_a);
	// ft_printlist(data->lst_b, "Liste b (push b -> a)");
	// ft_printlist(data->lst_a, "Liste a (push b -> a)");
	// rotate(&data->lst_a);
	// ft_printlist(data->lst_a, "Liste a (rotate)");
	// r_rotate(&data->lst_a);
	// ft_printlist(data->lst_a, "Liste a (revers_rotate)");
}

int	main(int ac, char **av)
{
	t_pshswp	data;

	ft_init(&data);
	if (ac < 2)
		ft_free_arrays(NULL, NULL, "Error, pas d'arguments");
	else if (ac == 2)
		char_to_lst(av[1], &data, data.index);
	else
		int_to_lst(av + 1, &data, data.index);
	ft_printlist(&data.lst_a, "Liste a (depart)");
	test_ft(&data);
	ft_dlst_clear(&data.lst_a, &ft_free);
}
