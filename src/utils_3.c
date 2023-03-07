/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:32:27 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/06 11:41:49 by nrossel          ###   ########.fr       */
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
