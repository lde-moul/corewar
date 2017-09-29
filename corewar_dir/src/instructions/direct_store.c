/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:57:37 by afourcad          #+#    #+#             */
/*   Updated: 2017/09/29 17:49:55 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

void	ft_direct_store(t_vm *vm, t_proc *proc, int nb_reg, int value)
{
	vm->ram[(proc->pc + (value % IDX_MOD)) % MEM_SIZE] = proc->r[nb_reg];
}
