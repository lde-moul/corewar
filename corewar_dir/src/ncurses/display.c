/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:51:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/20 20:03:50 by lde-moul         ###   ########.fr       */
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
	int		players;

	players = 0;
	line  = 7;
	info = subwin(stdscr, 66, 70, 0, 195);
	box(info, ACS_VLINE, ACS_HLINE);
	mvwprintw(info, 3, 3, "Current_cycle: %d", vm->cycle);
	mvwprintw(info, 5, 3, "Current_live: %d", vm->num_lives);
	while (players < vm->num_players)
	{
		mvwprintw(info, line, 3, "Player (%d): %s",
				-vm->players[players].number, vm->players[players].header.prog_name);
		mvwprintw(info, line + 1, 5, "Last live %d", vm->players[players].last_live);
		mvwprintw(info, line + 2, 5, "Number of live: %d",
				vm->players[players].nb_live);
		++players;
		line = line + 4;
	}
	mvwprintw(info, line + 1, 3, "Cycle to Die: %d", vm->cycle_to_die);
	mvwprintw(info, line + 3, 3, "Cycle Delta: %d", CYCLE_DELTA);
	mvwprintw(info, line + 5, 3, "Total_live: %d", vm->tot_lives);
	wrefresh(info);
	//display_players(vm, info);
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
			printw("%.2x ", vm->ram[pc]);
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
