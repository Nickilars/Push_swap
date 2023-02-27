/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:13:42 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/27 10:28:13 by nrossel          ###   ########.fr       */
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
	dlist->b = ft_dlst_new();
	if (!dlist->b)
	{
		free(dlist->a);
		ft_free_arrays(NULL, NULL, "Erreur, b non-créé");
	}
}

int	main(int ac, char **av)
{
	t_pshswp	dlist;

	ft_init(&dlist);
	if (ac < 2)
		ft_free_arrays(NULL, NULL, "Error, pas d'arguments");
	else if (ac == 2)
		char_to_lst(av[1], &dlist);
	else
		int_to_lst(av + 1, &dlist);
	check_algo(&dlist);
	ft_dlst_clear(&dlist.a, &ft_free);
}
