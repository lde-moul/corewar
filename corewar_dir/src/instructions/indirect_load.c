#include "corewar.h"

void	indirect_load(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	param_a;
	int	param_b;

	if (inst->param_types[0] == IND_CODE)
		param_a = four_octets_to_int(vm->ram,
			(MEM_SIZE + proc->pc + (inst->params[0] % IDX_MOD) + 2) % MEM_SIZE);
	else
		param_a = inst->params[0];
	if (inst->param_types[1] == IND_CODE)
		param_b = four_octets_to_int(vm->ram,
			(MEM_SIZE + proc->pc + (inst->params[1] % IDX_MOD) + 2) % MEM_SIZE);
	else
		param_b = inst->params[1];
	proc->r[inst->params[2]] = param_a + param_b;
	proc->carry = proc->r[inst->params[2]] == 0 ? 1 : 0;
}

void	long_indirect_load(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	param_a;
	int	param_b;

	if (inst->param_types[0] == IND_CODE)
		param_a = four_octets_to_int(vm->ram,
			(MEM_SIZE + proc->pc + inst->params[0] + 2) % MEM_SIZE);
	else
		param_a = inst->params[0];
	if (inst->param_types[1] == IND_CODE)
		param_b = four_octets_to_int(vm->ram,
			(MEM_SIZE + proc->pc + inst->params[1] + 2) % MEM_SIZE);
	else
		param_b = inst->params[1];
	proc->r[inst->params[2]] = param_a + param_b;
	proc->carry = proc->r[inst->params[2]] == 0 ? 1 : 0;
}
