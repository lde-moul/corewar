/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:56:20 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/02 19:47:04 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_process(t_vm *vm, int pc, int player_number)
{
	t_proc	new_process;

	new_process = (t_proc*)malloc(sizeof(t_proc));
	if (!new_process)
		exit(1); // !!! Handle the error instead of just exiting?
	new_process->pc = pc;
	bzero(&new_process->r[1], (REG_NUMBER - 1) * sizeof(int));
	new_process->r[0] = player_number;
	new_process->carry = 0;
	new_process->cycles = op_tab[vm->ram[pc]].cycles; // !!! Check for array overflows
	// new_process->cycles = 3; // !!! Read the opcode to know the cycle number
	new_process->last_live = 0; // !!!
	new_process->next = vm->processes;
	vm->processes = new_process;
}

void	kill_process(t_proc *process, t_vm *vm)
{
	t_proc	**prev_next;

	// !!! Optimisation: store previous process to avoid iterating through all processes?
	prev_next = &vm->processes;
	while (*prev_next != process)
		prev_next = &(*prev_next)->next;
	*prev_next = process->next;
	free(process);
}

void	execute_instruction(t_proc *process, t_vm *vm)
{
	// !!! Check for invalid opcode. How do we handle them? By killing the process?
}
