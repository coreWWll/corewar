/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_and_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:02:52 by arepnovs          #+#    #+#             */
/*   Updated: 2017/06/26 16:03:13 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_name_comment_till_end(char **line, char **name, int fd)
{
	char	*t;
	int		check;

	check = 9;
	if (!ft_strchr(*line, '\"'))
	{
		t = ft_strjoin(*name, *line);
		*name = ft_strdup(t);
		free(t);
	}
	while (!ft_strchr(*line, '\"') && (check = get_next_line(fd, line)) > 0)
	{
		if (!ft_strchr(*line, '\"'))
		{
			t = ft_strjoin(*name, *line);
			free(*name);
			*name = ft_strdup(t);
			free(t);
		}
		free(*line);
	}
	if (check <= 0)
		ft_exit(0);
}

void	make_name_comm_complete(char **line, char **name)
{
	char	*p;
	char	*t;
	int		i;

	i = 0;
	p = ft_strdup(*line);
	while (p[i] != '\"')
	{
		t = *name;
		*name = ft_charjoin(t, p[i]);
		free(t);
		i++;
	}
	free(p);
}

char	*get_full_name_or_comment(int fd, char *name, char *line, int flag)
{
	char *t;

	if (flag == 1 && ft_strstr(line, ".comment"))
		ft_exit(0);
	else if (flag == 0 && ft_strchr(line, ','))
		ft_exit(0);
	else
	{
		get_name_comment_till_end(&line, &name, fd);
		if (ft_strchr(line, '\"'))
		{
			make_name_comm_complete(&line, &name);
			t = line;
			while (*t != '\"' && *t != '\0')
				t++;
			check_endl_and_len(t, name, flag);
		}
	}
	return (name);
}

void	check_if_name_comment_is_correct(char *line, int flag)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (line[i] != '.')
		(line[i] != ' ' && line[i] != '\t') ? ft_exit(9) : i++;
	tmp = (flag == 0) ? COMMENT_CMD_STRING : NAME_CMD_STRING;
	if (line[i] == '.')
	{
		while (tmp[j])
		{
			if (line[i] != tmp[j])
				ft_exit(9);
			i++;
			j++;
		}
	}
	else
		ft_exit(9);
	while (line[i] != '\"')
		(line[i] != ' ' && line[i] != '\t') ? ft_exit(9) : i++;
}

char	*start_getting_name(char **name, char *t, size_t len)
{
	char	*temp;
	size_t	i;

	i = 0;
	*name = ft_strnew(len);
	temp = *name;
	while (i < len)
	{
		temp[i] = *t;
		t++;
		i++;
	}
	return (t);
}
