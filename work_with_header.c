//
// Created by Oleksiy Kres on 15/29/17.
//

#include "op.h"

unsigned int	do_big_endian(unsigned int magic, int size)
{
	unsigned int	res;
	int 			i;

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

void			fill_name_and_comment(t_asm *head)
{
	int i;

	i = 0;
	while (head->comm[i])
	{
		head->header->comment[i] = head->comm[i];
		i++;
	}
	i = 0;
	while (head->name[i])
	{
		head->header->prog_name[i] = head->name[i];
		i++;
	}
}

int 			find_lable(t_asm *begin, char *lable)
{
	t_asm			*node;
	unsigned int	res;

	node = begin;
	while (node)
	{

		node = node->next;
	}
}

int 			get_index(int *ar)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		if (i == 1)
			j = i;
		i++;
	}
	return (j);
}

void			get_prog_size(t_asm *head)
{
	t_asm			*begin;
	unsigned int 	res;

	res = 0;
	begin = head;
	while (begin)
	{
		res += begin->what_args[0] + begin->what_args[1] + begin->what_args[2];
		if (begin->l_flag[0] == 1 || begin->l_flag[1] == 1 ||
				begin->l_flag[2] == 1)
		{
			res += find_lable(head, begin->args[get_index(begin->l_flag)]);
		}
		begin = begin->next;
	}
	head->header->prog_size = res;
}

void			fill_header_and_get_size(t_asm *head)
{
	t_asm *begin;

	begin = head;
	fill_name_and_comment(head);
	get_prog_size(head);
	while (begin)
	{
		begin = begin->next;
	}
}

void			header_parse(t_asm *head, int fd)
{
	head->header->magic = do_big_endian(COREWAR_EXEC_MAGIC, 4);
	ft_bzero(head->header->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(head->header->comment, COMMENT_LENGTH + 1);
	fill_header_and_get_size(head);

}
