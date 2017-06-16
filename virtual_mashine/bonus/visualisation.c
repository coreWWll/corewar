//
// Created by denys on 13.06.17.
//

#include "../vm.h"
#include "visualisation.h"
#include <ncurses.h>

void	refresh_all(t_vis *vis)
{
	refresh();
	wrefresh(vis->arena);
	wrefresh(vis->param);
}

void	create_windows(t_vm *main_struct, short color_pair)
{
	WINDOW	*background_arena;
	WINDOW	*background_param;

	background_arena = newwin((MEM_SIZE / CHAR_IN_ROW) + 2,
							  (CHAR_IN_ROW * 3) + 2, 1, 1);
	main_struct->vis->arena = newwin(MEM_SIZE / CHAR_IN_ROW,
									 CHAR_IN_ROW * 3, 2, 2);
	wbkgd(background_arena, COLOR_PAIR(color_pair));
	wbkgd(main_struct->vis->arena, COLOR_PAIR(color_pair));
	background_param = newwin(50, 50, 1, (CHAR_IN_ROW * 3) + 4);
	wbkgd(background_param, COLOR_PAIR(COLOR_RED));
	wrefresh(background_arena);
	wrefresh(background_param);
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
	while (i < COLOR_WHITE)
	{
		init_pair(i, COLOR_BLACK, i);
		if (i == COLOR_CYAN)
			create_windows(main_struct, i);
		i++;
	}

}

void	stop_visualisation(t_vm *main_struct)
{
	delwin(main_struct->vis->arena);
	delwin(main_struct->vis->param);
	endwin();
}



/*
 *
 * #include <time.h>

int 	i = 0;


void	get_input(t_vm *main_struct)
{
	char	buf[2];

	if (ft_kbhit() && fgets(buf, 2, stdin))
	{
		if (buf[0] == '+' && main_struct->time > 10)
			main_struct->time -= 10;
		if (buf[0] == '-' && main_struct->time < 9990)
			main_struct->time += 10;
	}
}

void	visualisation(t_vm *main_struct)
{
	long	time;

	//210 * 100000 50/c
	//    1/c
	time = 10000 * main_struct->time;
	get_input(main_struct);
	ft_putstr(CLEARE);
	ft_putstr(TO_BEGIN);
	printf("CYCLE = %10d PERIOD = %10d\n", main_struct->cycle, main_struct
		->round);
	//ft_putnbr(main_struct->time);
	if (main_struct->cycle % 50 == 0)
		i++;
//	ft_putnbr(i);
	//print_memory((unsigned char*)main_struct->map, MEM_SIZE);
	nanosleep((const struct timespec[]){{0, time}}, NULL);
}
 */