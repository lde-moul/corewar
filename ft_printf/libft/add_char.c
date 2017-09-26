/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:22:40 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/04 19:34:24 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_char(char *str, char c)
{
	int i;

	i = ft_strlen(str);
	str[i + 1] = 0;
	while (i != -1 && (str[i] = str[i - 1]))
		--i;
	str[0] = c;
}
