/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:13:42 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/22 17:50:55 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

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
	ft_printf("\n(Main)\n");
	ft_printlist(data.lst_a, "Liste a (depart)");
	test_ft(&data);
	ft_dlst_clear(&data.lst_a, &ft_free);
}
