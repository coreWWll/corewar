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

#include "asm.h"

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
