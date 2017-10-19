/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:15:47 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/19 16:17:51 by afourcad         ###   ########.fr       */
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
	while (1)
	{
		if (vm->visu)
		{
			display_ram(vm);
			if (sleep_display(vm))
				return ;
		}
		// !!! Handle dump
		// if (vm->cycle == vm->dump_cycle)
		if(!vm->pause)
		{
			handle_processes(vm);
			vm->check_cycles--;
			if (!vm->check_cycles && !check_processes(vm))
				break ;
			vm->cycle++;
			usleep(vm->speed);
		}
	}
}
