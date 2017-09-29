/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:10:14 by gdelabro          #+#    #+#             */
/*   Updated: 2017/09/29 16:51:47 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include "../../ft_printf/ft_printf.h"
#include "../op/op.h"
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

typedef struct	s_player
{
	int				number;
	t_header		header;
	int				last_live;
	int				nb_live;
}					t_player;

typedef struct	s_instruction
{
	int				name;
	int				ocp;
	int				p[3];
}					t_instruction;

typedef struct	s_proc
{
	int				r[REG_NUMBER];
	int				pc;
	int				carry;
	int				id;
	int				nb_cycles;
	int				last_live;
	t_instruction	inst;
}					t_proc;

typedef struct	s_vm
{
	char			ram[MEM_SIZE];
	// t_proc		*processes;
	int				num_players;
	t_player		players[MAX_PLAYERS];
	int				dump_cycles;
}				t_vm;

int				parse(int argc, char **argv, t_vm *vm);
int				load_player(t_player *player, const char *name);

int				swap_int(int n);
int				swap_short(short n);

void	ft_direct_load(int source, int *dest, int *carry);

#endif
