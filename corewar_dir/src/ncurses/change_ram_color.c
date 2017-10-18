/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_ram_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:55:51 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/16 20:09:34 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

void	change_ram_color(t_vm *vm, int pc, int pc_dest)
{
	int	color;

	color = vm->ram_color[pc];
	color = color > 5 ? color - 5 : color;
	vm->ram_color[pc_dest % MEM_SIZE] = color;
	vm->ram_color[(pc_dest + 1) % MEM_SIZE] = color;
	vm->ram_color[(pc_dest + 2) % MEM_SIZE] = color;
	vm->ram_color[(pc_dest + 3) % MEM_SIZE] = color;
}
