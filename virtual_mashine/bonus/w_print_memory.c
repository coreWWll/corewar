//
// Created by Denys Burtnjak on 6/17/17.
//


#include "visualisation.h"

void	w_put_nbr(unsigned char c, WINDOW *win)
{
	unsigned char	print;

	if (c >= 16)
	{
		w_put_nbr(c / (char)16, win);
		w_put_nbr(c % (char)16, win);
	}
	else
	{
		if (c < 10)
			print = (unsigned char)(c + '0');
		else
			print = (unsigned char)((c - 10) + 'a');
		waddch(win, print);
	}
}

void	w_print_arena(t_vm *main_struct)
{
	int		i;
	WINDOW	*win;
	char	color;

	i = 0;
	win = main_struct->vis->arena;
	while (i < MEM_SIZE)
	{
		color = (char)(main_struct->color[i] == 0 ? COL_ARENA :
				  main_struct->color[i]);
		wattron(win, COLOR_PAIR(color));
		if (main_struct->map[i] < 16)
			waddch(win, '0');
		w_put_nbr((unsigned char)main_struct->map[i], win);
		i++;
		if (i % CHAR_IN_ROW == 0 && i != 0)
			waddch(win, '\n');
		else
			waddch(win, ' ');
		wattroff(win, COLOR_PAIR(COL_ARENA));
	}
}