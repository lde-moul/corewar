/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:06:30 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/19 18:41:51 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ocp_to_param_types(t_instruction *inst, unsigned char ocp)
{
	t_arg_type	*pt;
	char		*arg;

	pt = inst->param_types;
	arg = op_tab[inst->opcode - 1].arg;
	pt[0] = ocp >> 6;
	if (!pt[0] != !arg[0] || (pt[0] && !((arg[0] & (1 << (pt[0] - 1))))))
		inst->invalid = 1;
	pt[1] = (ocp >> 4) & 3;
	if (!pt[1] != !arg[1] || (pt[1] && !((arg[1] & (1 << (pt[1] - 1))))))
		inst->invalid = 1;
	pt[2] = (ocp >> 2) & 3;
	if (!pt[2] != !arg[2] || (pt[2] && !((arg[2] & (1 << (pt[2] - 1))))))
		inst->invalid = 1;
	if (ocp & 3)
		inst->invalid = 1;
}
