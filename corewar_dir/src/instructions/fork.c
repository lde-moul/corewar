/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:20:24 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/17 18:35:14 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cor_fork(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	create_process(vm, (proc->pc + inst->params[0] % IDX_MOD) % MEM_SIZE, 0, 1);
	memcpy(vm->processes->r, proc->r, REG_NUMBER);
	vm->processes->carry = proc->carry;
}

void	cor_lfork(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	create_process(vm, (proc->pc + inst->params[0]) % MEM_SIZE, 0, 1);
	memcpy(vm->processes->r, proc->r, REG_NUMBER);
	vm->processes->carry = proc->carry;
}

// void	cpy_reg(int src[REG_NUMBER], int dst[REG_NUMBER])
// {
// 	int	i;
//
// 	i = 0;
// 	while (i <= REG_NUMBER)
// 	{
// 		dst[i] = src[i];
// 		++i;
// 	}
// }
//
// void	cor_fork(t_vm *vm, t_proc *src, t_instruction *inst)
// {
// 	t_proc	*new;
//
// 	if (!(new = malloc(sizeof(t_proc))))
// 		exit (1);
// 	cpy_reg(src->r, new->r);
// 	new->pc = ((src->pc + (inst->params[0] % IDX_MOD)) % MEM_SIZE);
// 	new->carry = src->carry;
// 	new->cycles = src->cycles;
// 	new->opcode = src->opcode;
// 	new->next = NULL;
// 	vm->processes = new;
// 	new->next = src;
// }
//
// void	cor_lfork(t_vm *vm, t_proc *src, t_instruction *inst)
// {
// 	t_proc	*new;
//
// 	if (!(new = malloc(sizeof(t_proc))))
// 		exit (1);
// 	cpy_reg(src->r, new->r);
// 	new->pc = ((src->pc + inst->params[0]) % MEM_SIZE);
// 	new->carry = src->carry;
// 	new->cycles = src->cycles;
// 	new->opcode = src->opcode;
// 	new->next = NULL;
// 	vm->processes = new;
// 	new->next = src;
// }
