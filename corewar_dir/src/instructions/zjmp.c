/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:44:11 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/11 16:46:27 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	(void)vm;
	if (proc->carry == 1)
		proc->pc = (proc->pc + inst->params[0]) % MEM_SIZE;
}
