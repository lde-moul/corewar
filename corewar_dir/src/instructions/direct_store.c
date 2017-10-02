/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:57:37 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/02 16:18:53 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

void	direct_store(t_vm *vm, t_proc *proc, int nb_reg, int value)
{
	vm->ram[(proc->pc + (value % IDX_MOD)) % MEM_SIZE] =
		proc->r[nb_reg] & 0x000000ff;
	vm->ram[(proc->pc + 1 + (value % IDX_MOD)) % MEM_SIZE] =
		proc->r[nb_reg] & 0x0000ff00 >> 8;
	vm->ram[(proc->pc + 2 + (value % IDX_MOD)) % MEM_SIZE] =
		proc->r[nb_reg] & 0x00ff0000 >> 16;
	vm->ram[(proc->pc + 3 + (value % IDX_MOD)) % MEM_SIZE] =
		proc->r[nb_reg] & 0xff000000 >> 24;
}
