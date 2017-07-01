/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 16:39:10 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/01 16:39:12 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"
#include "visualisation.h"

void	erase_all(t_vis *vis)
{
	werase(vis->param);
	werase(vis->arena);
}

void	refresh_all(t_vis *vis)
{
	wrefresh(vis->param);
	wrefresh(vis->arena);
}

void	init_color_pair_from(short from, short till, short let)
{
	short	save_from;
	short	fon;

	save_from = (short)(from - 1);
	till += save_from;
	while (from < till)
	{
		if (save_from != 0)
			fon = from % save_from;
		else
			fon = from;
		init_pair(from, let, fon);
		from++;
	}
}

void	start_visualisation(t_vm *main_struct)
{
	main_struct->vis = (t_vis*)ft_memalloc(sizeof(t_vis));
	main_struct->vis->pause = TRUE;
	main_struct->vis->t_pause = -1;
	main_struct->vis->h_pause = -1;
	initscr();
	noecho();
	curs_set(FALSE);
	start_color();
	init_color_pair_from(1, COLOR_CYAN, COLOR_BLACK);
	init_color_pair_from(COL_NEW_MEM + 1, COLOR_CYAN, COLOR_WHITE);
	init_pair(COL_ARENA, COLOR_BLACK, COLOR_CYAN);
	init_pair(COL_CAR, COLOR_WHITE, COLOR_BLACK);
	create_windows(main_struct);
	w_print_usage(main_struct->vis->usage);
}

void	stop_visualisation(t_vm *main_struct)
{
	delwin(main_struct->vis->arena);
	delwin(main_struct->vis->param);
	delwin(main_struct->vis->usage);
	delwin(main_struct->vis->bg_arena);
	delwin(main_struct->vis->bg_param);
	delwin(main_struct->vis->bg_usage);
	curs_set(TRUE);
	endwin();
}
