//
// Created by Oleksiy Kres on 5/26/17.
//

#include "corewar.h"

void	get_lable(t_asm *begin, t_asm *head, int fd);

int 	find_lable_in_args(int *ar)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (ar[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

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
					if (save->l_flag[j] > 0)
						get_lable(begin, save, fd);
					else
						write(fd, save->args[j], ft_strlen(save->args[j]));
					j++;
				}
			}
			i++;
		}
		save = save->next;
	}
}

void	get_lable(t_asm *begin, t_asm *head, int fd)
{
	int 			i;
	unsigned char	*s;

	i = 0;
	if (find_lable_in_args(head->l_flag))
		find_lable(begin, head->args, fd);
	else if (head->command)
	{
		s = (unsigned char *)head->command;
		write(fd, s, ft_strlen(head->command));
		while (head->args[i])
		{
			write(fd, head->args[i], ft_strlen(head->args[i]));
			i++;
		}
	}

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
