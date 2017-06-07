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
		main_struct->players[i]->car->nb = 0;
		if (main_struct->players[i]->boot_nbr != 0)
		{
			main_struct->players[i]->name = (unsigned int)
					main_struct->players[i]->boot_nbr;
			main_struct->players[i]->car->reg[0] =
					(unsigned int) main_struct->players[i]->boot_nbr;
		}
		else
		{
			main_struct->players[i]->name = (i * (-1));
			main_struct->players[i]->car->reg[0] = (unsigned int) (i * (-1));
		}
		i++;
	}
}