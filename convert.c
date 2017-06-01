//
// Created by Oleksiy Kres on 5/26/17.
//

#include "op.h"

void	get_commands(t_asm *head)
{
	t_asm *begin;

	begin = head;
	while (begin)
	{

		begin = begin->next;
	}
}

void	to_byte_code(t_asm *head)
{
	t_asm	*begin;
	char 	*file_name;
	int		fd;

	file_name = ft_strjoin(head->file_name, ".cor");
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	begin = head;
	head->header = (header_t *)malloc(sizeof(header_t));
	header_parse(head, fd);
	write(fd, &(*head->header), sizeof(header_t));
	get_commands(head);
}
