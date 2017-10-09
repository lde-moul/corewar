/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:15:47 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/06 18:45:50 by lde-moul         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < 30)
	{
		handle_processes(vm);
		i++;
	}
}
