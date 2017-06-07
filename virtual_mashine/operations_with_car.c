//
// Created by Yevhen Yefimov on 6/7/17.
//

#include "vm.h"

void	put_cat_on_start(t_vm	*main_struct)
{
	int i;

	i = 0;
	while (i < main_struct->players_nbr)
	{
		main_struct->players[i]->car->pos = MEM_SIZE /
											main_struct->players_nbr * (i);
		i++;
	}
}