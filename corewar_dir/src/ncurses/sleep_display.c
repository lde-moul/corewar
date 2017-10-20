/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:42:12 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/20 16:40:51 by lde-moul         ###   ########.fr       */
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
	else if (key == '=')
		vm->speed = vm->speed - SPEED_STEP > MAX_SPEED ?
			vm->speed - SPEED_STEP : MAX_SPEED;
	else if (key == '-' && vm->speed < MIN_SPEED)
		vm->speed = vm->speed + SPEED_STEP > MIN_SPEED ?
			vm->speed + SPEED_STEP : MIN_SPEED;
	else if (key == ']')
		vm->speed = MAX_SPEED;
	else if (key == '[')
		vm->speed = MIN_SPEED;
	return (0);
}
