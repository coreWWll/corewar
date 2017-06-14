//
// Created by denys on 02.06.17.
//

#include "vm.h"

void	put_bot_on_map(char *map, t_player *player, int n_bots, int n)
{
	int		cor_bot;
	size_t	i;

	i = 0;
	cor_bot = (MEM_SIZE / n_bots) * n;
	while (i < player->prog_len)
	{
		map[i + cor_bot] = (player->champ_code)[i];
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
		put_bot_on_map(map, (main_struct->players)[i],
					   main_struct->players_nbr, i);
		i++;
	}
	main_struct->map = map;
}