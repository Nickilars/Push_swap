/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:13:42 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/20 18:10:14 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

void	ft_printlist(t_pshswp *lst)
{
	t_list	*ptr;

	ptr = lst->lst_a->head;
	while (ptr != NULL)
	{
		ft_printf("%d -> ", *ptr->data);
		ptr = ptr->next;
	}
	ft_printf("NULL\n");
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
	ft_printlist(&data);
	ft_dlst_clear(&data.lst_a, &ft_free);
}
