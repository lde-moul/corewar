/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:40:23 by gdelabro          #+#    #+#             */
/*   Updated: 2017/09/27 19:39:09 by gdelabro         ###   ########.fr       */
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

typedef struct		s_asm
{
	int				fd;
	char			name[PROG_NAME_LENGTH];
	int				name_enter;
	char			comment[COMMENT_LENGTH];
	int				com_enter;
	char			*file;
	char			*file_name;
	char			**split;
	int				i;
	int				i2;
}					t_asm;

void				ft_exit(int err);

#endif
