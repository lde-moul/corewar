/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:56:20 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/16 19:25:24 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_process(t_vm *vm, int pc, int player_num, int no_init)
{
	t_proc	*process;

	process = (t_proc*)malloc(sizeof(t_proc));
	if (!process)
		exit(1); // !!! Handle the error instead of just exiting?
	process->next = vm->processes;
	vm->processes = process;
	process->pc = pc;
	pre_execute_instruction(process, vm);
	if (no_init)
		return ;
	process->r[0] = player_num;
	bzero(&process->r[1], (REG_NUMBER - 1) * sizeof(int));
	process->carry = 0;
	process->alive = 0;
}

void	kill_process(t_proc *process, t_vm *vm)
{
	t_proc	**prev_next;

	ft_printf("RIP\n");
	// !!! Optimisation: store previous process to avoid iterating through all processes?
	prev_next = &vm->processes;
	while (*prev_next != process)
		prev_next = &(*prev_next)->next;
	*prev_next = process->next;
	free(process);
}


// !!!!
// void	fork(t_vm *vm, t_proc *proc, t_instruction *inst)
// {
// 	create_process(vm, (src->pc + (inst->params[0] % IDX_MOD)) % MEM_SIZE,
// 		player_num, 1);
// 	memcpy(vm->processes->r, proc->r, REG_NUMBER)
// 	vm->processes->carry = proc->carry;
// }
