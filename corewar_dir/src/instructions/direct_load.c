/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:15:07 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/16 18:08:21 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

void	direct_load(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	rel_pc;

	rel_pc = 0;
	if (inst->param_types[0] == IND_CODE)
	{
		rel_pc = (MEM_SIZE + proc->pc + (inst->params[0] % IDX_MOD) + 2)
			% MEM_SIZE;
		proc->r[inst->params[1]] = four_octets_to_int(vm->ram, rel_pc);
	}
	else
		proc->r[inst->params[1]] = inst->params[0];
	proc->carry = inst->params[0] == 0 ? 1 : 0;
}

void	long_direct_load(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	rel_pc;

	rel_pc = 0;
	if (inst->param_types[0] == IND_CODE)
	{
		rel_pc = (MEM_SIZE + proc->pc + inst->params[0] + 2) % MEM_SIZE;
		proc->r[inst->params[1]] = four_octets_to_int(vm->ram, rel_pc);
	}
	else
		proc->r[inst->params[1]] = inst->params[0];
	proc->carry = inst->params[0] == 0 ? 1 : 0;
}
