/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:53:33 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/24 10:46:25 by nrossel          ###   ########.fr       */
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
	t_dlist	*lst_a;
	t_dlist	*lst_b;
	t_index	index;
}	t_pshswp;

void	char_to_lst(char *av, t_pshswp *list);
void	int_to_lst(char **av, t_pshswp *list);

void	check_algo(t_pshswp *data);
void	algo_2nb(t_dlist *list);

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

void	test_ft(t_pshswp *data);
void	ft_printlist(t_dlist *list, char *nom_list);

#endif