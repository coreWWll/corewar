/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 16:00:28 by arepnovs          #+#    #+#             */
/*   Updated: 2017/06/24 16:03:39 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../op.h"

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
			check_endl_and_len(t, name, line, flag);
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

char	*get_name_or_comm(char *line, int fd, int flag)
{
	char	*t;
	char	*p;
	char	*name;
	size_t	len;

	len = 0;
	check_if_name_comment_is_correct(line, flag);
	if (!(t = ft_strchr(line, '\"')))
		ft_exit(0);
	t++;
	while (t[len] != '\"' && t[len] != '\0')
		len++;
	t = start_getting_name(&name, t, len);
	if (*t != '\"')
	{
		get_next_line(fd, &line);
		t = get_full_name_or_comment(fd, name, line, flag);
		free(line);
		free(name);
		name = t;
	}
	else
		check_endl_and_len(t, name, line, flag);
	return (name);
}

char	*get_file_name(char *av)
{
	size_t	len;
	char	*name;
	char	*t;

	name = ft_strnew(0);
	len = ft_strlen(av);
	while (len > 0 && av[len - 1] != '/')
		len--;
	while (av[len] != '.')
	{
		t = name;
		name = ft_charjoin(t, av[len]);
		ft_strdel(&t);
		len++;
	}
	return (name);
}

char	*get_result_output(char *av)
{
	size_t	len;
	int		i;
	char	*name;
	char	*t;

	i = 0;
	name = ft_strnew(0);
	len = ft_strlen(av);
	while (i < len - 2)
	{
		t = name;
		name = ft_charjoin(t, av[i]);
		ft_strdel(&t);
		i++;
	}
	return (name);
}
