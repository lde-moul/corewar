/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:59:59 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/19 18:43:15 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_winner(t_vm *vm)
{
	int i;
	int i2;

	i2 = 0;
	i = -1;
	while (++i < vm->num_players)
		vm->players[i].last_live > vm->players[i2].last_live ? i2 = i : 0;
	ft_printf("Contestant %d, \"%s\" (\"%s\") has won !\n", i2 + 1,
		vm->players[i2].header.prog_name, vm->players[i2].header.comment);
}

int	main(int argc, char **argv)
{
	t_vm	vm;

	parse(argc, argv, &vm);
	vm.visu = 1;
	init_vm(&vm);
	if (vm.visu)
		init_ncurses(&vm);
	if (vm.visu)
		display_ram(&vm);
	handle_main_loop(&vm);
	display_winner(&vm);
	// !!! Display winner
//	getch();
	if (vm.visu)
		endwin();
	return (0);
}
