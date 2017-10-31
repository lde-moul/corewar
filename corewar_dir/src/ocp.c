/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:06:30 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/31 16:38:23 by gdelabro         ###   ########.fr       */
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
	pt[1] = op_tab[inst->opcode - 1].nb_param >= 2 ? ((ocp >> 4) & 3) : 0;
	pt[2] = op_tab[inst->opcode - 1].nb_param >= 3 ? ((ocp >> 2) & 3) : 0;
	if (!pt[0] || !(arg[0] & (1 << (pt[0] - 1))))
		inst->invalid = 1;
	if (op_tab[inst->opcode - 1].nb_param < 2)
		return ;
	if (!pt[1] || (pt[1] && !(arg[1] & (1 << (pt[1] - 1)))))
		inst->invalid = 1;
	if (op_tab[inst->opcode - 1].nb_param < 3)
		return ;
	if (!pt[2] || (pt[2] && !(arg[2] & (1 << (pt[2] - 1)))))
		inst->invalid = 1;
}

/*void	test_valid_param(t_instruction *inst, t_op o)
{
	int i;
	int v;

	i = -1;
	while (++i < o.nb_param)
	{
		v = 0;
		inst->param_types[i] == REG_CODE ?
			v = T_REG : 0;
		inst->param_types[i] == DIR_CODE ?
			v = T_DIR : 0;
		inst->param_types[i] == IND_CODE ?
			v = T_IND : 0;
		!(v & o.arg[i]) ?
			inst->invalid = 1 : 0;
	}
}

void	ocp_to_param_types(t_instruction *inst, unsigned char ocp)
{
	t_arg_type	*pt;
	t_op		o;

	pt = inst->param_types;
	o = op_tab[inst->opcode - 1];
	pt[0] = ocp >> 6;
	pt[1] = o.nb_param >= 2 ? (ocp >> 4) & 3 : 0;
	pt[2] = o.nb_param >= 3 ? (ocp >> 2) & 3 : 0;
	test_valid_param(inst, o);
}*/
