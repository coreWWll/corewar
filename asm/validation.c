/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:18:36 by arepnovs          #+#    #+#             */
/*   Updated: 2017/06/07 14:19:30 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../op.h"

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
		if (op_tab[p->comm_num].args[i] != T_REG && op_tab[p->comm_num].args[i] != T_REG + T_IND
            && op_tab[p->comm_num].args[i] != T_REG + T_DIR)
			ft_exit(2);
	}
	else if (p->what_args[i] == T_IND)
	{
		if (op_tab[p->comm_num].args[i] != T_IND && op_tab[p->comm_num].args[i] != T_IND + T_REG
            && op_tab[p->comm_num].args[i] != T_IND + T_DIR)
			ft_exit(2);
	}
	else if (p->what_args[i] == T_DIR)
	{
		if (op_tab[p->comm_num].args[i] != T_DIR && op_tab[p->comm_num].args[i] != T_DIR + T_REG
            && op_tab[p->comm_num].args[i] != T_DIR + T_IND)
			ft_exit(2);
	}
}

void	check_args(t_asm *p)
{
	int i;

	i = 0;
	while (i < op_tab[p->comm_num].args_am || (p->comm_num == 0 && i == 0))
	{
		if (op_tab[p->comm_num].args[i] != 7)
			check_args_type(p, i);
		i++;
	}
}

void	check_args_now(t_asm *start)
{
	t_asm *p;

	p = start;
	while (p)
	{
		if (p->command && p->command[0] != '\0')
		{
			if (p->amount_of_args != op_tab[p->comm_num].args_am)
				ft_exit(2);
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
