#include <stdlib.h>
#include "ncurses.h"
#include "snake.h"

int maxy, maxx;
void decrease(int *num) {
	if (*num > 0) {
		(*num)--;
	}
}

void get_maxyx() {
	getmaxyx(stdscr, maxx, maxy);
	mvprintw(0, 0, "maxx:%d, maxy:%d\n", maxx, maxy);
}

point *get_new_xy_by_direction(point p, point direction) {
	if (0 > p.x + direction.x || p.x + direction.x >= maxx) {
		return NULL;
	}
	if (0 > p.y + direction.y || p.y + direction.y >= maxy) {
		return NULL;
	}
	point *newp = malloc(sizeof(point));
	newp->x = p.x + direction.x;
	newp->y = p.y + direction.y;
	return newp;
}

void get_random_xy(int *x, int *y) {
	*x = random() % maxx;
	*y = random() % maxy;
}

void draw_on_screen() {
}

void change_snake_state(snake *s, point direction) {
	if (s->direction == NULL) {
		s->direction = malloc(sizeof(point));
	}
	if ((s->direction->x + direction.x) == 0
		&& (s->direction->y + direction.y) == 0) {
		fprintf(stderr, "forbidden move");
		return;
	}
	s->direction->x = direction.x;
	s->direction->y = direction.y;
	point *newp = get_new_xy_by_direction(s->head->p, direction);
	if (!newp) return;
	snake_append_body(s, *newp);
	if (s->size > 20) {
		snake_remove_body(s);
	}
}

void draw_snake(snake *s) {
	for(linked_node *head = s->head; head; head = head->next) {
		mvprintw(head->p.x, head->p.y, "*");
	}
}

void input_loop() {
	int key = 0;
	int row = 0;
	int col = 0;
	point direction;
	snake s[1];
	snake_init(s);
	snake_append_body(s, (point){0, 0});
	while ((char)key != 'q'){
		key = getch();
		switch(key) {
		case 'h':
			direction = (point){0, -1};
			break;
		case 'j':
			direction = (point){1, 0};
			break;
		case 'k':
			direction = (point){-1, 0};
			break;
		case 'l':
			direction = (point){0, 1};
			break;
		default:
			continue;
		}
		change_snake_state(s, direction);
		wclear(stdscr);
		draw_snake(s);
		refresh();
	}
	snake_destroy(s);
}

int main(void)
{
	initscr();
	curs_set(FALSE);
	noecho();
	get_maxyx();
	
	input_loop();

	endwin();
	return 0;
}
