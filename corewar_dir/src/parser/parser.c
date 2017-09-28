/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:56:21 by lde-moul          #+#    #+#             */
/*   Updated: 2017/09/28 14:59:48 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	parse_dump(int argc, char **argv, int *i, t_vm *vm)
{
	(*i)++;
	if (*i == argc)
	{
		ft_putendl_fd("Missing argument after -dump", 2);
		return (0);
	}
	// !!! Check number validity?
	vm->dump_cycles = ft_atoi(argv[*i]);
	return (1);
}

int			parse_options(int argc, char **argv, int *i, t_vm *vm)
{
	*i = 1;
	while (*i < argc)
	{
		if (!ft_strcmp(argv[*i], "-dump"))
		{
			if (!parse_dump(argc, argv, i, vm))
				return (0);
		}
		else
			return (1);
		(*i)++;
	}
	return (1);
}

int			parse_players(int argc, char **argv, int *i, t_vm *vm)
{
	while (*i < argc)
	{
		// if (!ft_strcmp(argv[*i], "-n"))
		// 	return (0);
		load_player(&vm->players[vm->num_players], argv[*i]);
		vm->num_players++;
		i++;
	}
	return (1);
}

int			parse(int argc, char **argv, t_vm *vm)
{
	int	i;

	if (argc == 1)
	{
		ft_putendl("Usage: ./corewar [-dump nbr_cycles] "
					"[[-n number] champion1.cor] ...");
		return (0);
	}
	parse_options(argc, argv, &i, vm);
	parse_players(argc, argv, &i, vm);
	return (1);
}
