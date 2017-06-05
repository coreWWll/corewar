//
// Created by Oleksiy Kres on 5/26/17.
//

#include "op.h"

int 	check_if_comand(char *command)
{
	int i;
	int size[] = {4, 4, 0, 0, 0, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4};
	int codage_octal[] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1};
	char *comm[] = {"live", "ld", "st", "add", "sub", "and", "or",
				  "xor", "zjmp", "ldi", "sti", "fork", "lld",
				  "lldi", "lfork", "aff"};

	i = 0;
	if (!command)
		return (MAX_INT);
	while (i < 16)
	{
		if (ft_strcmp(command, comm[i]) == 0)
			return (i + 1);
		i++;
	}
	return (MAX_INT);
}

void	get_commands(t_asm *head, int fd)
{
	t_asm	*begin;
	int 	op_c;

	begin = head;
	while (begin)
	{
		if ((op_c = check_if_comand(begin->command)) != MAX_INT)
			write_op_code(head, begin, op_c, fd);
		begin = begin->next;
		if (begin->next == NULL)
			break ;
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
	get_commands(head, fd);
}
