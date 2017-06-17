//
// Created by Denys Burtnjak on 6/17/17.
//


#include "visualisation.h"

void	w_print_char(unsigned char c, WINDOW *win, char color)
{
	char	p_color;

	if (color < 0)
		p_color = COL_CAR;
	else
		p_color = color;
	wattron(win, COLOR_PAIR(p_color));
	waddch(win, c);
	wattroff(win, COLOR_PAIR(COL_ARENA));
}

void	w_put_nbr(unsigned char c, WINDOW *win, char color)
{
	unsigned char	print;

	if (c >= 16)
	{
		w_put_nbr(c / (char)16, win, color);
		w_put_nbr(c % (char)16, win, color);
	}
	else
	{
		if (c < 10)
			print = (unsigned char)(c + '0');
		else
			print = (unsigned char)((c - 10) + 'a');
		w_print_char(print, win, color);
	}
}

void	w_print_arena(t_vm *main_struct)
{
	int		i;
	WINDOW	*win;

	i = 0;
	win = main_struct->vis->arena;
	while (i < MEM_SIZE)
	{
		if (main_struct->map[i] < 16)
			w_print_char('0', win, main_struct->color[i]);
		w_put_nbr((unsigned char)main_struct->map[i], win,
				main_struct->color[i]);
		i++;
		if (i % CHAR_IN_ROW == 0 && i != 0)
			waddch(win, '\n');
		else
			waddch(win, ' ');
	}
}