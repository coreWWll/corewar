//
// Created by Denys Burtnjak on 6/30/17.
//

#include "visualisation.h"

int		check_input_char(t_vm *main_struct, int c)
{
	if (c == 's')
	{
		main_struct->vis->pause = TRUE;
		return (TRUE);
	}
	if (c == 't')
	{
		main_struct->vis->pause = FALSE;
		main_struct->vis->t_pause = main_struct->cycle;
		return (TRUE);
	}
	if (c == 'h')
	{
		main_struct->vis->pause = FALSE;
		main_struct->vis->h_pause = main_struct->cycle;
		return (TRUE);
	}
	return (FALSE);
}

int		read_when_play_and_pause(t_vm *main_struct, int c)
{
	if (c == 'e')
	{
		main_struct->vis->go_to_end = TRUE;
		return (TRUE);
	}
	else if (c == 'q')
	{
		stop_vis_and_exit(main_struct);
		return (TRUE);
	}
	return (FALSE);
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
		if (read_when_play_and_pause(main_struct, c))
			break ;
		if (check_input_char(main_struct, c))
			break ;
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
	read_when_play_and_pause(main_struct, c);
	while (wgetch(main_struct->vis->arena) != EOF);	/*delete chars in stdin*/
	wprintw(main_struct->vis->param, "\t\t== PLAY ==\n");
}