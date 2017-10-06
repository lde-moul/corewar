/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arg_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 20:09:40 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/06 19:26:23 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

short			swap_short(short n)
{
	return (((n & 0x00ff) << 8)
		| ((n & 0xff00) >> 8));
}

int				swap_int(int n)
{
	return (((n & 0x000000ff) << 24)
		| ((n & 0x0000ff00) << 8)
		| ((n & 0x00ff0000) >> 8)
		| ((n & 0xff000000) >> 24));
}

unsigned int	swap_uint(unsigned int n)
{
	return (((n & 0x000000ff) << 24)
		| ((n & 0x0000ff00) << 8)
		| ((n & 0x00ff0000) >> 8)
		| ((n & 0xff000000) >> 24));
}

int				test_arg_label(char *arg, t_asm *e)
{
	int i;

	i = -1;
	if (ft_strlen(arg) < 2 || arg[0] != LABEL_CHAR)
		return (-1);
	if (!e->test)
		return (1);
	while (++i < e->nb_lab && ft_strcmp(arg + 1, e->l[i].label))
		;
	if (i != e->nb_lab)
		return (i);
	return (-1);
}
