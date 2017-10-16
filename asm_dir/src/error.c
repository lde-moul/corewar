/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:07:31 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/16 19:43:07 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	ft_exit(int err)
{
	ft_printf("error: ");
	err == 1 ? ft_printf("bad argument\n") : 0;
	err == 2 ? ft_printf("malloc failed\n") : 0;
	err == 3 ? ft_printf("can't open file\n") : 0;
	err == 4 ? ft_printf("bad name\n") : 0;
	err == 5 ? ft_printf("bad comment\n") : 0;
	err == 6 ? ft_printf("bad instruction name found\n") : 0;
	err == 7 ? ft_printf("bad param number found\n") : 0;
	err == 8 ? ft_printf("error not found\n") : 0;
	err == 9 ? ft_printf("bad type of param found\n") : 0;
	err == 11 ? ft_printf("can't create new file\n") : 0;
	err == 12 ? ft_printf("empty code\n") : 0;
	exit(-1);
}
