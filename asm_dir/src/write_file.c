/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:41:42 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/09 18:45:33 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	write_ocp(t_asm *e)
{
	int		i;
	char	ocp;
	char	tmp;

	i = -1;
	ocp = 0;
	if (!op_tab[e->u.i].ocp)
		return ;
	while (++i < e->u.nb_param)
	{
		tmp = 0;
		e->u.t_arg[i] == T_DIR ? tmp = 2 : 0;
		e->u.t_arg[i] == T_REG ? tmp = 1 : 0;
		e->u.t_arg[i] == T_IND ? tmp = 3 : 0;
		ocp += tmp << (2 * (3 - i));
	}
	write(e->fd, &ocp, 1);
}

void	write_instruction(t_asm *e)
{
	write(e->fd, &op_tab[e->u.i].id, 1);
	write_ocp(e);
	write_arg(e);
}

void	write_header(t_asm *e)
{
	t_header t;

	ft_bzero(&t, sizeof(t));
	t.magic = swap_uint(COREWAR_EXEC_MAGIC);
	ft_strcpy(t.prog_name, e->name);
	ft_strcpy(t.comment, e->comment);
	t.prog_size = swap_uint(e->num);
	write(e->fd, &t, sizeof(t));
}

void	init_write(t_asm *e)
{
	int i;

	!(e->new_file =
			malloc((i = ft_strlen(e->file_name)) + 5)) ? ft_exit(2) : 0;
	ft_bzero(e->new_file, ft_strlen(e->file_name) + 5);
	ft_strcpy(e->new_file, e->file_name);
	while (--i >= 0 && e->new_file[i] != '.' && e->new_file[i] != '/')
		;
	if ((e->new_file[i] == '/' || !i) && e->new_file[i] != '.')
		ft_strcat(e->new_file, ".cor");
	else
		ft_strcpy(e->new_file + i + 1, "cor");
	close(e->fd);
	(e->fd = open(e->new_file, O_CREAT | O_WRONLY | O_TRUNC,
		S_IRUSR | S_IWUSR)) < 0 ? ft_exit(11) : 0;
	ft_printf("writing output program to %s\n", e->new_file);
	write_header(e);
}

void	write_file(t_asm *e)
{
	int i;

	i = -1;
	init_write(e);
	e->num = 0;
	e->test = 2;
	while (e->split[++i])
	{
		test_instruction(e->split[i], e);
		e->i ? write_instruction(e) : 0;
	}
}
