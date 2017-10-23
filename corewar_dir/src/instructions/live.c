/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:26:21 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/23 17:02:23 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int			i;

	proc->alive = 1;
	vm->num_lives++;
	vm->tot_lives++;
	i = 0;
	while (i < vm->num_players)
	{
		if (vm->players[i].number == inst->params[0])
		{
			if (!vm->visu && vm->dump_cycle == -1)
				ft_printf("The player \"%s\" ($%d) is in life !\n",
					vm->players[i].header.prog_name, inst->params[0]);
			++(vm->players[i].nb_live);
			vm->players[i].last_live = vm->cycle;
			return ;
		}
		++i;
	}
	if (!vm->visu && vm->dump_cycle == -1)
		ft_printf("The player \"UnknownPlayer\" ($%d) is in life !\n",
			inst->params[0]);
}
