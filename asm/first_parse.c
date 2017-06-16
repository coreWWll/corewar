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

/*char    *get_full_name_or_comment(int fd, char *name, char *line, int flag)
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
        t = if_comment_at_end(line);//leaks !!!!!!!!!!!!!!!!!!!!!!!!!!!!
        ft_strdel(&line);
        line = good_strtrim(t);
        if (ft_strcmp(line, t) != 0)
            ft_strdel(&t);
        while(line[i] != '\"' && line[i] != '\0')
        {
            t = ft_charjoin(name, line[i]);
            ft_strdel(&name);
            name = ft_strdup(t);
            ft_strdel(&t);
            i++;
        }
        len = ft_strlen(line);
        if (!ft_strchr(line, '\"'))
        {
           ft_strdel(&line);
            get_next_line(fd, &line);
            t = get_full_name_or_comment(fd, name, line, flag); //leaks here!!!!!!!!!!!!!!
            //ft_strdel(&name);
            name = t;
        }
        /*else
            ft_strdel(&line);
    }
    return(name);
}*/

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
        while (!ft_strchr(line, '\"') && ft_strlen(name) <= COMMENT_LENGTH)
        {
            //ft_strdel(&line);
            get_next_line(fd, &line);
            if (!ft_strchr(line, '\"'))
            {
                t = ft_strjoin(name, line);
                //ft_strdel(&name);
                name = ft_strdup(t);
                //ft_strdel(&t);
            }
        }
        if (ft_strchr(line, '\"'))
        {
            t = if_comment_at_end(line);
            //ft_strdel(&line);
            line = good_strtrim(t);
            while(line[i] != '\"' && line[i] != '\0')
            {
                t = ft_charjoin(name, line[i]);
                //ft_strdel(&name);
                name = ft_strdup(t);
                //ft_strdel(&t);
                i++;
            }
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
    //p = line;
    /*if (ft_strchr(line, '#') || ft_strchr(line, ';'))
    {
        p = if_comment_at_end(line);
        line = ft_strdup(p);
        ft_strdel(&p);
        line = good_strtrim(line);
    }*/
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
        //ft_strdel(&line);
        get_next_line(fd, &line);
        //p = name;
        name = get_full_name_or_comment(fd, name, line, flag);
        //ft_strdel(&name);
        //name = p;
    }
    t = name;
    while (*t != '\"' && *t != '\0')
        t++;
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
