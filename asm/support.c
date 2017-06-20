/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:13:16 by arepnovs          #+#    #+#             */
/*   Updated: 2017/06/07 14:13:25 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../op.h"

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
			|| str[j] == COMMENT_CHAR/* || str[j] == ';'*/)
		j--;
	len = j - i;
	res = ft_strsub(str, i, len + 1);
	//free(str);
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
			minus++;
		if (ft_isdigit(str[i]) != 1 && minus > 1)
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
    i++;
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
		ft_putendl("Wrong format of file");
	if (flag == 5)
		ft_putendl("No command or wrong command");
	if (flag == 6)
		ft_putendl("Wrong label");
	if (flag == 7)
		ft_putendl("Wrong label syntax");
    if (flag == 8)
        ft_putendl("Syntax error - unexpected end of input (Perhaps you forgot to end with a newline?)");
    if (flag == 9)
        ft_putendl("No name or initial comment");
	exit(0);
}
