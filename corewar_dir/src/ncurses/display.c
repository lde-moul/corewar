/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:51:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/27 20:27:32 by lde-moul         ###   ########.fr       */
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
		proc = proc->next;
	}
	proc = vm->viewed_process;
	if (proc)
	{
		attron(COLOR_PAIR(11));
		attron(A_BOLD);
		attron(A_UNDERLINE);
		mvprintw(proc->pc / 64 + 1, proc->pc % 64 * 3 + 2, "%.2x",
			vm->ram[proc->pc]);
		attroff(A_UNDERLINE);
		attroff(A_BOLD);
		attroff(COLOR_PAIR(11));
	}
}

void	display_info(t_vm *vm)
{
	WINDOW	*info;
	int		line;

	line = 9;
	info = subwin(stdscr, 66, 70, 0, 195);
	box(info, ACS_VLINE, ACS_HLINE);
	mvwprintw(info, 3, 3, "Current_cycle: %d", vm->cycle);
	mvwprintw(info, 5, 3, "Current_live: %-10d", vm->num_lives);
	mvwprintw(info, 7, 3, "Processes: %-10d", vm->num_processes);
	display_players(vm, info, &line);
	mvwprintw(info, line + 1, 3, "Cycle to Die: %-4d", vm->cycle_to_die);
	mvwprintw(info, line + 3, 3, "Cycle Delta: %d", CYCLE_DELTA);
	mvwprintw(info, line + 5, 3, "Total_live: %d", vm->tot_lives);
	if (vm->viewed_process)
		mvwprintw(info, line + 7, 3, "Viewed process: %d",
		vm->viewed_process->id);
	vm->win ? display_winner_ncurse(vm, info, line + 5) : 0;
	wrefresh(info);
	delwin(info);
}

void	creat_first_win(WINDOW **ram, int *i, int *j, int *pc)
{
	*ram = subwin(stdscr, 66, 195, 0, 0);
	box(*ram, ACS_VLINE, ACS_HLINE);
	*i = 0;
	*j = 2;
	*pc = 0;
}

void	display_ram(t_vm *vm)
{
	WINDOW	*ram;
	int		i;
	int		j;
	int		pc;

	creat_first_win(&ram, &i, &j, &pc);
	while (++i < 65 && (j = 2))
	{
		move(i, 2);
		while (j < 193)
		{
			attron(COLOR_PAIR(vm->ram_color[pc]));
			vm->ram_glow[pc] ? attron(WA_BOLD) : 0;
			printw("%.2x ", vm->ram[pc]);
			vm->ram_glow[pc] ? attroff(WA_BOLD) : 0;
			attroff(COLOR_PAIR(vm->ram_color[pc]));
			++pc;
			j += 3;
		}
	}
	display_info(vm);
	display_pc(vm);
	curs_set(0);
	refresh();
	delwin(ram);
}
