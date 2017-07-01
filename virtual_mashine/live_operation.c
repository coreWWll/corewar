//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"

int		get_int_from_byte_code(char *byte_array)
{
	int		i;

	i = ((byte_array[0] & 0xFF) << 24) + ((byte_array[1] & 0xFF) << 16)
			+ ((byte_array[2] & 0xFF) << 8) + (byte_array[3] & 0xFF);
	return (i);
}

void    get_live_func(char *map, t_car *car)
{
	car->live = 1;
    if (!(car->data = ft_memdup(4, map, car->pos + 1)))
		ft_error(ft_strjoin(ERR_MEM_ALLOC, "file: live_operation.c:17"));
	car->op_tabble.nb_tours--;
}

int		check_who_live(unsigned int number, t_vm *main_struct)
{
	int			i;

	i = 0;
	main_struct->f_alive = FALSE;
	while (main_struct->players[i])
	{
		if (number == main_struct->players[i]->name)
		{
			main_struct->players[i]->lives_in_current_period++;
			main_struct->nbr_of_lifes++;
			if (main_struct->f_alive)
				ft_printf("Player %d (%s) is said to be alive\n",
						  -number, main_struct->players[i]->bot_name);
			return (main_struct->players[i]->name);
		}
		i++;
	}
	return (0);
}

void    do_live_func(t_vm *main_struct, t_car *car)
{
	unsigned int	number;
	int 			new_life;

	main_struct->count_live_functions++;
	number = (unsigned int)get_int_from_byte_code(car->data);
	new_life = check_who_live(number, main_struct);
	if (new_life != 0)
	{
		main_struct->last_live[0] = new_life;
		main_struct->last_live[1] = main_struct->cycle;
	}
	car->pos = car->pos + DIR_SIZE + 1;
    car->op_tabble.opcode = 0;
    ft_strdel(&(car->data));
}

