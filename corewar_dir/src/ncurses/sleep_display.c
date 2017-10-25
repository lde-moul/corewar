/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:42:12 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/25 16:59:23 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	sleep_display(t_vm *vm)
{
	int	key;

	if ((key = getch()) == ' ')
		vm->pause = !vm->pause;
	else if (key == 27)
		return (1);
	else if (key == '=')
		vm->speed = vm->speed > MAX_SPEED + SPEED_STEP ?
			vm->speed - SPEED_STEP : MAX_SPEED;
	else if (key == '-' && vm->speed < MIN_SPEED)
		vm->speed = vm->speed < MIN_SPEED - SPEED_STEP ?
			vm->speed + SPEED_STEP : MIN_SPEED;
	else if (key == ']')
		vm->speed = MAX_SPEED;
	else if (key == '[')
		vm->speed = MIN_SPEED;
	else if (key == 's')
		vm->sbs = 1;
	return (0);
}
