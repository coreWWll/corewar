/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:11:49 by arepnovs          #+#    #+#             */
/*   Updated: 2017/06/07 14:12:02 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../op.h"

char	*get_name_or_comm(char *line, int flag)
{
	char	*t;
	char	*name;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (!(t = ft_strchr(line, '\"')))
		ft_exit(0);
	t++;
	while (t[len] != '\"' && t[len] != '\0')
		len++;
	if (t[len] != '\"')
		ft_exit(0);
	name = ft_strnew(len);
	while (i < len)
	{
		name[i] = *t;
		t++;
		i++;
	}
	check_endl_and_len(t, name, flag);
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
