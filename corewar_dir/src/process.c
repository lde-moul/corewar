/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:56:20 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/03 20:32:16 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		create_process(t_vm *vm, int pc, int player_number)
{
	t_proc	*new_process;

	new_process = (t_proc*)malloc(sizeof(t_proc));
	if (!new_process)
		exit(1); // !!! Handle the error instead of just exiting?
	new_process->pc = pc;
	bzero(&new_process->r[1], (REG_NUMBER - 1) * sizeof(int));
	new_process->r[0] = player_number;
	new_process->carry = 0;
	new_process->cycles = op_tab[(int)vm->ram[pc] - 1].cycles; // !!! Check for array overflows
	new_process->last_live = 0; // !!!
	new_process->next = vm->processes;
	vm->processes = new_process;
}

void		kill_process(t_proc *process, t_vm *vm)
{
	t_proc	**prev_next;

	// !!! Optimisation: store previous process to avoid iterating through all processes?
	prev_next = &vm->processes;
	while (*prev_next != process)
		prev_next = &(*prev_next)->next;
	*prev_next = process->next;
	free(process);
}

// !!!
static void print_sub_ocp(char sub_ocp)
{
	switch (sub_ocp)
	{
		case 0: printf("none"); break ;
		case 1: printf("register"); break ;
		case 2: printf("direct"); break ;
		case 3: printf("index"); break ;
		default: printf("invalid"); break ;
	}
}

// !!!
static void print_ocp(char ocp)
{
	// printf("ocp: %d\n", (int)vm->ram[process->pc + 1]);
	printf("ocp: ");
	print_sub_ocp((ocp >> 6) & 3);
	printf(", ");
	print_sub_ocp((ocp >> 4) & 3);
	printf(", ");
	print_sub_ocp((ocp >> 2) & 3);
}

// opcode [ocp] params

static int	ocp_needed(char arg[3])
{
	if (arg[0] != 1 && arg[0] != 2 && arg[0] != 4)
		return (1);
	if (!arg[1])
		return (0);
	if (arg[1] != 1 && arg[1] != 2 && arg[1] != 4)
		return (1);
	if (!arg[2])
		return (0);
	return (arg[2] != 1 && arg[2] != 2 && arg[2] != 4);
}

void		execute_instruction(t_proc *process, t_vm *vm)
{
	t_instruction	instruction;

	printf("Executing instruction at %d\n", process->pc);
	// !!! Check for invalid opcode. How do we handle them? By killing the process?
	// !!! Check if the ocp is not allowed for this instruction?
	instruction.opcode = vm->ram[process->pc];
	instruction.id = instruction->opcode - 1;
	process->pc = (process->pc + 1) % MEM_SIZE;
	if (ocp_needed(op_tab[instruction.id].arg))
	{
		instruction->ocp = vm->ram[process->pc];
		process->pc = (process->pc + 1) % MEM_SIZE;
		instruction->param_types[0] = instruction->ocp >> 6;
		instruction->param_types[0] = (instruction->ocp >> 4) & 3;
		instruction->param_types[0] = (instruction->ocp >> 4) & 3;
	}
	printf("opcode: %s (%d)\n", op_tab[(int)vm->ram[process->pc] - 1].name, (int)vm->ram[process->pc]);
	print_ocp((int)vm->ram[process->pc + 1]);
}
