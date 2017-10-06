/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:30:02 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/06 17:39:17 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		is_empty_line(t_asm *e, int i)
{
	while (e->file[i])
	{
		if (e->file[i] == '\n')
			return (1);
		else if (e->file[i] != ' ' && e->file[i] != '\t')
			return (0);
		i++;
	}
	return (0);
}

void	split_file(t_asm *e, int i2)
{
	int i;

	i = -1;
	while (e->file[++i])
		if (e->file[i] == COMMENT_CHAR)
			while (e->file[i] && e->file[i] != '\n')
				e->file[i++] = '\n';
	while (--i2 >= 0)
		e->file[i2] = '\n';
	i = -1;
	while (e->file[++i])
		if (is_empty_line(e, i))
			while (e->file[i] && e->file[i] != '\n')
				e->file[i++] = '\n';
	!(e->split = ft_strsplit(e->file, '\n')) ? ft_exit(2) : 0;
}
