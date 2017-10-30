/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:26:21 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/30 16:55:53 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int			i;

	i = 0;
	proc->alive = 1;
	vm->num_lives++;
	vm->tot_lives++;
	while (i < vm->num_players)
	{
		if (vm->players[i].number == inst->params[0])
		{
			if (vm->show_lives && !vm->visu && vm->dump_cycle == -1)
				ft_printf("The player \"%s\" ($%d) is in life !\n",
					vm->players[i].header.prog_name, inst->params[0]);
			else if (vm->show_lives)
				mvprintw(60, 200, "The player \"%s\" ($%d) is in life !\n",
					vm->players[i].header.prog_name, inst->params[0]);
			++(vm->players[i].nb_live);
			vm->players[i].last_live = vm->cycle;
			vm->winner = i;
			return ;
		}
		++i;
	}
	if (vm->show_lives)
		mvprintw(60, 200, "The player \"%s\" ($%d) is in life !\n",
			vm->players[i].header.prog_name, inst->params[0]);
}
