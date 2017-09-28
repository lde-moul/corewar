/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:38:02 by gdelabro          #+#    #+#             */
/*   Updated: 2017/09/27 21:03:20 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

void	pars_info(t_asm *e)
{
	int		i;
	int		i2;
	char	*name;

	i = -1;
	while (is_space(e->file[++i]) && e->file[i])
		;
	--i;
	i2 = -1;
	while (e->file[++i] && !is_space(e->file[i]) && ++i2 < PROG_NAME_LENGTH)
		e->name[i2] = e->file[i];
}
