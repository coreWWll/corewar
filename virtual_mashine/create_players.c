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

void	put_bot_on_map(char *map, char *champ_code, int cor_bot, size_t prog_len)
{
	size_t	i;

	i = 0;
	while (i < prog_len)
	{
		map[i + cor_bot] = champ_code[i];
		i++;
	}
	ft_strdel(&champ_code);
}

t_player    *create_players(void *map, int n_bots, char *file_name, int n)
{
    t_player    *p_list;
	size_t		prog_len;
	int			fd;

	p_list = add_player(n, n_bots);
	if ((fd = open(file_name, O_RDONLY)) < 3)
		exit(-2);
	if (get_int_from_file(fd) != COREWAR_EXEC_MAGIC)
		exit(-5);
	p_list->bot_name = get_string_from_file(fd, PROG_NAME_LENGTH + 4);
	prog_len = (size_t)get_int_from_file(fd);
	p_list->comment = get_string_from_file(fd, COMMENT_LENGTH + 4);
	put_bot_on_map(map, get_champ_code(fd, prog_len), (MEM_SIZE / n_bots ) *
			(n - 1), prog_len);
	return (p_list);
}