//
// Created by denys on 13.06.17.
//

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

void	create_windows(t_vm *main_struct)
{
	int	h;

	h = MEM_SIZE / CHAR_IN_ROW;
	main_struct->vis->bg_arena = newwin(h + 2, (CHAR_IN_ROW * 3) + 2, 1, 1);
	main_struct->vis->arena = newwin(h, CHAR_IN_ROW * 3, 2, 2);
	wbkgd(main_struct->vis->bg_arena, COLOR_PAIR(COL_ARENA));
	wbkgd(main_struct->vis->arena, COLOR_PAIR(COL_ARENA));
	main_struct->vis->bg_param = newwin(42 , 52, 1, (CHAR_IN_ROW * 3) + 4);
	main_struct->vis->param = newwin(40, 50, 2, (CHAR_IN_ROW * 3) + 5);
	wbkgd(main_struct->vis->bg_param, COLOR_PAIR(COL_ARENA));
	wbkgd(main_struct->vis->param, COLOR_PAIR(COL_ARENA));
	main_struct->vis->bg_usage = newwin(23, 52, 44, (CHAR_IN_ROW * 3) + 4);
	main_struct->vis->usage = newwin(21, 50, 45, (CHAR_IN_ROW * 3) + 5);
	wbkgd(main_struct->vis->bg_usage, COLOR_PAIR(COL_ARENA));
	wbkgd(main_struct->vis->usage, COLOR_PAIR(COL_ARENA));
	wrefresh(main_struct->vis->bg_arena);
	wrefresh(main_struct->vis->bg_param);
	wrefresh(main_struct->vis->bg_usage);
	wrefresh(main_struct->vis->usage);
	nodelay(main_struct->vis->arena, TRUE);
}

void start_visualisation(t_vm *main_struct)
{
	short int	i;

	main_struct->vis = (t_vis*)ft_memalloc(sizeof(t_vis));
	initscr();
	noecho();
	curs_set(FALSE);
	start_color();
	i = 1;
	while (i < COLOR_CYAN)
	{
		init_pair(i, COLOR_BLACK, i);
		i++;
	}
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
	endwin();
}
