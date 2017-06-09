/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:18:03 by arepnovs          #+#    #+#             */
/*   Updated: 2017/06/07 14:18:21 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../op.h"

void	check_if_label_ok(char *line, int len)
{
	char *t;
	char *p;

	p = line + len + 1;
	if ((t = ft_strchr(p, LABEL_CHAR)))
	{
		t--;
		if (*t != DIRECT_CHAR)
			ft_exit(7);
	}
}

void	check_label_syntax(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(LABEL_CHARS, line[i]))
			ft_exit(7);
		i++;
	}
}

void	find_label_or_die(t_asm *start, char *label)
{
	t_asm	*p;
	int		i;

	i = 0;
	p = start;
	while (p)
	{
		if (p->label)
		{
			if (ft_strcmp(p->label, label) == 0)
			{
				i = 1;
				break ;
			}
		}
		p = p->next;
	}
	if (i != 1)
		ft_exit(6);
}
