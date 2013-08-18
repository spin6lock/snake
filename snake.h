#ifndef SNAKE
#define SNAKE
#include <stdbool.h>

typedef struct point_s {
	int x;
	int y;
} point;

typedef struct linked_node_s {
	point p;
	struct linked_node_s *next;
} linked_node;

typedef struct snake_s {
	linked_node *head;
	int size;
	point *direction;
} snake;

bool point_compare(point *p1, point *p2);
void snake_init(snake *s);
void snake_destroy(snake *s);
void snake_append_body(snake *s, point p);
void snake_remove_body(snake *s);

#endif
