/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:32:27 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/08 08:36:25 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_s.h"

void	ft_free_arraylist(t_dlist *a, t_dlist *b, int sortie)
{
	ft_dlst_clear(&a, &ft_free);
	free(a);
	free(b);
	ft_exit(sortie);
}

int	check_arg2(char *str)
{
	int	index;
	int	compteur_espace;
	int	compteur_trait;

	index = 0;
	compteur_espace = 1;
	compteur_trait = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if (str[index] == ' ')
			compteur_espace++;
		else if (str[index] == '-')
			compteur_trait++;
		if (compteur_trait > compteur_espace)
			return (0);
		index++;
	}
	return (1);
}
