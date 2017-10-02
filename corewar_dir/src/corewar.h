/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:10:14 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/02 18:56:20 by afourcad         ###   ########.fr       */
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

void			parse(int argc, char **argv, t_vm *vm);
void			load_player(t_player *p, const char *name);

int				swap_int(int n);
unsigned int	swap_uint(unsigned int n);
short			swap_short(short n);

/*
** Instructions
*/

short			two_octets_to_short(char ram[MEM_SIZE], int pc);
int				four_octets_to_short(char ram[MEM_SIZE], int pc);

void			direct_load(int source, int *dest, int *carry);
void			add(int	r1, int r2, int *r3, int *carry);
void			direct_store(t_vm *vm, t_proc *proc, int nb_reg, int value);
void			live(int number, t_player *player[MAX_PLAYERS]);
void			add(int	r1, int r2, int *r3, int *carry);
void			sub(int r1, int r2, int *r3, int *carry);
void			and(int param_a, int param_b, int *reg, int *carry);
void			or(int param_a, int param_b, int *reg, int *carry);
void			xor(int param_a, int param_b, int *reg, int *carry);
void			zjmp(short jump, int *pc, int carry);

#endif
