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

#include "../op.h"

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

void	get_command(char *line, t_asm *start)
{
	int		i;
	size_t	j;
	char	*t;

	i = 16;
	while (--i >= 0) //sometimes works when 2 or more commands in line
	{
		if ((t = ft_strstr(line, op_tab[i].command)) != 0)
		{
			j = ft_strlen(op_tab[i].command);
			t = t + j;
			if (*t == ' ' || *t == '\t' || *t == DIRECT_CHAR)
			{
				start->command = ft_strdup(op_tab[i].command);
				start->comm_num = i;
				start->opcode = op_tab[i].opcode;
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
	char *dupline;
	char *p;
	int comm;

	comm = 0;
	if (start->only_label == 1 && is_label(line) == 1)//if list with only label
	{
		start->next = new_asm();
		start->only_label = 0;
		start = start->next;
	}
	if (ft_strchr(line, '#'))
	{
		line = if_comment_at_end(line);//maybe the reason of leaks!!!!!!!!!
		comm = 1;
	}
	line = good_strtrim(line);//leaks!!!!!!!!!!
	dupline = line;
	get_label(&dupline, start);
	get_command(dupline, start);
	get_args(dupline, start);
	ft_strdel(&line);
	//line = NULL;
}
