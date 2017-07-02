/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 16:46:49 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/01 16:46:51 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisation.h"

void	create_windows(t_vm *main_struct)
{
	int	h;

	h = MEM_SIZE / CHAR_IN_ROW;
	main_struct->vis->bg_arena = newwin(h + 2, (CHAR_IN_ROW * 3) + 2, 1, 1);
	main_struct->vis->arena = newwin(h, CHAR_IN_ROW * 3, 2, 2);
	wbkgd(main_struct->vis->bg_arena, COLOR_PAIR(COL_ARENA));
	wbkgd(main_struct->vis->arena, COLOR_PAIR(COL_ARENA));
	main_struct->vis->bg_param = newwin(42, 52, 1, (CHAR_IN_ROW * 3) + 4);
	main_struct->vis->param = newwin(40, 50, 2, (CHAR_IN_ROW * 3) + 5);
	wbkgd(main_struct->vis->bg_param, COLOR_PAIR(COL_ARENA));
	wbkgd(main_struct->vis->param, COLOR_PAIR(COL_ARENA));
	main_struct->vis->bg_usage = newwin(23, 52, 44, (CHAR_IN_ROW * 3) + 4);
	main_struct->vis->usage = newwin(21, 50, 45, (CHAR_IN_ROW * 3) + 5);
	wbkgd(main_struct->vis->bg_usage, COLOR_PAIR(COL_ARENA));
	wbkgd(main_struct->vis->usage, COLOR_PAIR(COL_ARENA));
	wrefresh(main_struct->vis->bg_arena);
	wrefresh(main_struct->vis->bg_param);
	wrefresh(main_struct->vis->usage);
	wrefresh(main_struct->vis->bg_usage);
	nodelay(main_struct->vis->arena, TRUE);
}
