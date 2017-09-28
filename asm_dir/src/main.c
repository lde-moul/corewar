/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:56:42 by gdelabro          #+#    #+#             */
/*   Updated: 2017/09/28 18:08:46 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	del_com(char *file)
{
	int i;

	i = -1;
	while (file[++i])
		if (file[i] == COMMENT_CHAR)
			while (file[i] && file[i] != '\n')
				file[i++] = '\n';
}

void	init_struct_asm(t_asm *e, char *file)
{
	(e->fd = open(file, O_RDONLY)) <= 0 ? ft_exit(3) : 0;
	ft_bzero(e->name, PROG_NAME_LENGTH);
	e->name_enter = 0;
	ft_bzero(e->comment, COMMENT_LENGTH);
	e->com_enter = 0;
	e->i = -1;
	!(e->file_name = ft_strdup(file)) ? ft_exit(2) : 0;
	ft_cpyfile(e->fd, &e->file);
	pars_info(e);
	del_com(e->file);
	e->split = ft_strsplit(e->file, '\n');
}

int		main(int ac, char **av)
{
	t_asm	*e;

	if (ac != 2)
		ft_exit(1);
	e = malloc(sizeof(*e));
	init_struct_asm(e, av[1]);
	return (1);
}
