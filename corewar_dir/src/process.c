/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:56:20 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/27 20:11:29 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_process(t_vm *vm, int pc, int player_num, int no_init)
{
	static int	id = 0;
	t_proc		*process;

	process = (t_proc*)malloc(sizeof(t_proc));
	if (!process)
		exit(1);
	vm->num_processes++;
	process->next = vm->processes;
	vm->processes = process;
	process->id = id++;
	process->pc = pc;
	pre_execute_instruction(process, vm);
	process->alive = 0;
	if (no_init)
		return ;
	process->r[0] = player_num;
	bzero(&process->r[1], (REG_NUMBER - 1) * sizeof(int));
	process->carry = 0;
}

void	kill_process(t_proc *process, t_vm *vm)
{
	t_proc	**prev_next;

	prev_next = &vm->processes;
	while (*prev_next != process)
		prev_next = &(*prev_next)->next;
	*prev_next = process->next;
	free(process);
	vm->num_processes--;
	if (vm->viewed_process == process)
		vm->viewed_process = NULL;
}
