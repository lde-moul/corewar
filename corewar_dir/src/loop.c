/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:15:47 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/20 19:07:56 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	handle_processes(t_vm *vm)
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
}

static int	display_if_needed(t_vm *vm)
{
	struct timeval	current_time;
	struct timeval	time_diff;

	gettimeofday(&current_time, NULL);
	timersub(&current_time, &vm->last_display, &time_diff);
	if (!vm->pause
		&& (time_diff.tv_sec || time_diff.tv_usec >= DISPLAY_FREQUENCY))
	{
		display_ram(vm);
		gettimeofday(&vm->last_display, NULL);
	}
	if (sleep_display(vm))
		return (1);
	return (0);
}

void		handle_main_loop(t_vm *vm)
{
	while (1)
	{
		if (vm->visu && display_if_needed(vm))
			return ;
		if (!vm->pause)
		{
			if (vm->cycle == vm->dump_cycle)
				dump_ram(vm);
			vm->cycle++;
			handle_processes(vm);
			vm->check_cycles--;
			if (!vm->check_cycles && !check_processes(vm))
				break ;
			if (vm->visu)
				usleep(vm->speed);
		}
	}
}
