/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:40:23 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/02 19:31:40 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "../ft_printf/ft_printf.h"
#include "../op/op.h"
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

typedef struct		s_lab
{
	char			*label;
	int				num;
}					t_lab;

typedef struct		s_instruction
{
	char			*name;
	char			*p[3];
	int				t_p[3];
	int				t_n;
	int				nb_param;
}					t_instruction;

typedef struct		s_asm
{
	int				fd;
	char			name[PROG_NAME_LENGTH];
	char			comment[COMMENT_LENGTH];
	char			*file;
	char			*file_name;
	char			**split;
	int				nb_lab;
	int				num;
	int				i;
	int				i2;
	t_lab			*l;
	t_instruction	u;
}					t_asm;

void				ft_exit(int err);
int					is_space(char c);
void				pars_info(t_asm *e);
void				split_file(t_asm *e, int i2);
void				aff_struct(t_asm *e);
void				fill_label(t_asm *e);
void				test_instruction(char *line, t_asm *e);

#endif
