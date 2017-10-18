/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:42:12 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/18 18:38:51 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	sleep_display(t_vm *vm)
{
	int	key;

	if((key = getch()) == ' ')
		vm->pause = !vm->pause;
	else if (key == 27)
		return (1);
	else if (key == '=' && vm->speed > MAX_SPEED)
		vm->speed -= 3000;
	else if (key == '=' && vm->speed <= MAX_SPEED)
		vm->speed = 10000;
	else if (key == '-' && vm->speed < MIN_SPEED)
		vm->speed += 3000;
	else if (key == '-' && vm->speed <= MIN_SPEED)
		vm->speed = 100000;
	else if (key == ']' && vm->speed > MAX_SPEED)
		vm->speed = MAX_SPEED;
	else if (key == '[' && vm->speed < MIN_SPEED)
		vm->speed = MIN_SPEED;
	return (0);
}
