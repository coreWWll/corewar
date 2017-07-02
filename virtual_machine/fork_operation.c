//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_fork_func(char *map, t_car *car)
{
	car->op_tabble.nb_tours--;
}

short		get_short_from_byte_code(char *buffer, int flag)
{
	if (flag == 0)
		return((buffer[0] & 0xFF) << 24) + ((buffer[1] & 0xFF) << 16)
				   + ((buffer[2] & 0xFF) << 8) + (buffer[3] & 0xFF);
	else
		return ((buffer[0] & 0xFF) << 8) + ((buffer[1] & 0xFF));
}
t_car	*add_car(t_car *car, int delta)
{
	t_car	*new;

	new = ft_memalloc(sizeof(t_car));
	new = ft_memmove(new, car, sizeof(t_car));
	new->pos = new->pos + delta;
	if (new->pos > MEM_SIZE)
		new->pos = new->pos - MEM_SIZE;
	new->op_tabble.opcode = 0;
	new->next = NULL;
	return (new);
}

t_car	*create_new_car(t_car *head, t_car *car, int delta, t_vm *main_struct)
{
	t_car	*ptr;

	ptr = add_car(car, delta);
	move_single_car(main_struct, ptr);
	ptr->next = head;
	return (ptr);
}

void    do_fork_func(t_vm *main_struct, t_car *car)
{
	int dist;
	int arg_size;
	int i;

	i = 0;
	arg_size = car->op_tabble.codage_octal == 0 ? DIR_SIZE : IND_SIZE;
	dist = (int)get_short_from_byte_code(main_struct->map + car->pos + 1,
			car->op_tabble
			.codage_octal) % IDX_MOD;
	while (i < main_struct->players_nbr)
	{
		if (car->index == i)
			main_struct->players[i]->car = create_new_car
				(main_struct->players[i]->car, car, dist, main_struct);
		i++;
	}
	car->op_tabble.opcode = 0;
	car->pos = car->pos + arg_size + 1;
}
