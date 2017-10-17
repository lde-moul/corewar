/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:06:30 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/17 17:06:30 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ocp_to_param_types(t_arg_type param_types[3], unsigned char ocp)
{
	// !!! Check if the ocp is not allowed
	param_types[0] = ocp >> 6;
	param_types[1] = (ocp >> 4) & 3;
	param_types[2] = (ocp >> 2) & 3;
}
