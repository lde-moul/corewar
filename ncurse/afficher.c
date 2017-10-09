/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:51:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/09 19:06:25 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ncurses.h>
#include "corewar.h"

void	afficher(t_vm *vm)
{
	WINDOW *boite;
	int	i = 1;
	int	j = 2;
	int	pc = 0;

	initscr();
	boite= subwin(stdscr, 66, 195, 0, 0);
	box(boite, ACS_VLINE, ACS_HLINE);
	while (i < 65)
	{
		move(i, 2);
		while (j < 193)
		{
			printw("%.2x ", vm->r[pc]);
			++pc;
			j += 3;
		}
		++i;
		j = 2;
	}
	refresh();
	getch();
	endwin();
	free(boite);
}
