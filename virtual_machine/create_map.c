/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:28:14 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:28:15 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	put_bot_on_map(char *map, t_vm *main_struct, int n)
{
	int			cor_bot;
	size_t		i;
	t_player	*player;

	i = 0;
	player = (main_struct->players)[n];
	cor_bot = (MEM_SIZE / main_struct->players_nbr) * n;
	while (i < player->prog_len)
	{
		map[i + cor_bot] = (player->champ_code)[i];
		main_struct->color[i + cor_bot] = (char)(n + 1);
		i++;
	}
}

void	create_map(t_vm *main_struct)
{
	int		i;
	char	*map;

	i = 0;
	map = ft_memalloc(MEM_SIZE);
	while ((main_struct->players)[i])
	{
		put_bot_on_map(map, main_struct, i);
		i++;
	}
	main_struct->map = map;
}
