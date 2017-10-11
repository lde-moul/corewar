/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:51:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/11 18:26:39 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_ram(t_vm *vm)
{
	WINDOW *boite;
	int	i = 1;
	int	j = 2;
	int	pc = 0;

	initscr();
	boite = subwin(stdscr, 66, 195, 0, 0);
	box(boite, ACS_VLINE, ACS_HLINE);
	while (i < 65)
	{
		move(i, 2);
		while (j < 193)
		{
			printw("%.2x ", vm->ram[pc]);
			++pc;
			j += 3;
		}
		++i;
		j = 2;
	}
	refresh();
	getch();
//	free(boite);
}
