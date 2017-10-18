/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:06:30 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/18 19:14:18 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ocp_to_param_types(t_instruction *inst, unsigned char ocp)
{
	t_arg_type	*param_types;
	char		*arg;

	param_types = inst->param_types;
	arg = op_tab[inst->opcode - 1].arg;
	param_types[0] = ocp >> 6;
	// if ((!param_types[0] && arg[0]) || !(arg[0] & (1 << (param_types[0] - 1))))
	// 	inst->invalid = 1;
	param_types[1] = (ocp >> 4) & 3;
	// if ((!param_types[1] && arg[1]) || !(arg[1] & (1 << (param_types[1] - 1))))
	// 	inst->invalid = 1;
	param_types[2] = (ocp >> 2) & 3;
	// if ((!param_types[2] && arg[2]) || !(arg[2] & (1 << (param_types[2] - 1))))
	// 	inst->invalid = 1;
	if (ocp & 3)
		inst->invalid = 1;
}
