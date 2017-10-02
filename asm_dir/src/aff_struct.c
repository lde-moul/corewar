/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:52:27 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/02 19:31:09 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	aff_struct(t_asm *e)
{
	int i;

	i = -1;
	ft_printf("name: {blue}%s{none}\ncomment: {green}%s{none}\nlabel:\n",
			e->name, e->comment);
	while (++i < e->nb_lab)
		ft_printf("%10s num: %d\n", e->l[i].label, e->l[i].num);
}
