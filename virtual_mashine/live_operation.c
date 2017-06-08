//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"

int		get_int_from_byte_code(char *buffer)
{

	return (buffer[3] | ( (int)buffer[2] << 8 ) | ( (int)buffer[1] << 16 ) |
			( (int)buffer[0] << 24 ));
}

void    get_live_func(char *map, t_car *car)
{
    car->data = ft_memdup(REG_SIZE, map, car->pos + 1);
    car->op_type = op_tab[0].opcode;
    car->c_for_op = op_tab[0].nb_tours - 1;
    car->pos = car->pos + REG_SIZE + 1;
    ft_printf ("-> read LIVE instruction, data = %s\n", car->data);
}

int		check_who_live(unsigned int number, t_vm *main_struct)
{
	int			i;

	i = 0;

	while (main_struct->players[i])
	{
		if (number == main_struct->players[i]->name)
		{
			main_struct->players[i]->lives_in_current_period++;
			return (main_struct->players[i]->name);
		}
		i++;
	}
	return (0);
}

void    do_live_func(t_vm *main_struct, t_car *car)
{
	unsigned int number;

	car->live = 1;
	number = (unsigned int)get_int_from_byte_code(car->data);
	ft_printf ("Player %d", check_who_live(number, main_struct));
	main_struct->last_live[0] = check_who_live(number, main_struct);
	main_struct->last_live[1] = main_struct->cycle;
    car->op_type = 0;
    ft_strdel(&(car->data));
}

