/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:23:29 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/26 19:31:12 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		taille_nb(int nb)
{
	int t;
	int i;

	i = 0;
	t = nb == -2147483648 || !nb? 1 : 0;
	nb == -2147483648 ? nb = -214748364 : 0;
	nb < 0 ? t += 1 : 0;
	nb < 0 ? nb *= -1 : 0;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (t + i);
}

void	display_players(t_vm *vm, WINDOW *info, int *line)
{
	int players;

	players = 0;
	while (players < vm->num_players)
	{
		mvwprintw(info, *line, 3, "Player (%d): ",
				vm->players[players].number);
		wattron(info, COLOR_PAIR(players + 2));
		wattron(info, WA_ALTCHARSET);
		wprintw(info, "%.53s", vm->players[players].header.prog_name);
		wattroff(info, COLOR_PAIR(players + 2));
		wattroff(info, WA_ALTCHARSET);
		mvwprintw(info, *line + 1, 5, "Last live %-10d",
				vm->players[players].last_live);
		mvwprintw(info, *line + 2, 5, "Number of live: %-10d",
				vm->players[players].nb_live);
		++players;
		*line = *line + 4;
	}
}
