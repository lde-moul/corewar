/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:59:59 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/27 20:41:53 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_winner(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\" (\"%s\") has won !\n", vm->winner + 1,
		vm->players[vm->winner].header.prog_name,
		vm->players[vm->winner].header.comment);
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	parse(argc, argv, &vm);
	init_vm(&vm);
	if (vm.visu)
		init_ncurses(&vm);
	handle_main_loop(&vm);
	display_winner(&vm);
	if (vm.visu)
		endwin();
	return (0);
}
