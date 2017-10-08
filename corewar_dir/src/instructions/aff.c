#include "corewar.h"

void	aff(t_proc *proc, t_instruction *inst)
{
	ft_printf("%s", inst->params[0] % 256);
	proc->carry = inst->params[0] % 256 == 0 ? 1 : 0;
}
