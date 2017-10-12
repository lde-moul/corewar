/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:17:26 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/12 18:41:27 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_player(int n, t_vm *vm)
{
	t_player	*player;
	int			pc;

	player = &vm->players[n];
	pc = n * MEM_SIZE / vm->num_players;
	ft_memcpy(vm->ram + pc, player->prog, player->header.prog_size);
	ft_memset(vm->ram_color + pc, n + 1, player->header.prog_size);
	create_process(vm, pc, player->number, 0);
}

void		init_vm(t_vm *vm)
{
	int	i;

	ft_bzero(vm->ram, MEM_SIZE);
	ft_bzero(vm->ram_color, MEM_SIZE);
	vm->processes = NULL;
	i = 0;
	while (i < vm->num_players)
	{
		init_player(i, vm);
		i++;
	}
}
