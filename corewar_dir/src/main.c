/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:59:59 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/11 17:10:21 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_vm	vm;

	parse(argc, argv, &vm);
	init_vm(&vm);
	display_ram(&vm);
	handle_main_loop(&vm);
	return (0);
}
