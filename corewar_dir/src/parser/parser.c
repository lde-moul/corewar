/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:56:21 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/02 17:40:04 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	parse_dump(int argc, char **argv, int *i, t_vm *vm)
{
	(*i)++;
	if (*i == argc)
	{
		ft_printf("Missing argument after -dump");
		exit(1);
	}
	// !!! Check number validity?
	vm->dump_cycles = ft_atoi(argv[*i]);
}

static void	parse_options(int argc, char **argv, int *i, t_vm *vm)
{
	vm->dump_cycles = -1;
	*i = 1;
	while (*i < argc)
	{
		if (!ft_strcmp(argv[*i], "-dump"))
			parse_dump(argc, argv, i, vm);
		else
			return ;
		(*i)++;
	}
}

static void	parse_players(int argc, char **argv, int *i, t_vm *vm)
{
	vm->num_players = 0;
	while (*i < argc)
	{
		// if (!ft_strcmp(argv[*i], "-n"))
		// 	return (0);
		// !!! Check if too many players
		vm->players[vm->num_players].number = vm->num_players - 1; // !!!
		load_player(&vm->players[vm->num_players], argv[*i]);
		vm->num_players++;
		i++;
	}
}

void		parse(int argc, char **argv, t_vm *vm)
{
	int	i;

	if (argc == 1)
	{
		ft_printf("Usage: ./corewar [-dump nbr_cycles] "
					"[[-n number] champion1.cor] ...");
		exit(1);
	}
	parse_options(argc, argv, &i, vm);
	parse_players(argc, argv, &i, vm);
}
