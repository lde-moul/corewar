/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:38:02 by gdelabro          #+#    #+#             */
/*   Updated: 2017/11/02 16:29:29 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		is_space3(char *c, int i)
{
	if (c[i] == ' ' || c[i] == '\t')
		return (1);
	if (c[i] == COMMENT_CHAR)
	{
		c[i] = ' ';
		while (c[++i] && c[i] != '\n')
			c[i] = ' ';
		return (1);
	}
	return (0);
}

int		is_space2(char *c, int i)
{
	if (c[i] == ' ' || c[i] == '\t' || c[i] == '\n')
		return (1);
	if (c[i] == COMMENT_CHAR)
	{
		while (c[++i] && c[i] != '\n')
			c[i] = ' ';
		return (1);
	}
	return (0);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

void	pars_comment(t_asm *e, int i)
{
	int		i2;

	i2 = -1;
	e->file[i] != '\n' ? ft_exit(5) : 0;
	while (is_space2(e->file, ++i) && e->file[i])
		;
	--i;
	i2 = -1;
	while (e->file[++i] && !is_space2(e->file, i) && ++i2 < COMMENT_LENGTH)
		e->comment[i2] = e->file[i];
	i2 == COMMENT_LENGTH || ft_strcmp(e->comment, COMMENT_CMD_STRING)
		? ft_exit(5) : 0;
	--i;
	ft_bzero(e->comment, COMMENT_LENGTH);
	while (is_space2(e->file, ++i) && e->file[i])
		;
	e->file[i] == '\"' ? 0 : ft_exit(5);
	i2 = -1;
	while (e->file[++i] && e->file[i] != '\"' && ++i2 < COMMENT_LENGTH)
		e->comment[i2] = e->file[i];
	i2 == COMMENT_LENGTH || !e->file[i] ? ft_exit(5) : 0;
	while (e->file[++i] && is_space3(e->file, i))
		;
	e->file[i] != '\n' ? ft_exit(5) : 0;
	split_file(e, i);
}

void	pars_info(t_asm *e)
{
	int		i;
	int		i2;

	i = -1;
	while (is_space2(e->file, ++i) && e->file[i])
		;
	--i;
	i2 = -1;
	while (e->file[++i] && !is_space2(e->file, i) && ++i2 < PROG_NAME_LENGTH)
		e->name[i2] = e->file[i];
	i2 == PROG_NAME_LENGTH || ft_strcmp(e->name, NAME_CMD_STRING)
		? ft_exit(4) : 0;
	--i;
	ft_bzero(e->name, PROG_NAME_LENGTH);
	while (is_space2(e->file, ++i) && e->file[i])
		;
	e->file[i] == '\"' ? 0 : ft_exit(4);
	i2 = -1;
	while (e->file[++i] && e->file[i] != '\"' && ++i2 < PROG_NAME_LENGTH)
		e->name[i2] = e->file[i];
	i2 == PROG_NAME_LENGTH || !e->file[i] ? ft_exit(4) : 0;
	while (e->file[++i] && is_space3(e->file, i))
		;
	pars_comment(e, i);
}
