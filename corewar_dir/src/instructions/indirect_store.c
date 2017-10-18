/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:36:04 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/18 17:36:31 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	indirect_store(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	param_2;
	int param_3;

	if (inst->param_types[1] == IND_CODE)
		param_2 = four_octets_to_int(vm->ram,
			(MEM_SIZE + proc->pc + (inst->params[1] % IDX_MOD) + 2) % MEM_SIZE);
	else
		param_2 = inst->params[1];
	if (inst->param_types[2] == IND_CODE)
		param_3 = four_octets_to_int(vm->ram,
			(MEM_SIZE + proc->pc + (inst->params[2] % IDX_MOD) + 2) % MEM_SIZE);
	else
		param_3 = inst->params[2];
	vm->ram[(MEM_SIZE + proc->pc + (param_2 + param_3 % IDX_MOD)) % MEM_SIZE] =
		proc->r[inst->params[0]] & 0x000000ff;
	vm->ram[(MEM_SIZE + proc->pc + 1 + (param_2 + param_3 % IDX_MOD))
		% MEM_SIZE] = proc->r[inst->params[0]] & 0x0000ff00 >> 8;
	vm->ram[(MEM_SIZE + proc->pc + 2 + (param_2 + param_3 % IDX_MOD))
		% MEM_SIZE] = proc->r[inst->params[0]] & 0x00ff0000 >> 16;
	vm->ram[(MEM_SIZE + proc->pc + 3 + (param_2 + param_3 % IDX_MOD))
		% MEM_SIZE] = proc->r[inst->params[0]] & 0xff000000 >> 24;
	change_ram_color(vm, proc->pc,
			(MEM_SIZE + proc->pc + (param_2 + param_3 % IDX_MOD)) % MEM_SIZE);
	proc->carry = param_2 + param_3 == 0 ? 1 : 0;
}
