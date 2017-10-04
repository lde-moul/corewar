#include "corewar.h"

void	cpy_reg(int src[REG_NUMBER], int dst[REG_NUMBER])
{
	int	i;

	i = 0;
	while (i <= REG_NUMBER)
	{
		dst[i] = src[i];
		++i;
	}
}

t_proc	*fork(t_proc *src, short pc)
{
	t_proc	*new;

	if (!(new = malloc(sizeof(t_proc))))
		return (NULL);
	cpy_reg(src->r, new->r);
	new->pc = ((src->pc + (pc % IDX_MOD)) % MEM_SIZE);
	new->carry = src->carry;
	new->cycles = src->cycles;
	new->last_live = src->last_live;
	new->inst = src->inst;
	// Placer le next;
	return (new);
}

t_proc	*lfork(t_proc *src, short pc)
{
	t_proc	*new;

	if (!(new = malloc(sizeof(t_proc))))
		return (NULL);
	cpy_reg(src->r, new->r);
	new->pc = ((src->pc + pc) % MEM_SIZE);
	new->carry = src->carry;
	new->cycles = src->cycles;
	new->last_live = src->last_live;
	new->inst = src->inst;
	// Placer le next;
	return (new);
}
