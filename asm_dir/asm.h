/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:40:23 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/09 18:55:44 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../ft_printf/ft_printf.h"
# include "../op/op.h"
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>

typedef struct		s_lab
{
	char			*label;
	int				num;
	int				l;
	int				i;
}					t_lab;

typedef struct		s_instruction
{
	char			*name;
	char			*p[3];
	int				t_p[3];
	int				t_arg[3];
	int				value[3];
	int				t_n;
	int				nb_param;
	int				i;
}					t_instruction;

typedef struct		s_asm
{
	int				fd;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	char			content[CHAMP_MAX_SIZE + 10];
	char			*file;
	char			*file_name;
	char			*new_file;
	char			**split;
	int				nb_lab;
	int				num;
	int				i;
	int				test;
	int				i2;
	t_lab			*l;
	t_instruction	u;
	int				nb_instruction;
}					t_asm;

void				ft_exit(int err);
int					is_space(char c);
void				pars_info(t_asm *e);
void				split_file(t_asm *e, int i2);
void				aff_struct(t_asm *e);
int					test_arg_label(char *arg, t_asm *e);
void				write_arg(t_asm *e);
void				fill_label(t_asm *e);
void				test_instruction(char *line, t_asm *e);
void				test_arg(t_asm *e);
void				free_struct(t_asm *e);
int					calcul_taille(t_asm *e);
void				write_file(t_asm *e);
unsigned int		swap_uint(unsigned int n);
int					swap_int(int n);
short				swap_short(short n);

#endif
