/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:10:14 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/05 18:50:24 by lde-moul         ###   ########.fr       */
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
	int				opcode;
	int				id;
	int				ocp;
	t_arg_type		param_types[3];
	int				params[3];
}					t_instruction;

typedef struct	s_proc
{
	int				r[REG_NUMBER];
	int				pc;
	char			carry;
	// int			id; // Unused?
	int				cycles;
	int				last_live;
	char			opcode;
	struct s_proc	*next;
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

void			create_process(t_vm *vm, int pc, int player_number);
void			kill_process(t_proc *process, t_vm *vm);
void			execute_instruction(t_proc *process, t_vm *vm);

int				ocp_needed(char arg[3]);
void			ocp_to_param_types(t_arg_type param_types[3], char ocp);

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
void			direct_store(t_vm *vm, t_proc *proc, int nb_reg, int value);
void			live(int number, t_player *player[MAX_PLAYERS]);
void			add(int	r1, int r2, int *r3, int *carry);
void			sub(int r1, int r2, int *r3, int *carry);
void			and(int param_a, int param_b, int *reg, int *carry);
void			or(int param_a, int param_b, int *reg, int *carry);
void			xor(int param_a, int param_b, int *reg, int *carry);
void			zjmp(short jump, int *pc, int carry);

#endif
