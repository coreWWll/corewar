/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:40:49 by arepnovs          #+#    #+#             */
/*   Updated: 2017/06/24 14:41:09 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		if_comment(char *line)
{
	int i;

	i = 0;
	if (line[0] == '\0')
		return (1);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == COMMENT_CHAR)
	{
		if (line[i] == COMMENT_CHAR)
			return (1);
		i++;
	}
	return ((line[i] == '\0') ? 1 : 0);
}

void	check_endl_and_len(char *t, char *name, int flag)
{
	if (t != '\0')
		t++;
	while (*t != '\0')
	{
		if (*t == COMMENT_CHAR)
			break ;
		if (*t != ' ' && *t != '\t')
			ft_exit(0);
		t++;
	}
	if ((flag == 1 && ft_strlen(name) > PROG_NAME_LENGTH)
			|| (flag == 0 && ft_strlen(name) > COMMENT_LENGTH))
		ft_exit(1);
}

void	check_format(char *file)
{
	size_t len;

	len = ft_strlen(file);
	if (file[len - 1] != 's' && file[len - 2] != '.')
		ft_exit(3);
}

int		is_label(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != LABEL_CHAR)
		i++;
	if (line[i - 1] == DIRECT_CHAR || line[i] == '\0')
		return (0);
	return (1);
}

char	*if_comment_at_end(char *line)
{
	char *t;

	t = ft_strchr(line, COMMENT_CHAR);
	if (t)
	{
		*t = '\0';
		t = ft_strdup(line);
		return (t);
	}
	return (line);
}
