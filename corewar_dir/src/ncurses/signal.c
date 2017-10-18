/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:16:38 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/17 16:27:13 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	sign(int s)
{
	endwin();
	exit(s);
}

void	handle_signal(void)
{
	signal(SIGINT, &sign);
	signal(SIGKILL, &sign);
	signal(SIGTERM, &sign);
	signal(SIGQUIT, &sign);
	signal(SIGHUP, &sign);
}
