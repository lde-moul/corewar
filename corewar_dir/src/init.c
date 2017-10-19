/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:17:26 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/19 16:58:15 by afourcad         ###   ########.fr       */
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
	ft_memset(vm->ram_color + pc, n + 2, player->header.prog_size);
	create_process(vm, pc, player->number, 0);
}

void		init_vm(t_vm *vm)
{
	int	i;

	ft_bzero(vm->ram, MEM_SIZE);
	ft_memset(vm->ram_color, 1, MEM_SIZE);
	vm->processes = NULL;
	i = 0;
	while (i < vm->num_players)
	{
		init_player(i, vm);
		i++;
	}
	vm->cycle = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->check_cycles = vm->cycle_to_die;
	vm->num_lives = 0;
	vm->tot_lives = 0;
	vm->checks = MAX_CHECKS;
}
