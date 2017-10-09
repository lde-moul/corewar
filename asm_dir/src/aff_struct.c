/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:52:27 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/09 18:44:49 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	aff_struct(t_asm *e)
{
	ft_printf("{green}name: {none}%s\n"
			"{blue}comment: {none}%s\n"
			"{yellow}size (champ): {none}%d bytes\n"
			"{yellow}size (file): {none}%d bytes\n"
			"{red}instruction number: {none}%d\n"
			, e->name, e->comment, e->num, e->num + sizeof(t_header)
			, e->nb_instruction);
}
