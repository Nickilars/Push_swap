/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:53:33 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/22 15:27:25 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_S_H
# define P_S_H

# include <stdlib.h>
# include "./libft/include/libft.h"

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

void	char_to_lst(char *av, t_pshswp *list, t_index index);
void	int_to_lst(char **av, t_pshswp *list, t_index index);
void	ft_init(t_pshswp *data);
void	ft_printlist(t_dlist **list, char *nom_list);

void	swap(t_dlist **lst);
void	rotate(t_dlist **lst);
void	r_rotate(t_dlist **lst);
void	push(t_dlist **lst_a, t_dlist **lst_b);

#endif