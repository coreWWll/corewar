//
// Created by Denys Burtnjak on 6/17/17.
//

#include "visualisation.h"

void	w_print_usage(WINDOW *win)
{
	wprintw(win, "%-35s %s\n", "PAUSE / PLAY:", "/SPACE/");
	wprintw(win, "%-35s %s\n", "STEP one cycle:", "s");
	wprintw(win, "%-35s %s\n", "STEP over 100 cycles:", "h");
	wprintw(win, "%-35s %s\n", "STEP over 1000 cycles:", "t");
	wprintw(win, "%-35s %s\n", "Increment speed", "+");
	wprintw(win, "%-35s %s\n", "Decrement speed", "-");


	init_pair(RED_TEXT_ON_CYAN, COLOR_RED, COLOR_CYAN);
	wattron(win, COLOR_PAIR(RED_TEXT_ON_CYAN));
	wprintw(win, "\n\n\n\n\npowered by: arepnov, dburtnja, okres, yyefimov\n");
	wprintw(win, "all rights reserved");
	wattroff(win, COLOR_PAIR(RED_TEXT_ON_CYAN));
	wrefresh(win);
}