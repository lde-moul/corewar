/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:15:47 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/27 22:34:57 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		handle_processes(t_vm *vm)
{
	t_proc	*process;

	process = vm->processes;
	while (process)
	{
		process->cycles--;
		if (!process->cycles)
			execute_instruction(process, vm);
		process = process->next;
	}
	process = vm->processes;
	while (process)
	{
		if (!process->cycles)
			pre_execute_instruction(process, vm);
		process = process->next;
	}
}

static int		display_if_needed(t_vm *vm)
{
	struct timeval	current_time;
	struct timeval	time_diff;

	gettimeofday(&current_time, NULL);
	timersub(&current_time, &vm->last_display, &time_diff);
	if (sleep_display(vm))
		return (1);
	//	//&& (time_diff.tv_sec || time_diff.tv_usec >= DISPLAY_FREQUENCY))
		display_ram(vm);
	//	gettimeofday(&vm->last_display, NULL);
	return (0);
}

static void		downgrade_glow(t_vm *vm)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
		vm->ram_glow[i] ? vm->ram_glow[i] -= 1 : 0;
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
	vm->visu ? display_ram(vm) : 0;
	while (vm->visu && getch() != 27)
		;
}
