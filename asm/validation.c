/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:18:36 by arepnovs          #+#    #+#             */
/*   Updated: 2017/07/03 14:53:34 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_if_labels(t_asm *start)
{
	t_asm	*p;

	p = start;
	while (p)
	{
		if (p->l_flag[0] == 1)
			find_label_or_die(start, p->args[0]);
		if (p->l_flag[1] == 1)
			find_label_or_die(start, p->args[1]);
		if (p->l_flag[2] == 1)
			find_label_or_die(start, p->args[2]);
		p = p->next;
	}
}

void	check_args_type(t_asm *p, int i)
{
	if (p->what_args[i] == T_REG)
	{
		if (g_op_tab[p->comm_num].args[i] != T_REG &&
				g_op_tab[p->comm_num].args[i] != (T_REG | T_IND)
				&& g_op_tab[p->comm_num].args[i] != (T_REG | T_DIR))
			ft_exit(2);
	}
	else if (p->what_args[i] == T_IND)
	{
		if (g_op_tab[p->comm_num].args[i] != T_IND
				&& g_op_tab[p->comm_num].args[i] != (T_IND | T_REG)
				&& g_op_tab[p->comm_num].args[i] != (T_IND | T_DIR))
			ft_exit(2);
	}
	else if (p->what_args[i] == T_DIR)
	{
		if (g_op_tab[p->comm_num].args[i] != T_DIR
				&& g_op_tab[p->comm_num].args[i] != (T_DIR | T_REG)
				&& g_op_tab[p->comm_num].args[i] != (T_DIR | T_IND))
			ft_exit(2);
	}
}

void	check_args(t_asm *p)
{
	int i;
    int args_sum;

	i = 0;
    args_sum = 0;
	while (i < g_op_tab[p->comm_num].args_am || (p->comm_num == 0 && i == 0))
	{
        args_sum = args_sum + p->what_args[i];
		if (g_op_tab[p->comm_num].args[i] != (T_REG | T_DIR | T_IND))
			check_args_type(p, i);
		i++;
	}
    if (args_sum == 0)
        ft_exit(2);
}

void	check_args_now(t_asm *start)
{
	t_asm *p;

	p = start;
	while (p)
	{
		if (p->command && p->command[0] != '\0')
		{
			if (p->amount_of_args != g_op_tab[p->comm_num].args_am)
				ft_exit(10);
			check_args(p);
		}
		p = p->next;
	}
}

void	validate_it(t_asm *start)
{
	if (!start->name || !start->comm)
		ft_exit(9);
	check_if_labels(start);
	check_args_now(start);
}
