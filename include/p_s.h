/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:53:33 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/08 08:24:02 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_S_H
# define P_S_H

# include <stdlib.h>
# include "../libft/include/libft.h"

typedef struct s_index
{
	int	i;
	int	j;
	int	k;
}	t_index;

typedef struct s_pshswp
{
	t_dlist	*a;
	t_dlist	*b;
	t_index	index;
}	t_pshswp;

void	int_to_lst(char **av, t_pshswp *list);
void	char_to_lst(char *av, t_pshswp *list);
void	ft_free_arraylist(t_dlist *a, t_dlist *b, int sortie);

int		check_arg2(char *str);
int		check_order(t_dlist *list);
void	check_algo(t_pshswp *data);
void	algo_2nb(t_dlist *list);
void	algo_3nb(t_dlist **list);
void	algo_5nb(t_pshswp *list);
void	algo_radix(t_pshswp *list, size_t lenght, t_dlist **a, t_dlist **b);

void	swap_a(t_dlist **lst_a);
void	swap_b(t_dlist **lst_b);
void	swap_ss(t_pshswp *data);

void	rotate_a(t_dlist **lst);
void	rotate_b(t_dlist **lst);
void	rotate_rr(t_pshswp *data);

void	r_rotate_a(t_dlist **lst);
void	r_rotate_b(t_dlist **lst);
void	r_rotate_rr(t_pshswp *data);

void	push_a(t_dlist **lst_a, t_dlist **lst_b);
void	push_b(t_dlist **lst_a, t_dlist **lst_b);

#endif