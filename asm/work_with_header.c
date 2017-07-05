/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 09:12:25 by okres             #+#    #+#             */
/*   Updated: 2017/07/05 09:12:27 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int g_size2[] = {4, 4, 0, 0, 0, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4};
int g_codage_octal2[] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1};

int				check_if_comand_is(char *command, int *cur_com_size,
		unsigned int *prog_s)
{
	int i;

	i = 0;
	*prog_s += 2;
	while (i < 16)
	{
		if (ft_strcmp(command, g_op_tab[i].command) == 0)
		{
			if (cur_com_size)
				*cur_com_size = g_size2[i];
			if (prog_s)
				*prog_s += g_codage_octal2[i] - 1;
			return (i + 1);
		}
		i++;
	}
	return (MAX_INT);
}

unsigned int	do_big_endian(unsigned int magic, int size)
{
	unsigned int	res;
	int				i;

	i = 0;
	res = 0;
	size = (size - 1) * 8;
	while (i <= size)
	{
		res |= ((magic >> (size - i) & 0xFF)) << i;
		i += 8;
	}
	return (res);
}

void			modify_size(t_asm *head, t_asm *begin, int cur_size)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (begin->what_args[i] == T_DIR)
			head->header->prog_size += cur_size;
		else
		{
			if (begin->what_args[i] == T_IND)
				head->header->prog_size += T_DIR;
			else
				head->header->prog_size += begin->what_args[i];
		}
		i++;
	}
}

void			get_prog_size(t_asm *head)
{
	t_asm	*begin;
	int		cur_com_size;

	begin = head;
	cur_com_size = 4;
	while (begin)
	{
		if (begin->label)
		{
			begin->program_s = head->header->prog_size;
			if (ft_strcmp(begin->label, "source") == 0)
			{
				begin->program_s = begin->program_s - 2;
				head->header->prog_size = head->header->prog_size - 2;
			}
		}
		if (begin->command)
		{
			check_if_comand_is(begin->command, &cur_com_size,
					&(head->header->prog_size));
			modify_size(head, begin, cur_com_size);
		}
		begin = begin->next;
	}
	head->header->prog_size = do_big_endian(head->header->prog_size, 4);
}

void			header_parse(t_asm *head)
{
	t_asm	*begin;

	begin = head;
	head->header->magic = do_big_endian(COREWAR_EXEC_MAGIC, 4);
	ft_bzero(head->header->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(head->header->comment, COMMENT_LENGTH + 1);
	fill_name_and_comment(head);
	get_prog_size(head);
}
