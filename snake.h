#ifndef SNAKE
#define SNAKE

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

void snake_init(snake *s);
void snake_destroy(snake *s);
void snake_append_body(snake *s, point p);

#endif
