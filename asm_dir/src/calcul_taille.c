/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_taille.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:40:52 by gdelabro          #+#    #+#             */
/*   Updated: 2017/11/02 16:27:31 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		calcul_taille(t_asm *e)
{
	int t;
	int i;

	t = 1;
	t += g_op[e->u.i].ocp;
	i = -1;
	while (++i < e->u.nb_param)
	{
		e->u.t_arg[i] == T_DIR ? t += 4 - g_op[e->u.i].d2 * 2 : 0;
		e->u.t_arg[i] == T_IND ? t += 2 : 0;
		e->u.t_arg[i] == T_REG ? t += 1 : 0;
	}
	return (t);
}
