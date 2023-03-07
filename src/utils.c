/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:18:24 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/06 10:17:21 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/p_s.h"

/******************** CREAT NODE ***********************/
static int	creat_newnode(t_dlist **list, char **tab, int index)
{
	long		nbr;
	t_node		*new_node;

	nbr = ft_atoi(tab[index]);
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	new_node = ft_dlst_newcontent((int)nbr);
	if (!new_node)
		return (0);
	if ((*list)->head == NULL)
		ft_dlst_addfront(list, new_node);
	else
		ft_dlst_addback(list, new_node);
	return (1);
}

/******************** CHECK ARG VALID ***********************/
/*------------- check before creat list -----------------*/
static int	ft_arg_check(char **split)
{
	int	index_i;
	int	index_j;

	index_i = 0;
	while (split[index_i] != 0)
	{
		index_j = 0;
		while (split[index_i][index_j] != 0)
		{
			if (split[index_i][index_j] == '-'
				|| split[index_i][index_j] == '+')
			{
				if (split[index_i][index_j + 1] == '-'
					|| split[index_i][index_j + 1] == '\0'
					|| !ft_isdigit(split[index_i][index_j + 1]))
					return (0);
			}
			else if (!ft_isdigit((int)split[index_i][index_j]))
				return (0);
			index_j++;
		}
		index_i++;
	}
	return (1);
}

/*------------- check after creat list -----------------*/
static void	ft_list_check(t_pshswp *list)
{
	t_node	*node_1;
	t_node	*node_2;

	node_1 = list->a->head;
	while (node_1->next != NULL)
	{
		node_2 = node_1->next;
		while (node_2 != NULL)
		{
			if (*node_1->data == *node_2->data)
				ft_free_arraylist(list->a, list->b, 0);
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

	i = 0;
	index = -1;
	split = ft_split(av, ' ');
	while (split[i])
		i++;
	if (ft_arg_check(split) == 0)
	{
		ft_free_2da(split, i, NULL);
		ft_free_arraylist(list->a, list->b, 0);
	}
	while (split[++index])
		if (creat_newnode(&list->a, split, index) == 0)
			ft_free_arraylist(list->a, list->b, 0);
	if (index == 1)
	{
		ft_free_2da(split, index, NULL);
		ft_free_arraylist(list->a, list->b, 1);
	}
	ft_free_2da(split, index, NULL);
	ft_list_check(list);
}

/*----------------- int to list -------------------*/
void	int_to_lst(char **av, t_pshswp *list)
{
	int	index;

	index = 0;
	if (ft_arg_check(av) == 0)
		ft_free_arraylist(list->a, list->b, 0);
	while (av[index])
	{
		if (creat_newnode(&list->a, av, index) == 0)
			ft_free_arraylist(list->a, list->b, 0);
		index++;
	}
	ft_list_check(list);
}
