/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:14:23 by arepnovs          #+#    #+#             */
/*   Updated: 2017/06/26 19:54:54 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	put_args_types(t_asm *start, int i)
{
	char *temp;

	if (start->args[i][0] == DIRECT_CHAR || start->args[i][0] == LABEL_CHAR)
	{
		start->what_args[i] = T_DIR;
		if (start->args[i][1] == LABEL_CHAR || start->args[i][0] == LABEL_CHAR)
		{
			temp = start->args[i];
			start->args[i] = (start->args[i][0] == DIRECT_CHAR)
                             ? ft_strsub(temp, 2, ft_strlen(temp) - 2) : ft_strsub(temp, 1, ft_strlen(temp) - 1);
			free(temp);
			start->l_flag[i] = 1;
		}
		else
			check_if_num_ok(start->args[i], 1);
	}
	else if (start->args[i][0] == 'r'
			&& check_if_num_ok(start->args[i], 0) == 1)
		start->what_args[i] = T_REG;
	else if (is_num(start->args[i]) == 1)
		start->what_args[i] = T_IND;
	else
		ft_exit(2);
}

void	if_one_arg(t_asm *start, char *dupline, size_t i)
{
	size_t	j;
	char	*temp;

	j = 0;
	start->amount_of_args++;
	while (dupline[i + j] != COMMENT_CHAR && dupline[i + j] != '\0')
		j++;
	start->args = (char **)malloc(sizeof(char *));
	start->args[0] = ft_strsub(dupline, (unsigned int)i, j);
	temp = ft_strdup(start->args[0]);
	ft_strdel(&start->args[0]);
	start->args[0] = clean_arg(temp);
	free(temp);
	put_args_types(start, 0);
}

void	if_more_args(t_asm *start)
{
	int		i;
	char	*temp;

	i = 0;
	while (start->args && start->args[i] != NULL)
	{
		temp = start->args[i];
		start->args[i] = good_strtrim(temp);
		free(temp);
		if (ft_strchr(start->args[i], ' ') || ft_strchr(start->args[i], '\t'))
		{
			temp = start->args[i];
			start->args[i] = clean_arg(temp);
			free(temp);
		}
		start->amount_of_args++;
		put_args_types(start, i);
		i++;
	}
}

void	how_to_get_args(t_asm *start, char *dupline, size_t i)
{
	size_t	j;
	char	*args;

	if (start->comm_num != -1 && op_tab[start->comm_num].args_am == 1)
		if_one_arg(start, dupline, i);
	else
	{
		j = ft_strlen(dupline);
		while (dupline[i] == ' ' || dupline[i] == '\t')
			i++;
		args = ft_strsub(dupline, (unsigned int)i, j);
		if (args[0] != '\0')
			start->args = ft_strsplit(args, SEPARATOR_CHAR);
		ft_strdel(&args);
		if_more_args(start);
	}
}

void	get_args(char *line, t_asm *start)
{
	size_t	i;
	char	dupline[100];

	i = 0;
	ft_strcpy(dupline, line);
	while (dupline[i] != DIRECT_CHAR && dupline[i] != ' '
			&& dupline[i] != '\t' && dupline[i] != '\0')
		i++;
	if (dupline[i] == '\0' && start->label == NULL)
		ft_exit(2);
	start->opcode = op_tab[start->comm_num].opcode;
	how_to_get_args(start, dupline, i);
	if (start->command && !start->args[0])
		ft_exit(2);
}
