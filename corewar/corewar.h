/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:10:14 by gdelabro          #+#    #+#             */
/*   Updated: 2017/09/26 20:31:32 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include "../ft_printf/ft_printf.h"
#include "../op/op.h"
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

typedef struct		s_vm
{
	int				nb_champ;
	char			ram[MEM_SIZE];
}					t_vm;

typedef struct		s_instruction
{
	int				name;
	int				ocp;
	int				p1;
	int				p2;
	int				p3;
}					t_instruction

typedef struct		s_proc
{
	int				r[REG_NUMBER];
	int				pc;
	int				carry;
	int				id;
	int				nb_c;
	int				last_l;
	t_instruction	inst;
}					t_proc;

#endif
