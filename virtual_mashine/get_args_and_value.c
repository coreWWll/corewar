//
// Created by Yevhen Yefimov on 6/7/17.
//

#include "vm.h"

void	read_args_from_char(t_car *car, unsigned char c, int pos)
{
	unsigned char	buf;
	int				i;

	i = 0;
	car->args[0].name = c >> 6;
	car->args[1].name = (buf = (c >> 4) << 6) >> 6;
	car->args[2].name = (buf = (c >> 2) << 6) >> 6;
	while (i < 3)
	{
		if (car->args[i].name == 3)
			car->args[i].name == 4;
		i++;
	}
}

int 	compare_args(int *example, int *args, )
{
	int		i;

	i = 0;
	while (i < 3)
	{
		
		i++;
	}
	return TRUE;
}

int		get_args_nd_value(t_car *car, t_vm *main_struct)
{
	int		local_pos;

	local_pos = car->pos + 1;
	read_args_from_char(car, main_struct->map[local_pos], local_pos);
	if (!compare_args(car->op_tabble.args, car->args))
		return FALSE;
}