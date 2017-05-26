//
// Created by Oleksiy Kres on 5/26/17.
//

#include "corewar.h"

void	find_lable(t_asm *begin, char **args, int fd)
{
	t_asm			*save;
	int 			i;
	int 			j;
	unsigned char	*s;

	i = 0;
	j = 0;
	save = begin;
	while (save)
	{
		while (args[i])
		{
			if (ft_strcmp(save->lable, args[i]) == 0)
			{
				s = (unsigned char *)save->command;
				write(fd, s, ft_strlen(save->command));
				while (save->args[j])
				{

				}
			}
			i++;
		}
		save = save->next;
	}
}

void	get_lable(t_asm *begin, t_asm *head, int fd)
{
	if (head->l_flag > -1)
	{
		find_lable(begin, head->args, fd);
	}
}

void	get_command()
{

}

void	get_argument()
{

}

void	to_byte_code(t_asm *head)
{
	t_asm	*begin;
	char 	*file_name;
	int		fd;

	file_name = ft_strjoin(head->file_name, ".cor");
	fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND);
	begin = head;
	while (head)
	{
		get_lable(begin, head, fd);
		get_command();
		get_argument();
		head = head->next;
	}
}

int main()
{
	t_asm *assem;

	assem = malloc(sizeof(assem));
	assem->file_name = ft_strdup("NAME");
	to_byte_code(assem);
}
