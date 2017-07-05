/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 17:02:33 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/01 17:02:37 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisation.h"

void	throw_resize_vis(t_vm *main_struct)
{
	int h;

	h = MEM_SIZE / CHAR_IN_ROW;
	wbkgd(stdscr, COLOR_PAIR(0));
	delwin(main_struct->vis->usage);
	delwin(main_struct->vis->bg_usage);
	wrefresh(stdscr);
	wresize(main_struct->vis->bg_arena, h + 2, (CHAR_IN_ROW * 3) + 2);
	wresize(main_struct->vis->arena, h, (CHAR_IN_ROW * 3));
	wresize(main_struct->vis->bg_param, 42, 52);
	wresize(main_struct->vis->param, 40, 50);
	wrefresh(main_struct->vis->bg_param);
	wrefresh(main_struct->vis->bg_arena);
	wbkgd(main_struct->vis->bg_arena, COLOR_PAIR(COL_ARENA));
	wbkgd(main_struct->vis->bg_param, COLOR_PAIR(COL_ARENA));
	wrefresh(main_struct->vis->bg_param);
	wrefresh(main_struct->vis->bg_arena);
	main_struct->vis->bg_usage = newwin(23, 52, 44, (CHAR_IN_ROW * 3) + 4);
	main_struct->vis->usage = newwin(21, 50, 45, (CHAR_IN_ROW * 3) + 5);
	wbkgd(main_struct->vis->bg_usage, COLOR_PAIR(COL_ARENA));
	wbkgd(main_struct->vis->usage, COLOR_PAIR(COL_ARENA));
	wrefresh(main_struct->vis->bg_usage);
	w_print_usage(main_struct->vis->usage);
	wrefresh(main_struct->vis->usage);
}

void	stop_vis_and_exit(t_vm *main_struct)
{
	stop_visualisation(main_struct);
	exit(1);
}

void	throw_visualization(t_vm *main_struct, char *status)
{
	erase_all(main_struct->vis);
	put_caret_on_map(main_struct);
	w_print_arena(main_struct);
	w_print_param(main_struct, status);
	refresh_all(main_struct->vis);
}

void	visualisate(t_vm *main_struct)
{
	read_commands(main_struct);
	if (check_if_refresh(main_struct) && main_struct->vis->go_to_end == FALSE)
	{
		throw_visualization(main_struct, "PLAY");
		time_pause(main_struct);
	}
}
