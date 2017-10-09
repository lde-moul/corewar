#include <ncurses.h>
#include <stdlib.h>
#include "corewar.h"

int main(void)
{
	WINDOW *boite;
	int	i = 1;
	int	j = 2;

	initscr();
	boite= subwin(stdscr, 66, 195, 0, 0);
	box(boite, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
	while (i < 65)
	{
		move(i, 2);
		while (j < 193)
		{
			printw("%.2x ", 0);
			j += 3;
		}
		++i;
		j = 2;
	}
	refresh();
	getch();
	endwin();
	free(boite);
	 return 0;
}
