/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:51:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/25 18:51:23 by afourcad         ###   ########.fr       */
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
	mvwprintw(info, 5, 3, "Current_live: %-10d", vm->num_lives);
	while (players < vm->num_players)
	{
		mvwprintw(info, line, 3, "Player (%d): %s",
				-vm->players[players].number, vm->players[players].header.prog_name);
		mvwprintw(info, line + 1, 5, "Last live %-10d", vm->players[players].last_live);
		mvwprintw(info, line + 2, 5, "Number of live: %-10d",
				vm->players[players].nb_live);
		++players;
		line = line + 4;
	}
	mvwprintw(info, line + 1, 3, "Cycle to Die: %-4d", vm->cycle_to_die);
	mvwprintw(info, line + 3, 3, "Cycle Delta: %d", CYCLE_DELTA);
	mvwprintw(info, line + 5, 3, "Total_live: %d", vm->tot_lives);
<<<<<<< HEAD
	mvwprintw(info, line + 7, 3, "Carry: %d", vm->processes->carry);
	mvwprintw(info, line + 9, 3, "r1: %x", vm->processes->r[0]);
	mvwprintw(info, line + 10, 3, "r2: %x", vm->processes->r[1]);
	mvwprintw(info, line + 11, 3, "r3: %x", vm->processes->r[2]);
	mvwprintw(info, line + 12, 3, "r4: %x", vm->processes->r[3]);
=======
	/*mvwprintw(info, line + 8, 3, "Carry: %d", vm->processes->carry);
	mvwprintw(info, line + 10, 3, "r1: %.8x", vm->processes->r[0]);
	mvwprintw(info, line + 11, 3, "r2: %.8x", vm->processes->r[1]);
	mvwprintw(info, line + 12, 3, "r3: %.8x", vm->processes->r[2]);
	mvwprintw(info, line + 13, 3, "r4: %.8x", vm->processes->r[3]);*/
>>>>>>> master
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
