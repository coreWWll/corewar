/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:25:27 by arepnovs          #+#    #+#             */
/*   Updated: 2017/03/01 18:55:44 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*new_gnl(int fd)
{
	t_gnl	*new;

	new = (t_gnl*)malloc(sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->str = ft_strnew(0);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

static char		*ft_read(int fd, char *tail, int *ret)
{
	char	buf[BUFF_SIZE + 1];
	char	*buf2;

	ft_bzero(buf, BUFF_SIZE + 1);
	*ret = read(fd, buf, BUFF_SIZE);
	buf[*ret] = '\0';
	buf2 = ft_strjoin(tail, buf);
	ft_strdel(&tail);
	return (buf2);
}

static int		get_line(char **tail, char **line, int fd)
{
	int		ret;
	char	*gline;

	ret = 1;
	while (ret > 0)
	{
		*tail = ft_read(fd, *tail, &ret);
		if ((gline = ft_strchr(*tail, '\n')) != NULL)
		{
			*gline = '\0';
			*line = ft_strdup(*tail);
			ft_memmove(*tail, gline + 1, ft_strlen(gline + 1) + 1);
			return (1);
		}
		else if (ft_strlen(*tail) && ret == 0)
		{
			*line = ft_strdup(*tail);
			ft_bzero(*tail, ft_strlen(*tail));
			return (1);
		}
		else if (!ft_strlen(*tail) && ret == 0)
			*line = ft_strnew(0);
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*s;
	t_gnl			*tail;

	if (fd < 0 || BUFF_SIZE <= 0 || BUFF_SIZE > 65534 || !line)
		return (-1);
	if (!s)
		s = new_gnl(fd);
	tail = s;
	while (tail)
	{
		if (tail->fd == fd)
			break ;
		if (tail->next == NULL && tail->fd != fd)
		{
			tail->next = new_gnl(fd);
			tail = tail->next;
			break ;
		}
		tail = tail->next;
	}
	return (get_line(&tail->str, line, fd));
}
