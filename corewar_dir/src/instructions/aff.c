#include "corewar.h"

void	aff(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	(void)vm;
	ft_printf("%c", inst->params[0] % 256);
	proc->carry = inst->params[0] % 256 == 0 ? 1 : 0;
}
