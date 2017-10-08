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

t_proc	*fork(t_proc *src, t_instruction *inst)
{
	t_proc	*new;
	t_proc	*lst;
	
	lst = src;
	if (!(new = malloc(sizeof(t_proc))))
		return (NULL);
	cpy_reg(src->r, new->r);
	new->pc = ((src->pc + (inst->params[0] % IDX_MOD)) % MEM_SIZE);
	new->carry = src->carry;
	new->cycles = src->cycles;
	new->last_live = src->last_live;
	new->opcode = src->opcode;
	new->next = NULL;
	// while(lst->next)
	//	lst = lst->next;
	//lst->next = &new;
	return (new);
}

t_proc	*lfork(t_proc *src, t_instruction *inst)
{
	t_proc	*new;
	t_proc	*lst;

	lst = src;
	if (!(new = malloc(sizeof(t_proc))))
		return (NULL);
	cpy_reg(src->r, new->r);
	new->pc = ((src->pc + inst->params[0]) % MEM_SIZE);
	new->carry = src->carry;
	new->cycles = src->cycles;
	new->last_live = src->last_live;
	new->opcode = src->opcode;
	new->next = NULL;
	// while(lst->next)
	//	lst = lst->next;
	//lst->next = &new;
	return (new);
}
