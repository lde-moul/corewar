/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 19:15:53 by gdelabro          #+#    #+#             */
/*   Updated: 2017/11/02 16:28:39 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	write_arg(t_asm *e)
{
	int		i;
	int		nb;
	short	nb1;
	char	nb2;

	i = -1;
	while (++i < e->u.nb_param)
	{
		nb = swap_int(e->u.value[i]);
		nb1 = swap_short(e->u.value[i]);
		nb2 = e->u.value[i];
		(e->u.t_arg[i] == T_DIR && g_op[e->u.i].d2) || e->u.t_arg[i] == T_IND
			? write(e->fd, &nb1, 2) : 0;
		e->u.t_arg[i] == T_DIR && !g_op[e->u.i].d2 ? write(e->fd, &nb, 4) : 0;
		e->u.t_arg[i] == T_REG ? write(e->fd, &nb2, 1) : 0;
	}
}
