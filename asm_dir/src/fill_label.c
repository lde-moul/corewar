/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:51:32 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/09 18:53:13 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		is_labchar(char c)
{
	int i;

	i = -1;
	while (LABEL_CHARS[++i])
		if (LABEL_CHARS[i] == c)
			return (1);
	return (0);
}

void	malloc_name_label(t_asm *e, int i, int i2)
{
	int		t;
	char	*lab;
	int		i3;

	t = 0;
	i3 = -1;
	while (--i2 >= 0 && is_labchar(e->split[i][i2]))
		t++;
	!(e->l[e->nb_lab - 1].label = malloc(sizeof(char) * t)) ? ft_exit(2) : 0;
	lab = e->l[e->nb_lab - 1].label;
	while (is_labchar(e->split[i][++i2]))
		lab[++i3] = e->split[i][i2];
	lab[++i3] = 0;
	e->l[e->nb_lab - 1].num = e->num;
	e->l[e->nb_lab - 1].l = i;
	e->l[e->nb_lab - 1].i = i2 + 1;
}

void	creat_label_struct(t_asm *e, int i, int i2)
{
	e->nb_lab++;
	e->l = !e->l ? malloc(sizeof(t_lab) * 1)
		: realloc(e->l, sizeof(t_lab) * e->nb_lab);
	!e->l ? ft_exit(2) : 0;
	malloc_name_label(e, i, i2);
}

void	fill_label(t_asm *e)
{
	int		i;
	int		i2;
	char	c;

	i = -1;
	while (!(e->test = 0)
			&& e->split[++i] && (i2 = -1))
	{
		while ((c = e->split[i][++i2]) && (c == ' ' || c == '\t'))
			;
		--i2;
		while ((c = e->split[i][++i2]) && is_labchar(c))
			;
		if (i2 >= 1 && c == LABEL_CHAR && is_labchar(e->split[i][i2 - 1]))
			creat_label_struct(e, i, i2);
		else
			i2 = -1;
		test_instruction(e->split[i] += i2 + 1, e);
	}
	e->num = 0;
	i = -1;
	while ((e->test = 1) && e->split[++i])
		test_instruction(e->split[i], e);
	write_file(e);
}
