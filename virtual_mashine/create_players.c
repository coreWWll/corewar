//
// Created by Yevhen Yefimov on 5/26/17.
//

#include "op.h"

t_player *add_player(int i, int n_bots)
{
    t_player    *new;

    new = (t_player *)malloc(sizeof(t_player));
    new->car = (t_car *)malloc(sizeof(t_car));
    new->name = -i;
    new->car->pos = ((MEM_SIZE / n_bots) * (i - 1));
    new->car->nb = 0;
    new->car->op_type = 0;
    new->car->c_for_op = 0;
    new->next = NULL;
    new->car->next = NULL;
    return (new);
}

void	check_magic(int fd)
{
	char	magic[4];

	ft_printf("sds = %x\n", COREWAR_EXEC_MAGIC);
	read(fd, magic, 4);
	ft_printf("%x", (unsigned  int*)magic);


	/*if (ft_strcmp((char *)COREWAR_EXEC_MAGIC, magic) != 0)
	{
		ft_print("asdasd");
		exit(-2);
	}*/
}

void	*get_player_name(int fd)
{
	void *name;

	name = malloc(PROG_NAME_LENGTH);
	read(fd, name, PROG_NAME_LENGTH);
	return (name);
}

void	*get_player_comment(int fd)
{
	void *comm;

	comm = malloc(COMMENT_LENGTH);
	read(fd, comm, COMMENT_LENGTH);

	return (comm);
}

void	put_bot_on_map(char *map, int fd, int n_bots, int *n)
{
	int				i;
	unsigned char 			buf[1];
	int 			k;

	k = *n;
	i = 0;
	while (read(fd, buf, 1))
	{
		map[i + ( MEM_SIZE / n_bots ) * k] = buf[0];
		i++;
	}
}

t_player    *create_players(void *map, int n_bots, char *file_name, int *n)
{
    t_player    *p_list;
	int fd;

	p_list = add_player(*n, n_bots);
	if ((fd = open(file_name, O_RDONLY)) < 3)
		exit(-2);
	check_magic(fd);
	p_list->bot_name = get_player_name(fd);
	p_list->comment = get_player_comment(fd);
	put_bot_on_map(map, fd, n_bots, *n);
	(*n)++;
	return (NULL);
}