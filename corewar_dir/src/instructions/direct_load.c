/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:15:07 by afourcad          #+#    #+#             */
/*   Updated: 2017/09/29 17:09:33 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "corewar.h"

void	ft_direct_load(int source, int *dest, int *carry, int pc)
{
	*dest = source;
	*carry = *carry > 0 ? 0 : 1;
}
