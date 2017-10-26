/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:23:29 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/26 20:15:18 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		taille_nb(int nb)
{
	int t;
	int i;

	i = 0;
	t = nb == -2147483648 || !nb ? 1 : 0;
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

int		search_winner(t_vm *vm)
{
	int i;
	int i2;

	i2 = 0;
	i = -1;
	while (++i < vm->num_players)
		vm->players[i].last_live > vm->players[i2].last_live ? i2 = i : 0;
	return (i2);
}

void	display_winner_ncurse(t_vm *vm, WINDOW *info, int line)
{
	int player_num;

	player_num = search_winner(vm);
	wmove(info, line + 10, 3);
	wprintw(info, "The winner is:");
	wattron(info, COLOR_PAIR(player_num + 2));
	wattron(info, WA_BOLD);
	wprintw(info, " %.51s",
			vm->players[player_num].header.prog_name);
	wmove(info, line + 12, 3);
	wattroff(info, COLOR_PAIR(player_num + 2));
	wattroff(info, WA_BOLD);
	wprintw(info, "Press ESC to finish.");
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
		wattron(info, WA_BOLD);
		wprintw(info, "%.44s", vm->players[players].header.prog_name);
		wattroff(info, COLOR_PAIR(players + 2));
		wattroff(info, WA_BOLD);
		mvwprintw(info, *line + 1, 5, "Last live %-10d",
				vm->players[players].last_live);
		mvwprintw(info, *line + 2, 5, "Number of live: %-10d",
				vm->players[players].nb_live);
		++players;
		*line = *line + 4;
	}
}
