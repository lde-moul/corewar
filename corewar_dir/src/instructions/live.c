/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:26:21 by afourcad          #+#    #+#             */
/*   Updated: 2017/09/28 19:56:24 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

void	live(int	number, t_player *player[MAX_PLAYERS])
{
	int	i;

	i = 0;
	while (player[i])
	{
		if (player[i]->number == number)
		{
			ft_printf("The player $%s ($%#x) is in life !",
					player[i]->header.prog_name, number);
			++(player[i]->nb_live);
			// incrementer last_live
			return ;
		}
		++i;
	}
	ft_printf("The player $UnknownPlayer ($%#x) is in life !", number);
}
