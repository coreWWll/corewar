//
// Created by Denys Burtnjak on 6/17/17.
//

#include "visualisation.h"

void	w_print_usage(WINDOW *win)
{
	wattron(win, COLOR_PAIR(COL_CAR));
	wprintw(win, "s");
	wattroff(win, COLOR_PAIR(COL_ARENA));
	wrefresh(win);
}