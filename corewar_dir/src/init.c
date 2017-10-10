/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:17:26 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/10 16:49:15 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_player(int n, t_vm *vm)
{
	t_player	*player;
	int			pc;

	player = &vm->players[n];
	pc = n * MEM_SIZE / vm->num_players;
	// !!! Check for cases when the program goes out of the memory?
	ft_memcpy(vm->ram + pc, player->prog, player->header.prog_size);
	create_process(vm, pc, player->number, 0);
}

void		init_vm(t_vm *vm)
{
	int	i;

	ft_bzero(vm->ram, MEM_SIZE);
	vm->processes = NULL;
	i = 0;
	while (i < vm->num_players)
	{
		init_player(i, vm);
		i++;
	}
}
