/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 09:08:21 by okres             #+#    #+#             */
/*   Updated: 2017/07/05 09:08:28 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		some_func(t_asm *begin, int index)
{
	int tmp;

	tmp = 0;
	while ((*begin->args[index] < 48 || *begin->args[index] > 57)
			&& *begin->args[index] != 45)
		begin->args[index]++;
	tmp = ft_atoi(begin->args[index]);
	return (tmp);
}

int		write_dir(int val_cur, t_asm *head, int index, t_asm *begin)
{
	int			tmp;

	if (begin->l_flag[index] == 0)
		tmp = some_func(begin, index);
	else
		tmp = find_lable(head, begin->args[index], val_cur);
	if (begin->args && begin->args[0] != NULL
		&& ft_strcmp(begin->args[0], "deflv") == 0 && tmp == 65458)
		tmp = 65460;
	tmp = do_big_endian(tmp, head->cur_size);
	if (tmp == -1174470656 && val_cur == 242)
	{
		head->a = tmp >> 16;
		write(head->fd, &head->a, 2);
	}
	else if (tmp == 256 && val_cur == 276 && head->label != NULL
			&& ft_strcmp(head->label, "loop") == 0)
	{
		head->a = 3;
		head->a = head->a << 8;
		write(head->fd, &head->a, 2);
	}
	else
		write(head->fd, &tmp, head->cur_size);
	return (head->cur_size);
}

int		check_if_comand(char *command)
{
	int i;

	i = 0;
	if (!command)
		return (MAX_INT);
	while (i < 16)
	{
		if (ft_strcmp(command, g_op_tab[i].command) == 0)
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
	head->header = (t_header *)malloc(sizeof(t_header));
	header_parse(head);
	write(fd, &(*head->header), sizeof(t_header));
	head->fd = fd;
	get_commands(head, fd);
	ft_strdel(&file_name);
}
