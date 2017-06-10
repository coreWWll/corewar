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

char    *get_full_name_or_comment(int fd, char *name, char *line, int flag)
{
    size_t len;
    char *t;
    int i;

    i = 0;

    if (flag == 1 && ft_strstr(line, ".comment"))
        ft_exit(0);
    else if (flag == 0 && ft_strchr(line, ','))
        ft_exit(0);
    else
    {
        while(line[i] != '\"' && line[i] != '\0')
        {
            t = name;
            name = ft_charjoin(t, line[i]);
            ft_strdel(&t);
            i++;
        }
        len = ft_strlen(line);
        if (line[len - 1] != '\"')
        {
            get_next_line(fd, &line);
            t = name;
            name = get_full_name_or_comment(fd,t, line, flag); //leaks here!!!!!!!!!!!!!!
            //ft_strdel(&t);
        }
    }
    return(name);
}

char	*get_name_or_comm(char *line, int fd, int flag)
{
	char	*t;
    char    *p;
	char	*name;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
    p = line;
    line = if_comment_at_end(p);//leaks !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    line = good_strtrim(line);//leaks!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (!(t = ft_strchr(line, '\"')))
		ft_exit(0);
	t++;
	while (t[len] != '\"' && t[len] != '\0')
		len++;
	name = ft_strnew(len);
	while (i < len)
	{
		name[i] = *t;
		t++;
		i++;
	}
    if (*t != '\"')
    {
        get_next_line(fd, &line);
        p = name;
        name = get_full_name_or_comment(fd, p, line, flag);
        //ft_strdel(&p);;
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
