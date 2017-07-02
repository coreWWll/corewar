//
// Created by Yevhen Yefimov on 6/7/17.
//

#include "vm.h"

void	read_args_from_char(t_car *car, unsigned char c, int pos)
{
	unsigned char	buf;
	int				i;

	i = 0;
	car->args[0].name = 0;
	car->args[1].name = 0;
	car->args[2].name = 0;
	car->args[0].name = c >> 6;
	car->args[1].name = (buf = (c >> 4) << 6) >> 6;
	car->args[2].name = (buf = (c >> 2) << 6) >> 6;
	while (i < 3)
	{
		if (car->args[i].name == REG_CODE)
			car->args[i].name = T_REG;
		if (car->args[i].name == DIR_CODE)
			car->args[i].name = T_DIR;
		if (car->args[i].name == IND_CODE)
			car->args[i].name = T_IND;
		i++;
	}
}

int		read_one_arg(t_car *car, unsigned char *map, int read_size)
{
	int		nbr;
	int		i;

	i = 0;
	nbr = 0;
	while (read_size > i)
	{
		nbr = nbr << 8;
		nbr |= map[i];
		i++;
	}
	return (nbr);
}

int 	read_args(t_car *car, unsigned char *map)
{
	int		i;
	int		error;
	int		buf;
	int 	read_size;

	i = 0;
	error = FALSE;
	while (i < car->op_tabble.args_am)
	{
		if (car->args[i].name == T_REG)
			read_size = T_REG;
		else if (car->args[i].name == T_DIR)
			read_size = car->op_tabble.codage_octal == 0 ? DIR_SIZE : IND_SIZE;
		else if (car->args[i].name == T_IND)
			read_size = IND_SIZE;
		else
				read_size = 0;
		buf = car->op_tabble.args[i] & car->args[i].name;
		if (buf != car->args[i].name || buf == 0)
			error = TRUE;
		if (error == FALSE)
			car->args[i].value = read_one_arg(car, map, read_size);
		if (car->args[i].name == T_IND)
			car->args[i].value = (short)car->args[i].value;
		if (car->args[i].name == T_REG && car->args[i].value < 0)
			return (FALSE);
		car->arg_size += read_size;
		map += read_size;
		i++;
	}
	return (error);
}

int		get_args_nd_value(t_car *car, t_vm *main_struct)
{
	int		local_pos;

 	car->arg_size = 0;
	car->args_error = TRUE;
	local_pos = car->pos + 1;
	read_args_from_char(car, (unsigned char)main_struct->map[local_pos],
			local_pos);
	local_pos++;
	if (read_args(car, (unsigned char*)main_struct->map + local_pos))
	{
		if (car->arg_size == 0)
			car->arg_size++;
		return FALSE;
	}
	if ((car->op_tabble.opcode == 4 || car->op_tabble.opcode == 5 ||
			car->op_tabble.opcode == 6 || car->op_tabble.opcode == 7 ||
			car->op_tabble.opcode == 8 || car->op_tabble.opcode == 10 ||
			car->op_tabble.opcode == 14) && (car->args[2].name == T_REG &&
			car->args[2].value  > 0 && car->args[2].value <= REG_NUMBER
													) )
		get_values_reg_end(car, main_struct, 0);
	else if (car->op_tabble.opcode == 11 && (car->args[0].name == T_REG &&
										car->args[0].value > 0 &&
			car->args[0].value  <= REG_NUMBER ))
		get_values_reg_start(car, main_struct, 1);
	else if (car->op_tabble.opcode == 2 || car->op_tabble.opcode == 3 ||
			car->op_tabble.opcode == 13)
		get_ldst_args(car, main_struct, 1);
	else
		return (FALSE);
	return (car->args_error);
}