/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 first_check.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: arepnovs <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/06/07 14:08:27 by arepnovs		   #+#	  #+#			  */
/*	 Updated: 2017/06/07 14:08:27 by arepnovs		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../op.h"

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
    t++;
	while (*t != '\0')
	{
		if (*t != ' ' && *t != '\t')
			ft_exit(0);
		t++;
	}
	if ((flag == 1 && ft_strlen(name) > PROG_NAME_LENGTH) //checking of name and comment size
		|| (flag == 0 && ft_strlen(name) > COMMENT_LENGTH))
		ft_exit(1);
}

void	check_format(char *file)
{
	size_t len;

	len = ft_strlen(file);
	if (file[len - 1] != 's' && file[len - 2] != '.')//checking file format by last 2 chars
		ft_exit(3);
}

int		is_label(char *line) //check if label is in line
{
	int i;

	i = 0;
	while (line[i] && line[i] != LABEL_CHAR)
		i++;
	if (line[i - 1] == DIRECT_CHAR || line[i] == '\0')
		return (0);
	return (1);
}

char	*if_comment_at_end(char *line) //check if comment is after command line
{
	char *t;

	t = ft_strchr(line, COMMENT_CHAR);
	if (!t)
		t = ft_strchr(line, ';');
	if (t)
	{
		*t = '\0';
		t = line;
		line = ft_strdup(t);//leaks here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//ft_strdel(&t);
	}
	return(line);
    //ft_strdel(&t);
}
