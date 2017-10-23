/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_ram_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:55:51 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/23 16:51:39 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	change_ram_color(t_vm *vm, int pc, int pc_dest)
{
	int	color;

	color = vm->ram_color[pc];
	color = color > 5 ? color - 5 : color;
	vm->ram_color[mod_adr(pc_dest)] = color;
	vm->ram_glow[mod_adr(pc_dest)] = 10;
	vm->ram_color[mod_adr(pc_dest + 1)] = color;
	vm->ram_glow[mod_adr(pc_dest + 1)] = 10;
	vm->ram_color[mod_adr(pc_dest + 2)] = color;
	vm->ram_glow[mod_adr(pc_dest + 2)] = 10;
	vm->ram_color[mod_adr(pc_dest + 3)] = color;
	vm->ram_glow[mod_adr(pc_dest + 3)] = 10;
}
