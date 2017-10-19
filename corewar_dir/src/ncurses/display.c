/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:51:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/18 17:00:49 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void	display_pc(t_vm *vm)
{
	t_proc *proc;

	proc = vm->processes;
	while (proc)
	{
		attron(COLOR_PAIR(vm->ram_color[proc->pc] + 5));
		mvprintw(proc->pc / 64 + 1, proc->pc % 64 * 3 + 2, "%.2x",
				vm->ram[proc->pc]);
		attroff(COLOR_PAIR(vm->ram_color[proc->pc] + 5));
		mvprintw(proc->pc / 64 + 1, proc->pc % 64 * 3 + 4, " ");
		proc = proc->next;
	}
}

void	display_ram(t_vm *vm)
{
	WINDOW *boite;
	int	i = 1;
	int	j = 2;
	int	pc = 0;
	
	boite = subwin(stdscr, 66, 195, 0, 0);
	box(boite, ACS_VLINE, ACS_HLINE);
	while (i < 65)
	{
		move(i, 2);
		while (j < 193)
		{
			attron(COLOR_PAIR(vm->ram_color[pc]));
			printw("%.2x ", vm->ram[pc]);
			attroff(COLOR_PAIR(vm->ram_color[pc]));
			++pc;
			j += 3;
		}
		++i;
		j = 2;
	}
	display_pc(vm);
	curs_set(0);
	refresh();
	free(boite);
}
