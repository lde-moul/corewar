/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:23:29 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/19 18:52:42 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

void	display_one_player(t_vm *vm, int line, WINDOW *players, int i)
{
	mvwprintw(players, line, 3, "Player (%d): %s",
			vm->players[i].number, vm->players[i].prog);
	mvwprintw(players, line + 1, 5, "Last live %d", vm->players[i].last_live);
	mvwprintw(players, line + 2, 5, "Number of live: %d",
			vm->players[i].nb_live);
}
void	display_players(t_vm *vm, WINDOW *info)
{
	WINDOW	*players;
	int		i;

	i = 0;
	players = subwin(info, 4 * vm->num_players, 70, 7, 195);
	while (i < vm->num_players)
	{
		display_one_player(vm, 7 + 4 * i, players, i);
		++i;
	}
	wrefresh(players);
	delwin(players);
}


