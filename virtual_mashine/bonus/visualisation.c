//
// Created by denys on 13.06.17.
//

#include "../vm.h"
#include "visualisation.h"

void	erase_all(t_vis *vis)
{
	werase(vis->arena);
	werase(vis->param);
}

void	refresh_all(t_vis *vis)
{
	wrefresh(vis->arena);
	wrefresh(vis->param);
}

void	create_windows(t_vm *main_struct)
{
	WINDOW	*background_arena;
	WINDOW	*background_param;

	background_arena = newwin((MEM_SIZE / CHAR_IN_ROW) + 2,
							  (CHAR_IN_ROW * 3) + 2, 1, 1);
	main_struct->vis->arena = newwin(MEM_SIZE / CHAR_IN_ROW,
									 CHAR_IN_ROW * 3, 2, 2);
	wbkgd(background_arena, COLOR_PAIR(COL_ARENA));
	wbkgd(main_struct->vis->arena, COLOR_PAIR(COL_ARENA));
	background_param = newwin(50, 50, 1, (CHAR_IN_ROW * 3) + 4);
	wbkgd(background_param, COLOR_PAIR(COLOR_RED));
	wrefresh(background_arena);
	wrefresh(background_param);
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
	create_windows(main_struct);
}

void	stop_visualisation(t_vm *main_struct)
{
	delwin(main_struct->vis->arena);
	delwin(main_struct->vis->param);
	endwin();
}
