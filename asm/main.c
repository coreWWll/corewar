/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 main.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: arepnovs <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/06/07 14:07:01 by arepnovs		   #+#	  #+#			  */
/*	 Updated: 2017/06/07 14:07:01 by arepnovs		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../op.h"

void	make_list(t_asm **start, char *line)//main
{
	t_asm *p;

	p = *start;
	while (p)
	{
		if (p->only_label == 1) // check if label is empty to add command in it
		{
			get_all_info(p, line);
			p->only_label = 0;
			break ;
		}
		else if (p->next == NULL)
		{
			if (p->command || p->label) //if lable was empty in prev iteration
			{
				p->next = new_asm();
				p = p->next;
			}
			get_all_info(p, line);
			if (p->only_label != 1)
				p->next = new_asm();
			break ;
		}
		p = p->next;
	}
}

void	do_parsing_work(char *av, t_asm *start)
{
	char	*line;
	int		fd;

	if ((fd = open(av, O_RDONLY)) != -1)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			if (ft_strstr(line, NAME_CMD_STRING))
				start->name = get_name_or_comm(line, fd, 1);
			else if (ft_strstr(line, COMMENT_CMD_STRING))
				start->comm = get_name_or_comm(line, fd, 0);
			else if (if_comment(line) != 1)
				make_list(&start, line);
			ft_strdel(&line);
		}
		check_if_end_is_newln(av);
		ft_strdel(&line);
	}
	else
		ft_exit(3);
}

int		main(int ac, char **av)
{
	t_asm	*start;

	if (ac == 2)
	{
		start = new_asm();
		start->file_path = get_result_output(av[1]);
		start->file_name = (av[1][0] == '.') ? get_file_name(av[1]) : av[1];
		check_format(av[1]);
		do_parsing_work(av[1], start);
		validate_it(start);
		to_byte_code(start);
		mult_putstr("Writing output program to ", start->file_path, ".cor\n");
	}
	else
		write(1, "Usage: ./asm [path to the champion_file.s]\n", 43);
	sleep(20);
	return (0);
}
