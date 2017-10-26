/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:51:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/26 19:56:59 by gdelabro         ###   ########.fr       */
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
	vm->win ? display_winner_ncurse(vm, info, line + 5) : 0;
	/*mvwprintw(info, line + 8, 3, "Carry: %d", vm->processes->carry);
	mvwprintw(info, line + 10, 3, "r1: %.8x", vm->processes->r[0]);
	mvwprintw(info, line + 11, 3, "r2: %.8x", vm->processes->r[1]);
	mvwprintw(info, line + 12, 3, "r3: %.8x", vm->processes->r[2]);
	mvwprintw(info, line + 13, 3, "r4: %.8x", vm->processes->r[3]);*/
	wrefresh(info);
	delwin(info);
}

void	display_ram(t_vm *vm)
{
	WINDOW *ram;
	int	i = 1;
	int	j = 2;
	int	pc = 0;

	ram = subwin(stdscr, 66, 195, 0, 0);
	box(ram, ACS_VLINE, ACS_HLINE);
	while (i < 65)
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
		++i;
		j = 2;
	}
	display_info(vm);
	display_pc(vm);
	curs_set(0);
	refresh();
	delwin(ram);
}
