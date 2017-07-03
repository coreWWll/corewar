/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 15:23:32 by arepnovs          #+#    #+#             */
/*   Updated: 2017/07/03 15:24:28 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm	*new_asm(void)
{
	t_asm *new;

	new = (t_asm *)malloc(sizeof(t_asm));
	new->file_name = NULL;
	new->file_path = NULL;
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

void	get_label(char **line, t_asm *start, int len)
{
	char	dupline[1000];

	if (start->label == NULL)
	{
		if (ft_strchr(ft_strcpy(dupline, *line), LABEL_CHAR) != NULL)
		{
			while (dupline[len] != LABEL_CHAR && dupline[len] != '\0')
				len++;
		}
		if ((dupline[len] == '\0' || dupline[len - 1] == DIRECT_CHAR)
			&& start->only_label != 1)
			start->label = start->label;
		else if (start->only_label != 1 && len != 0)
		{
			dupline[len] = '\0';
			if (dupline[len - 1] != ' ' && dupline[len - 1] != ','
				&& dupline[len - 1] != '\t')
			{
				start->label = ft_strnew(0);
				check_label_syntax(ft_strcpy(start->label, dupline));
				*line = *line + len + 1;
			}
		}
	}
}

void	get_command(char *line, t_asm *start)
{
	int		i;
	size_t	j;
	char	*t;

	i = 16;
	while (--i >= 0)
	{
		if ((t = ft_strstr(line, g_op_tab[i].command)) != 0)
		{
			j = ft_strlen(g_op_tab[i].command);
			t = t + j;
			if (*t == ' ' || *t == '\t' || *t == DIRECT_CHAR)
			{
				start->command = ft_strdup(g_op_tab[i].command);
				start->comm_num = i;
				start->opcode = g_op_tab[i].opcode;
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
	char	*dupline;
	char	*p;
	int		len;

	len = 0;
	if (start->only_label == 1 && is_label(line) == 1)
	{
		start->next = new_asm();
		start->only_label = 0;
		start = start->next;
	}
	if (ft_strchr(line, COMMENT_CHAR))
	{
		p = if_comment_at_end(line);
		line = p;
		ft_strdel(&p);
	}
	line = good_strtrim(line);
	dupline = line;
	get_label(&dupline, start, len);
	get_command(dupline, start);
	get_args(dupline, start);
	ft_strdel(&line);
}
