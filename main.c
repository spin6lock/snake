#include "/usr/include/ncursesw/ncurses.h"

int maxy, maxx;
void decrease(int *num) {
	if (*num > 0) {
		(*num)--;
	}
}

void increase(int *num) {
	if (*num < maxy - 1) {
		(*num)++;
	}
}

void get_maxyx() {
	getmaxyx(stdscr, maxx, maxy);
	mvprintw(0, 0, "maxx:%d, maxy:%d\n", maxx, maxy);
}

int main(void)
{
	WINDOW* win;
	initscr();
	curs_set(FALSE);
	noecho();
	get_maxyx();
	
	int key = 0;
	int row = 0;
	int col = 0;
	while ((char)key != 'q'){
		key = getch();
		switch(key) {
		case 'h':
			decrease(&col);
			break;
		case 'j':
			increase(&row);
			break;
		case 'k':
			decrease(&row);
			break;
		case 'l':
			increase(&col);
			break;
		default:
			continue;
		}
		wclear(stdscr);
		mvprintw(row, col, "#");
		refresh();
	}
	endwin();
	return 0;
}
