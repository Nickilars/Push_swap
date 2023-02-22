/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:18:24 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/22 15:32:39 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./p_s.h"

/******************** INITIALISATION ***********************/
void	ft_init(t_pshswp *data)
{
	data->index.i = 0;
	data->index.j = 0;
	data->index.k = 0;
	data->lst_a = ft_dlst_new();
	data->lst_b = ft_dlst_new();
}

/******************** CREAT NODE ***********************/
static void	creat_newnode(t_dlist **list, char **tab, int index)
{
	int		nbr;
	t_node	*new_node;

	nbr = ft_atoi(tab[index]);
	new_node = ft_dlst_newcontent(nbr);
	printf("valuer de new_node -> %d\n", *new_node->data);
	if ((*list)->head == NULL)
		ft_dlst_addfront(list, new_node);
	else
		ft_dlst_addback(list, new_node);
}

/******************** CHECK ARG VALID ***********************/
static void	ft_arg_check(t_dlist **list)
{
	t_node	*node_1;
	t_node	*node_2;

	node_1 = (*list)->head;
	printf("\nadresse node_1 -> %p\n", node_1);
	while (node_1->next != NULL)
	{
		node_2 = node_1->next;
		printf("adresse node_2 -> %p\n", node_2);
		while (node_2 != NULL)
		{
			printf("valeur node_1 -> %d\n", *node_1->data);
			printf("valeur node_2 -> %d\n", *node_1->data);
			if (*node_1->data == *node_2->data)
			{
				ft_dlst_clear(list, &ft_free);
				ft_free_arrays(NULL, NULL, "Erreur, arguments invalides");
			}
			node_2 = node_2->next;
		}
		node_1 = node_1->next;
	}
}

/******************** ARG TO LIST ***********************/
/*------------- string to list -----------------*/
void	char_to_lst(char *av, t_pshswp *list, t_index index)
{
	char	**split;

	split = ft_split(av, ' ');
	while (split[index.i])
	{
		creat_newnode(&list->lst_a, split, index.i);
		index.i++;
	}
	ft_free_2da(split, index.i, NULL);
	ft_arg_check(&list->lst_a);
}

/*----------------- int to list -------------------*/
void	int_to_lst(char **av, t_pshswp *list, t_index index)
{
	while (av[index.i])
	{
		creat_newnode(&list->lst_a, av, index.i);
		index.i++;
	}
	ft_printlist(&list->lst_a, "\nListe a (Après ajout node)");
	ft_arg_check(&list->lst_a);
}
