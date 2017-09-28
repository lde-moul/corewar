/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:56:09 by lde-moul          #+#    #+#             */
/*   Updated: 2017/09/28 16:11:51 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>
#include <fcntl.h>

static void	check_magic_number(int magic, const char *name)
{
	if (swap_int(magic) != COREWAR_EXEC_MAGIC)
	{
		ft_printf("Invalid magic number in \"%s\"\n", name);
		exit(1);
	}
}

int			load_player(t_player *player, const char *name)
{
	int	file;

	file = open(name, O_RDONLY);
	if (file < 0)
	{
		ft_printf("Can't open \"%s\"\n", name);
		return (0);
	}
	if (read(file, &player->header, sizeof(t_header)) != sizeof(t_header))
	{
		ft_printf("\"%s\" is too short\n", name);
		return (0);
	}
	check_magic_number(player->header.magic, name);
	player->header.prog_name[PROG_NAME_LENGTH] = '\0';
	player->header.comment[COMMENT_LENGTH] = '\0';
	// !!! Check prog_size
	player->
	close(file);
	return (1);
}
