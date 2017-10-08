/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:10:14 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/06 17:25:31 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../ft_printf/ft_printf.h"
# include "../../op/op.h"
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>

typedef struct	s_player
{
	int				number;
	unsigned char	prog[CHAMP_MAX_SIZE];
	t_header		header;
	int				last_live;
	int				nb_live;
}				t_player;

typedef struct	s_instruction
{
	int				opcode;
	int				id;
	int				ocp;
	t_arg_type		param_types[3];
	int				params[3];
}				t_instruction;

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
}				t_proc;

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

void			parse(int argc, char **argv, t_vm *vm);
void			load_player(t_player *p, const char *name);

int				swap_int(int n);
unsigned int	swap_uint(unsigned int n);
short			swap_short(short n);

short			two_octets_to_short(char ram[MEM_SIZE], int pc);
int				four_octets_to_int(char ram[MEM_SIZE], int pc);

/*
** Instructions
*/

void			direct_load(t_vm *vm, t_proc *proc, t_instruction *inst);
void			long_direct_load(t_vm *vm, t_proc *proc, t_instruction *inst);
void			direct_store(t_vm *vm, t_proc *proc, t_instruction *inst);
void			long_direct_store(t_vm *vm, t_proc *proc, t_instruction *inst);
void			live(t_vm *vm, t_proc *proc, t_instruction *inst);
void			add(t_proc *proc, t_instruction *inst);
void			sub(t_proc *proc, t_instruction *inst);
void			cor_and(t_vm *vm, t_proc *proc, t_instruction *inst);
void			cor_or(t_vm *vm, t_proc *proc, t_instruction *inst);
void			cor_xor(t_vm *vm, t_proc *proc, t_instruction *inst);
void			zjmp(short jump, int *pc, int carry);

void			(*g_op_functions[16])(t_vm*, t_proc*, t_instruction*);

#endif
