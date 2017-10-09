/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:37:32 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/09 18:45:03 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	free_label(t_asm *e)
{
	int i;

	i = -1;
	while (++i < e->nb_lab)
	{
		e->split[e->l[i].l] -= e->l[i].i;
		ft_strdel(&e->l[i].label);
	}
	e->l ? free(e->l) : 0;
}

void	free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	tab ? free(tab) : 0;
}

void	free_struct(t_asm *e)
{
	e->nb_lab ? free_label(e) : 0;
	ft_strdel(&e->file);
	ft_strdel(&e->file_name);
	ft_strdel(&e->new_file);
	free_tab(e->split);
	e ? free(e) : 0;
}
