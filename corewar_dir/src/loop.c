/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:15:47 by lde-moul          #+#    #+#             */
/*   Updated: 2017/11/01 19:00:02 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		handle_processes(t_vm *vm)
{
	t_proc	*process;

	process = vm->processes;
	while (process)
	{
		if (!process->cycles)
			pre_execute_instruction(process, vm);
		process->cycles--;
		if (!process->cycles)
			execute_instruction(process, vm);
		process = process->next;
	}
}

static int		display_if_needed(t_vm *vm)
{
	if (sleep_display(vm))
		return (1);
	display_ram(vm);
	return (0);
}

static void		downgrade_glow(t_vm *vm)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		vm->ram_glow[i] ? vm->ram_glow[i] -= 1 : 0;
		!vm->ram_glow[i] ? (vm->ram_viewed[i] = 0) : 0;
	}
}

void			handle_main_loop(t_vm *vm)
{
	while (1)
	{
		vm->sbs = 0;
		if (vm->visu && display_if_needed(vm))
			return ;
		if (!vm->pause || vm->sbs)
		{
			if (vm->cycle == vm->dump_cycle && !vm->visu)
				dump_ram(vm);
			vm->cycle++;
			downgrade_glow(vm);
			handle_processes(vm);
			vm->check_cycles--;
			if (!vm->check_cycles && !check_processes(vm))
				break ;
			if (vm->visu)
				usleep(vm->speed);
		}
	}
	vm->win = 1;
	if (vm->visu)
		display_ram(vm);
	while (vm->visu && getch() != 27)
		;
}
