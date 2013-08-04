#include "/usr/include/ncursesw/ncurses.h"

int main(void)
{
	initscr();
	int key = 0;
	int row = 0;
	while ((char)key != 'k'){
		key = getch();
		mvprintw(row, 0, "Entered = %x", key);
		refresh();
		row++;
	}
	endwin();
	return 0;
}
