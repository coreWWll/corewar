/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:19:46 by arepnovs          #+#    #+#             */
/*   Updated: 2017/06/07 14:26:15 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op	*init_tab(void)
{
	static t_op g_op_tab[16] = {{"live", 1, {T_DIR}, 1},
	{"add", 3, {T_REG, T_REG, T_REG}, 4},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8},
	{"zjmp", 1, {T_DIR}, 9},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10},
	{"st", 2, {T_REG, T_IND | T_REG}, 3},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14},
	{"fork", 1, {T_DIR}, 12},
	{"lfork", 1, {T_DIR}, 15},
	{"aff", 1, {T_REG}, 16},
	};

	return (g_op_tab);
}

t_asm	*new_asm(void)
{
	t_asm *new;

	new = (t_asm *)malloc(sizeof(t_asm));
	new->file_name = NULL;
	new->name = NULL;
	new->comm = NULL;
	new->label = NULL;
	new->command = NULL;
	new->args = NULL;
	new->l_flag[0] = 0;
	new->l_flag[1] = 0;
	new->l_flag[2] = 0;
	new->what_args[0] = 0;
	new->what_args[1] = 0;
	new->what_args[2] = 0;
	new->amount_of_args = 0;
	new->comm_num = -1;
	new->only_label = 0;
	new->opcode = 0;
	new->label_size = 0;
	new->next = NULL;
	return (new);
}

void	get_label(char **line, t_asm *start)
{
	int		len;
	char	dupline[1000];

	len = 0;
	if (start->label == NULL)
	{
		ft_strcpy(dupline, *line);
		if (ft_strchr(dupline, LABEL_CHAR) != NULL)
		{
			while (dupline[len] != LABEL_CHAR && dupline[len] != '\0')
				len++;
		}
		check_if_label_ok(*line, len);
		if ((dupline[len] == '\0' || dupline[len - 1] == DIRECT_CHAR)
			&& start->only_label != 1)//check if label is in line
			start->label = start->label;
		else if (start->only_label != 1 && len != 0)
		{
			dupline[len] = '\0';
			start->label = ft_strnew(0);
			ft_strcpy(start->label, dupline);
			check_label_syntax(start->label);
			*line = *line + len + 1;
		}
	}
}

void	get_command(char *line, t_op *g_tab, t_asm *start)
{
	int		i;
	size_t	j;
	char	*t;

	i = 16;
	while (--i >= 0) //sometimes works when 2 or more commands in line
	{
		if ((t = ft_strstr(line, g_tab[i].command)) != 0)
		{
			j = ft_strlen(g_tab[i].command);
			t = t + j;
			if (*t == ' ' || *t == '\t' || *t == DIRECT_CHAR)
			{
				start->command = ft_strdup(g_tab[i].command);
				start->comm_num = i;
				start->opcode = g_tab[i].opcode;
				break ;
			}
		}
	}
	if (start->label && !ft_strchr(line, DIRECT_CHAR)
			&& !ft_strchr(line, SEPARATOR_CHAR))
		start->only_label = 1;
	if (!start->label && !start->command)
		ft_exit(5);
}

void	get_all_info(t_asm *start, char *line)
{
	t_op *g_tab;
	char *dupline;

	if (start->only_label == 1 && is_label(line) == 1)//if list with only label
	{
		start->next = new_asm();
		start->only_label = 0;
		start = start->next;
	}
	if_comment_at_end(&line);
	line = good_strtrim(line);
	dupline = line;
	g_tab = init_tab();
	get_label(&dupline, start);
	get_command(dupline, g_tab, start);
	get_args(dupline, start, g_tab);
	ft_strdel(&line);
}
