/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:28:30 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:28:39 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player *add_player(int boot_nbr)
{
    t_player    *new;


    new = (t_player *)ft_memalloc(sizeof(t_player));
    new->car = (t_car *)ft_memalloc(sizeof(t_car));
	new->car->live = 0;
	new->boot_nbr = boot_nbr;
	new->car->next = NULL;
	ft_bzero(new->car->reg, sizeof(int) * 16);
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

int			name_is_taken(t_vm *main_struct, int name)
{
	int	i;

	i = 0;
	while (main_struct->players[i])
	{
		if (main_struct->players[i]->boot_nbr == name)
			return TRUE;
		i++;
	}
	return FALSE;
}

void		create_names_players(t_vm *main_struct)
{
	int		i;
	int 	names;

	i = 0;
	names = 1;
	while (main_struct->players[i])
	{
		if (main_struct->players[i]->boot_nbr == 0)
		{
			while (name_is_taken(main_struct, names))
				names++;
			main_struct->players[i]->name = -names;
			names++;
		}
		else
			main_struct->players[i]->name = - main_struct->players[i]->boot_nbr;
		i++;
	}
}
