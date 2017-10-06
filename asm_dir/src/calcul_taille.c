/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_taille.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:40:52 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/06 17:39:00 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		calcul_taille(t_asm *e)
{
	int t;
	int i;

	t = 1;
	t += op_tab[e->u.i].ocp;
	i = -1;
	while (++i < e->u.nb_param)
	{
		e->u.t_arg[i] == T_DIR ? t += 4 - op_tab[e->u.i].d2 * 2 : 0;
		e->u.t_arg[i] == T_IND ? t += 2 : 0;
		e->u.t_arg[i] == T_REG ? t += 1 : 0;
	}
	return (t);
}
