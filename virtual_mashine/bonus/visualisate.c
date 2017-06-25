//
// Created by Denys Burtnjak on 6/17/17.
//

#include "visualisation.h"

void	change_time(t_vm *main_struct, int c)
{
	if (c == '-' && main_struct->time + 1000 < 1000000)
		main_struct->time += 1000;
	else if (c == '+' && main_struct->time - 1000 > 0)
		main_struct->time -= 1000;
}

void	pause_vis(t_vm *main_struct)
{
	int c;

	main_struct->vis->pause = FALSE;
	wprintw(main_struct->vis->param, "\t\t== PAUSE ==\n");
	w_print_arena(main_struct);
	w_print_param(main_struct);
	refresh_all(main_struct->vis);
	nodelay(main_struct->vis->arena, FALSE);
	while ((c = wgetch(main_struct->vis->arena)) != ' ')
	{
		if (c == 's')
		{
			main_struct->vis->pause = TRUE;
			break ;
		}
		werase(main_struct->vis->param);
		change_time(main_struct, c);
		wprintw(main_struct->vis->param, "\t\t== PAUSE ==\n");
		w_print_param(main_struct);
		wrefresh(main_struct->vis->param);
	}
	nodelay(main_struct->vis->arena, TRUE);
}

void	read_commands(t_vm *main_struct)
{
	int		c;

	c = wgetch(main_struct->vis->arena);
	if (c == ' ' || main_struct->vis->pause == TRUE)
		pause_vis(main_struct);
	change_time(main_struct, c);
	while (wgetch(main_struct->vis->arena) != EOF);
	wprintw(main_struct->vis->param, "\t\t== PLAY ==\n");
}

void	visualisate(t_vm *main_struct)
{
	read_commands(main_struct);
	w_print_arena(main_struct);
	w_print_param(main_struct);
	refresh_all(main_struct->vis);
	erase_all(main_struct->vis);
	usleep((useconds_t)main_struct->time);
}