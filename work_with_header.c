//
// Created by Oleksiy Kres on 5/29/17.
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

void			header_parse(t_asm *head, int fd)
{
	head->header->magic = do_big_endian(COREWAR_EXEC_MAGIC, 4);
	ft_bzero(head->header->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(head->header->comment, COMMENT_LENGTH + 1);
	fill_header_and_get_size();

}
