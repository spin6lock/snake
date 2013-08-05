#include <stdlib.h>
#include "snake.h"

bool point_compare(point *p1, point *p2) {
	if (p1->x == p2->x && p1->y == p2->y) return true;
	return false;
}

void snake_init(snake *s) {
	s->head = NULL;
	s->size = 0;
	s->direction = NULL;
}

void snake_destroy(snake *s) {
	if (s->direction) {
		free(s->direction);
	}
	s->direction = NULL;
	s->size = 0;
	linked_node *head = s->head;
	for(;head != NULL;) {
		linked_node *tmp = head->next;
		free(head);
		head = tmp;
	}
	s->head = NULL;
}

void snake_append_body(snake *s, point p) {
	linked_node *head = s->head;
	linked_node *prev = head;
	linked_node *new_node = malloc(sizeof(linked_node));
	new_node->p = p;
	new_node->next = NULL;

	if (s->head == NULL) {
		s->head = new_node;
	} else {
		while(head != NULL) {
			prev = head;
			head = head->next;
		}
		prev->next = new_node;
	}
	s->size++;
}
