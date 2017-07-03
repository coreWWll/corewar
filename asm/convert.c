/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 15:42:46 by arepnovs          #+#    #+#             */
/*   Updated: 2017/07/03 15:44:48 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_if_comand(char *command)
{
	int i;

	i = 0;
	if (!command)
		return (MAX_INT);
	while (i < 16)
	{
		if (ft_strcmp(command, op_tab[i].command) == 0)
			return (i + 1);
		i++;
	}
	return (MAX_INT);
}

void	get_commands(t_asm *head, int fd)
{
	t_asm	*begin;
	int		op_c;

	begin = head;
	while (begin)
	{
		if ((op_c = check_if_comand(begin->command)) != MAX_INT)
			write_op_code(head, begin, op_c, fd);
		begin = begin->next;
	}
}

void	to_byte_code(t_asm *head)
{
	t_asm	*begin;
	char	*file_name;
	int		fd;

	file_name = ft_strjoin(head->file_path, ".cor");
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	begin = head;
	head->header = (header_t *)malloc(sizeof(header_t));
	header_parse(head);
	write(fd, &(*head->header), sizeof(header_t));
	get_commands(head, fd);
	ft_strdel(&file_name);
}
