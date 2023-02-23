/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:18:24 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/23 13:43:35 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

/******************** CREAT NODE ***********************/
static void	creat_newnode(t_dlist **list, char **tab, int index)
{
	int			nbr;
	t_node		*new_node;

	nbr = ft_atoi(tab[index]);
	new_node = ft_dlst_newcontent(nbr);
	if ((*list)->head == NULL)
		ft_dlst_addfront(list, new_node);
	else
		ft_dlst_addback(list, new_node);
}

/******************** CHECK ARG VALID ***********************/
/*------------- check before creat list -----------------*/
static void	ft_arg_check(char **av)
{
	int	index_i;
	int	index_j;

	index_i = 0;
	while (av[index_i] != 0)
	{
		index_j = 0;
		while (av[index_i][index_j] != 0)
		{
			if (av[index_i][index_j] == '-'
				|| av[index_i][index_j] == '+')
			{
				if ((av[index_i][index_j + 1] == '-'
					|| av[index_i][index_j + 1] == '+'))
					ft_free_arrays(NULL, NULL, "Erreur, arguments invalides");
				else if (ft_isdigit(av[index_i][++index_j]) == 0)
					ft_free_arrays(NULL, NULL, "Erreur, arguments invalides");
			}
			if (ft_isdigit(av[index_i][index_j]) == 0)
				ft_free_arrays(NULL, NULL, "Erreur, arguments invalides");
			index_j++;
		}
		index_i++;
	}
}

/*------------- check after creat list -----------------*/
static void	ft_list_check(t_dlist *list)
{
	t_node	*node_1;
	t_node	*node_2;

	node_1 = list->head;
	while (node_1->next != NULL)
	{
		node_2 = node_1->next;
		while (node_2 != NULL)
		{
			if (*node_1->data == *node_2->data)
			{
				ft_dlst_clear(&list, &ft_free);
				ft_free_arrays(NULL, NULL, "Erreur, arguments invalides");
			}
			node_2 = node_2->next;
		}
		node_1 = node_1->next;
	}
}

/******************** ARG TO LIST ***********************/
/*------------- string to list -----------------*/
void	char_to_lst(char *av, t_pshswp *list)
{
	char	**split;
	int		index;
	int		i;

	i = -1;
	index = 0;
	split = ft_split(av, ' ');
	while (split[++i])
		ft_printf("%s\n", split[i]);
	ft_printf("\n");
	ft_arg_check(split);
	while (split[index])
	{
		creat_newnode(&list->lst_a, split, index);
		index++;
	}
	ft_free_2da(split, index, NULL);
	ft_list_check(list->lst_a);
}

/*----------------- int to list -------------------*/
void	int_to_lst(char **av, t_pshswp *list)
{
	int	index;

	index = 0;
	ft_arg_check(av);
	while (av[index])
	{
		creat_newnode(&list->lst_a, av, index);
		index++;
	}
	ft_list_check(list->lst_a);
}
