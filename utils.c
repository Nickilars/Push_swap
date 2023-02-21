/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:18:24 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/20 19:48:40 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

/******************** INITIALISATION ***********************/
void	ft_init(t_pshswp *data)
{
	data->index.i = 0;
	data->index.j = 0;
	data->index.k = 0;
}

/******************** CHECK ARG VALID ***********************/
void	ft_arg_check(t_dlist *lst)
{
	t_dlist	*lst_p1;
	t_dlist	*lst_p2;

	lst_p1 = lst;
	while (lst_p1 != NULL)
	{
		lst_p2 = lst_p1;
		while (lst_p2 != NULL)
		{
			if (*lst_p1->head->data == *lst_p2->head->data
				|| *lst_p1->head->data > 2147483647
				|| *lst_p1->head->data < -2147483641 - 1)
			{
				ft_lstclear(&lst->head, &ft_free);
				ft_free_arrays(NULL, NULL, "Erreur, arguments invalides");
			}
			lst_p2->head = lst_p2->head->next;
		}
		lst_p1->head = lst_p1->head->next;
	}
}

/******************** ARG TO LIST ***********************/
/*------------- string to list -----------------*/
t_dlist	**char_to_lst(char *av, t_pshswp *lst, t_index index)
{
	char	**split;
	t_list	*new_lst;
	t_dlist	*new_dlst;
	int		*nbr;

	split = ft_split(av, ' ');
	new_dlst = ft_dlst_new;
	while (split[index.i])
	{ /*----------------------------------- ici ------------------------------------------------*/
		nbr = (int *)malloc(sizeof(int));
		if (!nbr)
		{
			ft_dlst_clear(&lst->lst_a, &ft_free);
			ft_free_arrays(NULL, NULL, "Error, no malloc char_to_lst");
		}
		*nbr = ft_atoi(split[index.i]);
		new_lst = ft_lstnew(nbr);
		if (lst->lst_a == NULL)
			ft_dlst_addfront(lst->lst_a, new_lst);
		else
			ft_dlst_addback(lst->lst_a, new_lst);
		index.i++;
	}
	ft_free_2da(split, index.i, NULL);
	ft_arg_check(lst->lst_a);
	return (new_dlst);
}

/*----------------- int to list -------------------*/
void	int_to_lst(char **av, t_pshswp *lst, t_index index)
{
	t_list	*new_lst;
	int		*nbr;

	while (av[index.i])
	{
		nbr = (int *)malloc(sizeof(int));
		if (!nbr)
		{
			ft_dlst_clear(&lst->lst_a, &ft_free);
			ft_free_arrays(NULL, NULL, "Error, no malloc int_to_lst");
		}
		*nbr = ft_atoi(av[index.i]);
		new_lst = ft_lstnew(nbr);
		if (lst->lst_a == NULL)
			ft_dlst_addfront(lst->lst_a, new_lst);
		else
			ft_dlst_addback(lst->lst_a, new_lst);
		index.i++;
	}
	ft_arg_check(lst->lst_a);
}
