/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:26:21 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/05 17:27:05 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

void	live(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	i;

	i = 0;
	while (vm->players[i] != NULL)
	{
		if (player[i]->number == number)
		{
			ft_printf("The player $%s ($%#x) is in life !",
					player[i]->header.prog_name, number);
			++(player[i]->nb_live);
			// incrementer last_live
			return ;
		}
		++i;
	}
	ft_printf("The player $UnknownPlayer ($%#x) is in life !", number);
}
