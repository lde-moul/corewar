/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:15:47 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/02 18:57:56 by lde-moul         ###   ########.fr       */
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

void		handle_main_loop(t_vm *vm)
{
	while (0)
	{
		handle_processes(vm);
	}
}
