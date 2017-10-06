/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:56:42 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/06 18:23:58 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	init_struct_asm(t_asm *e, char *file)
{
	(e->fd = open(file, O_RDONLY)) <= 0 ? ft_exit(3) : 0;
	ft_bzero(e->name, PROG_NAME_LENGTH + 1);
	ft_bzero(e->comment, COMMENT_LENGTH + 1);
	e->i = -1;
	e->nb_lab = 0;
	e->l = NULL;
	e->num = 0;
	e->u.t_n = 0;
	e->u.nb_param = 0;
	e->u.t_p[0] = 0;
	e->u.t_p[1] = 0;
	e->u.t_p[2] = 0;
	!(e->file_name = ft_strdup(file)) ? ft_exit(2) : 0;
	ft_cpyfile(e->fd, &e->file);
	pars_info(e);
}

int		main(int ac, char **av)
{
	t_asm	*e;

	if (ac != 2)
		ft_exit(1);
	!(e = malloc(sizeof(*e))) ? ft_exit(2) : 0;
	init_struct_asm(e, av[1]);
	fill_label(e);
	//aff_struct(e);
	return (1);
}
