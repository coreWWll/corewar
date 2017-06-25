//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_fork_func(char *map, t_car *car)
{
	if (!(car->data = ft_memdup((size_t)DIR_SIZE - 2 * car->op_tabble.codage_octal, map, car->pos + 1)))
		ft_error(ft_strjoin(ERR_MEM_ALLOC, "file: fork_operation.c:10"));
	car->op_tabble.nb_tours--;
	//ft_printf ("-> read FORK instruction, data = %r\n", car->data);
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
	new->op_tabble.opcode = 0;
	new->live = 0;
	new->next = NULL;
	return (new);
}

void	create_new_car(t_car *car, int delta)
{
	t_car	*ptr;

	ptr = add_car(car, delta);
	ptr->next = car;
	car = ptr;
}

void    do_fork_func(t_vm *main_struct, t_car *car)
{
	int dist;
	int arg_size;

	arg_size = car->op_tabble.codage_octal == 0 ? DIR_SIZE : IND_SIZE;
	dist = (int)get_short_from_byte_code(car->data, car->op_tabble
			.codage_octal) % IDX_MOD;
	//ft_printf("FORK DISTANCE = %d\n", dist);
	create_new_car(car, dist);
	//ft_printf("-> FORK <-\n");
	car->pos = car->pos + 1 + arg_size;
	car->op_tabble.opcode = 0;
	if (car->data)
		ft_strdel(&(car->data));
}
