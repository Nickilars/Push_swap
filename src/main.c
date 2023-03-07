/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:13:42 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/06 11:41:47 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_s.h"

/******************** INITIALISATION ***********************/
static void	ft_init(t_pshswp *dlist)
{
	dlist->index.i = 0;
	dlist->index.j = 0;
	dlist->index.k = 0;
	dlist->a = ft_dlst_new();
	if (!dlist->a)
		ft_exit(1);
	dlist->b = ft_dlst_new();
	if (!dlist->b)
	{
		free(dlist->a);
		ft_exit(1);
	}
}

int	main(int ac, char **av)
{
	t_pshswp	dlist;

	if (ac < 2)
		exit (0);
	else
	{
		ft_init(&dlist);
		if (ac == 2)
			char_to_lst(av[1], &dlist);
		else if (ac > 2)
			int_to_lst(av + 1, &dlist);
		check_algo(&dlist);
		ft_free_arraylist(dlist.a, dlist.b, 1);
	}
	return (0);
}
