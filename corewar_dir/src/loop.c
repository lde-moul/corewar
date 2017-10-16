/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:15:47 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/16 19:10:32 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	handle_processes(t_vm *vm)
{
	t_proc	*process;

	// printf("\nHandling processes\n");
	process = vm->processes;
	while (process)
	{
		// printf("Process cycles: %d\n", process->cycles);
		process->cycles--;
		if (!process->cycles)
			execute_instruction(process, vm);
		process = process->next;
	}
}

void		handle_main_loop(t_vm *vm)
{
	while (vm->cycle < 10000) // !!!
	{
		display_ram(vm);
		getch();
		// !!! Handle dump
		// if (vm->cycle == vm->dump_cycle)
		handle_processes(vm);
		vm->check_cycles--;
		if (!vm->check_cycles && !check_processes(vm))
			break ;
		vm->cycle++;
	}
}
