/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:35:27 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/06 17:56:10 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		test_arg_direct(char *arg, t_asm *e, int v)
{
	int i;
	int res;
	int lab;
	int val;
	int n;

	i = -1;
	n = 0;
	val = 0;
	res = T_DIR;
	if (ft_strlen(arg) < 2 || arg[0] != DIRECT_CHAR)
		return (0);
	lab = test_arg_label(++arg, e);
	lab != -1 && e->test ? e->u.value[v] = e->l[lab].num - e->num : 0;
	lab == -1 && arg[0] == '-' ? n = 1 : 0;
	while (lab == -1 && arg[++i])
	{
		(i || !n) && (arg[i] > '9' || arg[i] < '0') ? res = 0 :
			(val *= 10);
		i && n ? val -= arg[i] - '0' : 0;
		!n ? val += arg[i] - '0' : 0;
	}
	res && lab == -1 ? e->u.value[v] = val : 0;
	return (res);
}

int		test_arg_index(char *arg, t_asm *e, int v)
{
	int i;
	int res;
	int lab;
	int val;
	int n;

	i = -1;
	n = 0;
	val = 0;
	res = T_IND;
	lab = test_arg_label(arg, e);
	lab != -1 && e->test ? e->u.value[v] = e->l[lab].num - e->num : 0;
	lab == -1 && arg[0] == '-' ? n = 1 : 0;
	while (res && lab == -1 && arg[++i])
	{
		(i || !n) && (arg[i] > '9' || arg[i] < '0') ? res = 0 :
			(val *= 10);
		i && n ? val -= arg[i] - '0' : 0;
		!n ? val += arg[i] - '0' : 0;
	}
	res && lab == -1 ? e->u.value[v] = val : 0;
	return (res);
}

int		test_arg_registre(char *arg, t_asm *e, int v)
{
	int i;
	int r;
	int res;

	i = 0;
	r = 0;
	res = T_REG;
	ft_strlen(arg) < 2 || ft_strlen(arg) > 3 || arg[0] != 'r' ? res = 0 : 0;
	while (res && arg[++i])
	{
		arg[i] > '9' || arg[i] < '0' ? res = 0 : 0;
		r = r * 10 + arg[i] - '0';
	}
	res ? e->u.value[v] = r : 0;
	return (res);
}

void	test_one_arg(char *arg, int type, t_asm *e, int v)
{
	int		t_arg;

	t_arg = 0;
	t_arg += test_arg_index(arg, e, v);
	t_arg += test_arg_registre(arg, e, v);
	t_arg += test_arg_direct(arg, e, v);
	!(t_arg & type) ? ft_exit(9) : 0;
	e->u.t_arg[v] = t_arg;
	//e->test == 2 ? ft_printf("<%7-s type:%d>\nvalue: %d\n", e->u.p[v], t_arg, e->u.value[v]) : 0;
}

void	test_arg(t_asm *e)
{
	//e->test == 2 ? ft_printf("{yellow}%s{none}  %d\n", e->u.name, e->num) : 0;
	test_one_arg(e->u.p[0], op_tab[e->u.i].arg[0], e, 0);
	e->u.nb_param >= 2 ?
		test_one_arg(e->u.p[1], op_tab[e->u.i].arg[1], e, 1) : 0;
	e->u.nb_param >= 3 ?
		test_one_arg(e->u.p[2], op_tab[e->u.i].arg[2], e, 2) : 0;
	e->num += calcul_taille(e);
}
