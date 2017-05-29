//
// Created by Oleksiy Kres on 5/26/17.
//

#include "op.h"

void	to_byte_code(t_asm *head)
{
	t_asm	*begin;
	char 	*file_name;
	int		fd;

	file_name = ft_strjoin(head->file_name, ".cor");
	fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND);
	begin = head;
	head->header = (header_t *)malloc(sizeof(header_t));
	header_parse(head, fd);
}
