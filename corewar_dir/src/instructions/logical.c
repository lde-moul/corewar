/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:26:15 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/02 16:31:21 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cor_and(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	param_a;
	int	param_b;

	if (inst->param_types[0] == IND_CODE)
		param_a = four_octets_to_int(vm->ram,
			(proc->pc + (inst->params[0] % IDX_MOD) + 2) % MEM_SIZE);
	else
		param_a = inst->params[0];
	if (inst->param_types[1] == IND_CODE)
		param_b = four_octets_to_int(vm->ram,
			(proc->pc + (inst->params[1] % IDX_MOD) + 2) % MEM_SIZE);
	else
		param_b = inst->params[1];
	proc->r[inst->params[2]] = param_a & param_b;
	proc->carry = proc->r[inst->params[2]] == 0 ? 1 : 0;
}

void	cor_or(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	param_a;
	int	param_b;

	if (inst->param_types[0] == IND_CODE)
		param_a = four_octets_to_int(vm->ram,
			(proc->pc + (inst->params[0] % IDX_MOD) + 2) % MEM_SIZE);
	else
		param_a = inst->params[0];
	if (inst->param_types[1] == IND_CODE)
		param_b = four_octets_to_int(vm->ram,
			(proc->pc + (inst->params[1] % IDX_MOD) + 2) % MEM_SIZE);
	else
		param_b = inst->params[1];
	proc->r[inst->params[2]] = param_a | param_b;
	proc->carry = proc->r[inst->params[2]] == 0 ? 1 : 0;
}

void	cor_xor(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	param_a;
	int	param_b;

	if (inst->param_types[0] == IND_CODE)
		param_a = four_octets_to_int(vm->ram,
			(proc->pc + (inst->params[0] % IDX_MOD) + 2) % MEM_SIZE);
	else
		param_a = inst->params[0];
	if (inst->param_types[1] == IND_CODE)
		param_b = four_octets_to_int(vm->ram,
			(proc->pc + (inst->params[1] % IDX_MOD) + 2) % MEM_SIZE);
	else
		param_b = inst->params[1];
	proc->r[inst->params[2]] = param_a ^ param_b;
	proc->carry = proc->r[inst->params[2]] == 0 ? 1 : 0;
}
