/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:53:13 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/24 19:12:10 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/p_s.h"

static void	ft_one(t_pshswp *list)
{
	push_b(&list->lst_a, &list->lst_b);
	algo_3nb(&list->lst_a);
	push_a(&list->lst_a, &list->lst_b);
}

static void	ft_two(t_pshswp *list)
{
	if (*list->lst_a->head->next->data != 1)
	{
		push_b(&list->lst_a, &list->lst_b);
		algo_3nb(&list->lst_a);
		push_a(&list->lst_a, &list->lst_b);
	}
	swap_a(&list->lst_a);
}

static void	ft_three(t_pshswp *list)
{
	if (*list->lst_a->head->next->data == 2)
	{
		swap_a(&list->lst_a);
		r_rotate_a(&list->lst_a);
		push_b(&list->lst_a, &list->lst_b);
		r_rotate_a(&list->lst_a);
		push_a(&list->lst_a, &list->lst_b);
		rotate_a(&list->lst_a);
	}
	swap_a(&list->lst_a);
}

static void	ft_four(t_pshswp *list)
{
	push_b(&list->lst_a, &list->lst_b);
	algo_3nb(&list->lst_a);
	push_a(&list->lst_a, &list->lst_b);
	rotate_a(&list->lst_a);
}

void	algo_4nb(t_pshswp *list)
{	
	int	nbr;

	nbr = *list->lst_a->head->data;
	if (nbr == 1)
		ft_one(list);
	else if (nbr == 2)
		ft_two(list);
	else if (nbr == 3)
		ft_three(list);
	else if (nbr == 4)
		ft_four(list);
}
