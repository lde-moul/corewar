/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:10:14 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/02 18:15:01 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include "../../ft_printf/ft_printf.h"
#include "../../op/op.h"
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

typedef struct	s_player
{
	int				number;
	unsigned char	prog[CHAMP_MAX_SIZE];
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
	char			carry;
	// int			id; // Unused?
	int				cycles;
	int				last_live;
	t_instruction	inst;
	struct s_proc	next;
}					t_proc;

typedef struct	s_vm
{
	char			ram[MEM_SIZE];
	t_proc			*processes;
	int				num_players;
	t_player		players[MAX_PLAYERS];
	int				dump_cycles;
}				t_vm;

void			init_vm(t_vm *vm);
void			handle_main_loop(t_vm *vm);

void			parse(int argc, char **argv, t_vm *vm);
void			load_player(t_player *p, const char *name);

int				swap_int(int n);
unsigned int	swap_uint(unsigned int n);
short			swap_short(short n);

void	ft_direct_load(int source, int *dest, int *carry);

#endif
