//
// Created by Yevhen Yefimov on 5/26/17.
//

#include "vm.h"

t_player *add_player(int boot_nbr)
{
    t_player    *new;

    new = (t_player *)ft_memalloc(sizeof(t_player));
    new->car = (t_car *)malloc(sizeof(t_car));
	new->boot_nbr = boot_nbr;
    return (new);
}

t_player	*create_players(char *file_name, int boot_nbr)
{
    t_player    *p_list;
	int			fd;

	p_list = add_player(boot_nbr);
	if ((fd = open(file_name, O_RDONLY)) < 3)
		ft_error(ft_strjoin(ERR_OPEN_FILE, file_name));
	if (get_int_from_file(fd) != COREWAR_EXEC_MAGIC)
		ft_error(ft_strjoin(file_name, " - isn't player file"));
	p_list->bot_name = get_string_from_file(fd, PROG_NAME_LENGTH + 4);
	if ((p_list->prog_len = (size_t)get_int_from_file(fd)) > CHAMP_MAX_SIZE)
		ft_error(ft_strjoin(ERR_PLAYER_SIZE, file_name));
	p_list->comment = get_string_from_file(fd, COMMENT_LENGTH + 4);
	p_list->champ_code = get_champ_code(fd, p_list->prog_len);
	return (p_list);
}
