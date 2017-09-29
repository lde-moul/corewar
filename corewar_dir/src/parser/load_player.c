/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:56:09 by lde-moul          #+#    #+#             */
/*   Updated: 2017/09/29 16:31:55 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	error(const char *msg, const char *name)
{
	ft_printf(msg, name);
	exit(1);
}

void		load_player(t_player *p, const char *name)
{
	int	file;

	file = open(name, O_RDONLY);
	if (file < 0)
		error("Can't open \"%s\"\n", name);
	if (read(file, &p->header, sizeof(t_header)) != sizeof(t_header))
		error("\"%s\" is too short\n", name);
	if (swap_int(p->header.magic) != COREWAR_EXEC_MAGIC)
		error("Invalid magic number in \"%s\"", name);
	p->header.prog_size = swap_uint(p->header.prog_size);
	p->header.prog_name[PROG_NAME_LENGTH] = '\0';
	p->header.comment[COMMENT_LENGTH] = '\0';
	if (p->header.prog_size > CHAMP_MAX_SIZE)
		error("\"%s\" is too long\n", name);
	if (read(file, p->prog, p->header.prog_size) != p->header.prog_size)
		error("\"%s\" is too long\n", name);
	close(file);
}
