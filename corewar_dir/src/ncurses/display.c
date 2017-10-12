/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:51:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/12 18:42:03 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	refresh();
//	free(boite);
}
