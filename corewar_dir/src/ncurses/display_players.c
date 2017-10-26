/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:23:29 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/26 17:23:57 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_players(t_vm *vm, WINDOW *info, int *line)
{
	int players;

	players = 0;
	while (players < vm->num_players)
	{
		mvwprintw(info, *line, 3, "Player (%d): %s",
				-vm->players[players].number, vm->players[players].header.prog_name);
		mvwprintw(info, *line + 1, 5, "Last live %-10d", vm->players[players].last_live);
		mvwprintw(info, *line + 2, 5, "Number of live: %-10d",
				vm->players[players].nb_live);
		++players;
		*line = *line + 4;
	}
}
