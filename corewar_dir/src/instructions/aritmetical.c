/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:13:23 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/09 18:24:23 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	(void)vm;
	proc->r[inst->params[2]] =
		proc->r[inst->params[0]] + proc->r[inst->params[1]];
	proc->carry = proc->r[inst->params[2]] == 0 ? 1 : 0;
}

void	sub(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	(void)vm;
	proc->r[inst->params[2]] =
		proc->r[inst->params[0]] - proc->r[inst->params[1]];
	proc->carry = proc->r[inst->params[2]] == 0 ? 1 : 0;
}
