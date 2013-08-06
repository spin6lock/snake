#include <stdlib.h>
#include <stdio.h>
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
	linked_node *new_node = malloc(sizeof(linked_node));
	new_node->p = p;
	new_node->next = NULL;

	if (s->head == NULL) {
		s->head = new_node;
	} else {
		new_node->next = head;
		s->head = new_node;
	}
	s->size++;
}

void snake_print(snake *s) {
	printf("snake size: %d\n", s->size);
	printf("snake head direction:\n");
	if (s->direction) {
		printf("(%d, %d)\n", s->direction->x, s->direction->y);
	}
	printf("snake body:");
	for (linked_node *head = s->head; head; head = head->next) {
		if (head) {
			printf("(%d, %d)\n", head->p.x, head->p.y);
		}
	}
}
