//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_fork_func(char *map, t_car *car)
{
	if (!(car->data = ft_memdup((size_t)DIR_SIZE - 2 * car->op_tabble.codage_octal, map, car->pos + 1)))
		ft_error(ERR_MEM_ALLOC);
	car->op_type = 12;
	car->c_for_op = 799;
	ft_printf ("-> read FORK instruction, data = %s\n", car->data);
}

short		get_short_from_byte_code(char *buffer)
{

	return (( (short)buffer[1] ) | ( (short )buffer[0] << 8 ));
}
t_car	*add_car(t_car *car, int delta)
{
	t_car	*new;

	new = ft_memalloc(sizeof(t_car));
	new = ft_memmove(new, car, sizeof(t_car));
	new->pos = new->pos + delta;
	new->op_type = 0;
	new->live = 0;
	new->next = NULL;
	return (new);
}

void	create_new_car(t_car *car, int delta)
{
	t_car	*ptr;

	ptr = car;
	while (ptr->next)
	{
		printf("$$$$$$$$$$$$$$$$$$$$$$$$\n");
		ptr = ptr->next;
	}
	ptr->next = add_car(car, delta);
}

void    do_fork_func(t_vm *main_struct, t_car *car)
{
	int delta;

	delta = (int)get_short_from_byte_code(car->data);
	ft_printf("!!!!!!!!!!!!!!!!!!!!short = %d\n", delta);
	create_new_car(car, delta);
	ft_printf("-> FORK <-\n");
	car->pos = car->pos + 1 + DIR_SIZE - 2 * car->op_tabble.codage_octal;
	car->op_type = 0;
}
