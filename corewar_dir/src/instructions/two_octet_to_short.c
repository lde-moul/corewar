/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_octet_to_short.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:09:19 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/02 18:44:45 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

short	two_octets_to_short(char ram[MEM_SIZE], int pc)
{
	char	tab[2];

	tab[0] = ram[(pc + 1) % MEM_SIZE];
	tab[1] = ram[pc];
	return (*((short*)tab));
}
