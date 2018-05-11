/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:26:21 by gdelabro          #+#    #+#             */
/*   Updated: 2017/11/02 16:28:18 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	free_instruction(t_asm *e)
{
	int i;

	i = -1;
	while (++i < e->u.nb_param && !(e->u.t_p[i] = 0))
		ft_strdel(&(e->u.p[i]));
	ft_strdel(&(e->u.name));
	e->u.t_n = 0;
}

void	fill_nb_param(t_asm *e)
{
	e->u.i = -1;
	while (++e->u.i < 16 && ft_strcmp(g_op[e->u.i].name, e->u.name))
		;
	e->u.i == 16 ? ft_exit(6) : 0;
	e->u.nb_param = g_op[e->u.i].nb_param;
}

void	fill_param(char *line, t_asm *e)
{
	int i;
	int i2;

	i = 0;
	i2 = -1;
	while (++i2 < e->u.nb_param)
	{
		while (line[i + e->u.t_p[i2]] && !is_space(line[i + e->u.t_p[i2]])
				&& line[i + e->u.t_p[i2]] != ',')
			e->u.t_p[i2]++;
		!(e->u.p[i2] = malloc(e->u.t_p[i2] + 1)) ? ft_exit(2) : 0;
		e->u.p[i2][e->u.t_p[i2]] = 0;
		while (--e->u.t_p[i2] != -1)
			e->u.p[i2][e->u.t_p[i2]] = line[i + e->u.t_p[i2]];
		while (line[++i] && !is_space(line[i]) && line[i] != ',')
			;
		--i;
		while (line[++i] && is_space(line[i]))
			;
		(line[i] && i2 == e->u.nb_param - 1) || (line[i] != ',' && line[i])
			|| e->u.p[i2][0] == 0 ? ft_exit(7) : 0;
		while (i2 != e->u.nb_param - 1 && is_space(line[++i]))
			;
	}
}

void	fill_instruction(char *line, t_asm *e)
{
	int i;
	int i2;

	i = -1;
	while (is_space(line[++i]))
		;
	while (line[i + e->u.t_n] && !is_space(line[i + e->u.t_n]))
		e->u.t_n++;
	!(e->u.name = malloc(e->u.t_n + 1)) ? ft_exit(2) : 0;
	e->u.name[e->u.t_n] = 0;
	i2 = i + e->u.t_n;
	while (--e->u.t_n != -1)
		e->u.name[e->u.t_n] = line[i + e->u.t_n];
	i2--;
	while (line[++i2] && is_space(line[i2]))
		;
	fill_nb_param(e);
	fill_param(line + i2, e);
	test_arg(e);
}

void	test_instruction(char *line, t_asm *e)
{
	int i;
	int a;

	i = -1;
	a = 0;
	e->i = 0;
	while (line[++i])
		line[i] != ' ' || line[i] != '\t' ? a++ : 0;
	a ? fill_instruction(line, e) : 0;
	a ? e->i = 1 : 0;
	a && e->test == 2 ? e->nb_instruction++ : 0;
	free_instruction(e);
}
