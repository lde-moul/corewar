/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:59:59 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/17 19:06:53 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	// !!! Display winner
//	getch();
	if (vm.visu)
		endwin();
	return (0);
}
