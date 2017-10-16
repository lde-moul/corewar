/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:26:21 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/16 17:24:33 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

void	live(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int			i;

	i = 0;
	while (i < vm->num_players)
	{
		if (vm->players[i].number == inst->params[0])
		{
			ft_printf("The player $%s ($%#x) is in life !\n",
					vm->players[i].header.prog_name, inst->params[0]);
			++(vm->players[i].nb_live);
			vm->players[i].last_live = proc->cycles;
			return ;
		}
		++i;
	}
	ft_printf("The player $UnknownPlayer ($%#x) is in life !\n",
			inst->params[0]);
}
