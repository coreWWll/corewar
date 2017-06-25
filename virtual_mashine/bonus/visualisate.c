//
// Created by Denys Burtnjak on 6/17/17.
//

#include "visualisation.h"

void	read_comands(t_vm *main_struct, int pause)
{
	char	c;

	c = (char)wgetch(main_struct->vis->arena);
	if (c == ' ' || pause == TRUE)
	{
		wprintw(main_struct->vis->param, "\t\t== PAUSE ==\n");
		w_print_arena(main_struct);
		w_print_param(main_struct);
		refresh_all(main_struct->vis);
		while (wgetch(main_struct->vis->arena) != ' ');
	}
	else if (c == '-' && main_struct->time + 1000 < 1000000)
		main_struct->time += 1000;
	else if (c == '+' && main_struct->time - 1000 > 0)
		main_struct->time -= 1000;
	while (wgetch(main_struct->vis->arena) != EOF);
	wprintw(main_struct->vis->param, "\t\t== PLAY ==\n");
}

void	visualisate(t_vm *main_struct)
{
	erase_all(main_struct->vis);
	read_comands(main_struct, main_struct->cycle == 0 ? TRUE : FALSE);
	w_print_arena(main_struct);
	w_print_param(main_struct);
	refresh_all(main_struct->vis);
	usleep((useconds_t)main_struct->time);
}