/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:22:51 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/05 18:13:09 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

static void	ocp_to_param_types(t_arg_type param_types[3], char ocp)
{
	param_types[0] = ocp >> 6;
	if (!param_types[0])
		return ;
	param_types[1] = (ocp >> 4) & 3;
	if (!param_types[1])
		return ;
	param_types[2] = (ocp >> 2) & 3;
}

static void	read_param(int *value, t_arg_type type, char ram[MEM_SIZE], int *pc)
{
	if (type == REG_CODE)
	{
		*value = ram[*pc]; // !!! Check invalid register number
		*pc = (*pc + 1) % MEM_SIZE;
	}
	else if (type == DIR_CODE)
	{
		*value = four_octets_to_int(ram, *pc);
		*pc = (*pc + 4) % MEM_SIZE;
	}
	else if (type == IND_CODE) // !!! Unfinished
	{
		*value = two_octets_to_short(ram, *pc);
		*pc = (*pc + 2) % MEM_SIZE;
	}
}

void		execute_instruction(t_proc *proc, t_vm *vm)
{
	t_instruction	inst;

	printf("Executing instruction at %d\n", proc->pc);
	// !!! Check for invalid opcode. How do we handle them? By killing the proc?
	// !!! Check if the ocp is not allowed for this instruction?
	inst.opcode = proc->opcode;
	inst.id = inst->opcode - 1;
	proc->pc = (proc->pc + 1) % MEM_SIZE;
	if (ocp_needed(op_tab[inst.id].arg))
	{
		inst->ocp = vm->ram[proc->pc];
		ocp_to_param_types(inst->param_types, inst->ocp);
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		read_param(&inst->params[0], inst->param_types[0], vm->ram, &proc->pc);
	}
	printf("opcode: %s (%d)\n", op_tab[(int)vm->ram[proc->pc] - 1].name, (int)vm->ram[proc->pc]);
	print_ocp((int)vm->ram[proc->pc + 1]);
}
