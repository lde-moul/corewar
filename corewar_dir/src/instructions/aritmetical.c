/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:13:23 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/02 16:25:30 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add(t_proc *proc, t_instruction *inst)
{
	proc->r[inst->params[2]] =
		proc->r[inst->params[0]] + proc->r[inst->params[1]];
	proc->carry = proc->r[inst->params[2]] == 0 ? 1 : 0;
}

void	sub(t_proc *proc, t_instruction *inst)
{
	proc->r[inst->params[2]] =
		proc->r[inst->params[0]] - proc->r[inst->params[1]];
	proc->carry = proc->r[inst->params[2]] == 0 ? 1 : 0;
}
