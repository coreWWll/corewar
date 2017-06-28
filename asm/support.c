/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:44:19 by arepnovs          #+#    #+#             */
/*   Updated: 2017/06/26 15:56:05 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	mult_putstr(char *str, char *str1, char *str2)
{
	ft_putstr(str);
	ft_putstr(str1);
	ft_putstr(str2);
}

char	*good_strtrim(char *str)
{
	unsigned int	i;
	size_t			j;
	size_t			len;
	char			*res;

	i = 0;
	len = ft_strlen(str) - 1;
	j = len;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[j] == ' ' || str[j] == '\t'
			|| str[j] == COMMENT_CHAR)
		j--;
	len = j - i;
	res = ft_strsub(str, i, len + 1);
	return (res);
}

int		is_num(char *str)
{
	int i;
	int minus;

	i = 0;
	minus = 0;
	while (str[i])
	{
		if (str[i] == '-')
        {
            i++;
            minus++;
        }
		if (ft_isdigit(str[i]) != 1 || minus > 1)
			return (0);
		i++;
	}
	return (1);
}

char	*clean_arg(char *line)
{
	size_t	i;
	size_t	len;
	char	*res;

	len = ft_strlen(line);
	i = len;
	while (line[i] != '\t' && line[i] != ' ')
		i--;
	i = (i > MAX_INT) ? 0 : i + 1;
	res = ft_strsub(line, (unsigned int)i, len - i);
	return (res);
}

void	ft_exit(int flag)
{
	if (flag == 0)
		ft_putendl("Wrong name or comment format");
	if (flag == 1)
		ft_putendl("Size of name or comment is too big");
	if (flag == 2)
		ft_putendl("Wrong argument");
	if (flag == 3)
		ft_putendl("Wrong file format");
	if (flag == 5)
		ft_putendl("No command or wrong command");
	if (flag == 6)
		ft_putendl("Wrong label");
	if (flag == 7)
		ft_putendl("Wrong label syntax");
	if (flag == 8)
		ft_putendl("Syntax error - unexpected end of input"
				" (Perhaps you forgot to end with a newline?)");
	if (flag == 9)
		ft_putendl("Wrong or no name or initial comment");
	if (flag == 10)
		ft_putendl("Invalid parameter count for instruction");
	exit(0);
}
