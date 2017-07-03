/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_with_car.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:37:49 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:37:51 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	put_cat_on_start(t_vm	*main_struct)
{
	int i;

	i = 0;
	while (i < main_struct->players_nbr)
	{
		main_struct->players[i]->car->color = (char)(i + 1);
		main_struct->players[i]->car->pos = MEM_SIZE /
											main_struct->players_nbr * (i);
		main_struct->players[i]->car->reg[0] = (unsigned int)
				main_struct->players[i]->name;
		main_struct->players[i]->car->carry = 0;
		main_struct->players[i]->car->index = i;
		main_struct->players[i]->car->nb = i;
		i++;
	}
}

void	dell_car_from_list(t_car **head, t_car *to_dell, t_vm *main_struct)
{
	t_car	*ptr;
	t_car	*dell;

	ptr = *head;
	if (*head == to_dell)
	{
		*head = (*head)->next;
		main_struct->winner = ptr->index;
		ft_memdel((void**)&ptr);
	}
	else
	{
		while (ptr)
		{
			if (to_dell == ptr->next)
			{
				dell = ptr->next;
				ptr->next = ptr->next->next;
				main_struct->winner = ptr->index;
				ft_memdel((void **) &dell);
				break ;
			}
			else
				ptr = ptr->next;
		}
	}
}

int count_car(t_vm *main_struct)
{
	int 		count;
	t_player	**player;
	t_car		*car;
	int			i;

	count = 0;
	i = main_struct->players_nbr;
	player = main_struct->players;
	while (i)
	{
		car = player[i - 1]->car;
		while (car)
		{
			count++;
			car = car->next;
		}
		i--;
	}
	return (count);
}
