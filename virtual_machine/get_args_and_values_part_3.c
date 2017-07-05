/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_and_values_part_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:34:25 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:34:27 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_args(t_car *car, int i)
{
	int read_size;

	if (car->args[i].name == T_REG)
		read_size = T_REG;
	else if (car->args[i].name == T_DIR)
		read_size = car->op_tabble.codage_octal == 0 ? DIR_SIZE : IND_SIZE;
	else if (car->args[i].name == T_IND)
		read_size = IND_SIZE;
	else
		read_size = 0;
	return (read_size);
}
