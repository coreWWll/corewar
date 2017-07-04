/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_and_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:34:12 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:34:15 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_args_from_char(t_car *car, unsigned char c)
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

int		read_one_arg(unsigned char **map, int read_size, t_vm *main_struct)
{
	int		nbr;
	int		i;

	i = 0;
	nbr = 0;
	while (read_size > i)
	{
		if ((char*)*map >= &(main_struct->map[MEM_SIZE]))
			*map = (unsigned char *)main_struct->map;
		nbr = nbr << 8;
		nbr |= **map;
		i++;
		(*map)++;
	}
	return (nbr);
}

int 	read_args(t_car *car, unsigned char *map, t_vm *main_struct)
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
			car->args[i].value = read_one_arg(&map, read_size, main_struct);
		if (car->args[i].name == T_IND)
			car->args[i].value = (short)car->args[i].value;
		if (car->args[i].name == T_REG && car->args[i].value < 0)
			return (FALSE);
		car->arg_size += read_size;
		i++;
	}
	return (error);
}

int conditions(t_car *car)
{
	if ((car->op_tabble.opcode == 4 || car->op_tabble.opcode == 5 ||
		 car->op_tabble.opcode == 6 || car->op_tabble.opcode == 7 ||
		 car->op_tabble.opcode == 8 || car->op_tabble.opcode == 10 ||
		 car->op_tabble.opcode == 14) && (car->args[2].name == T_REG &&
		 car->args[2].value  > 0 && car->args[2].value <= REG_NUMBER))
		return (1);
	else
		return (0);
}

int		get_args_nd_value(t_car *car, t_vm *main_struct)
{
	int		local_pos;

	car->args_error = TRUE;
	local_pos = car->pos + 1 >= MEM_SIZE ? 0 : car->pos + 1;
	read_args_from_char(car, (unsigned char)main_struct->map[local_pos]);
	local_pos++;
	if (read_args(car, (unsigned char*)main_struct->map + local_pos,
				  main_struct))
	{
		if (car->arg_size == 0)
			car->arg_size++;
		return FALSE;
	}
	if (conditions(car))
		get_values_reg_end(car, main_struct, 0);
	else if (car->op_tabble.opcode == 11 && (car->args[0].name == T_REG &&
										car->args[0].value > 0 &&
			car->args[0].value  <= REG_NUMBER))
		get_values_reg_start(car, main_struct, 1);
	else if (car->op_tabble.opcode == 2 || car->op_tabble.opcode == 3 ||
			car->op_tabble.opcode == 13)
		get_ldst_args(car, main_struct, 1);
	else
		return (FALSE);
	return (car->args_error);
}
