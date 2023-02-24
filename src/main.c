/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:13:42 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/24 11:05:22 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_s.h"

/******************** INITIALISATION ***********************/
static void	ft_init(t_pshswp *data)
{
	data->index.i = 0;
	data->index.j = 0;
	data->index.k = 0;
	data->lst_a = ft_dlst_new();
	data->lst_b = ft_dlst_new();
	if (!data->lst_b)
	{
		free(data->lst_a);
		ft_free_arrays(NULL, NULL, "Erreur, lst_b non-créé");
	}
}

int	main(int ac, char **av)
{
	t_pshswp	data;

	ft_init(&data);
	if (ac < 2)
		ft_free_arrays(NULL, NULL, "Error, pas d'arguments");
	else if (ac == 2)
		char_to_lst(av[1], &data);
	else
		int_to_lst(av + 1, &data);
	check_algo(&data);
	ft_dlst_clear(&data.lst_a, &ft_free);
}
