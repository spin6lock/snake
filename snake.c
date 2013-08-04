#include <stdlib.h>
#include "snake.h"

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
}

void snake_append_body(snake *s, point p) {
	linked_node *head = s->head;
	linked_node *prev = head;
	while(head != NULL) {
		prev = head;
		head = head->next;
	}
	linked_node *new_node = malloc(sizeof(linked_node));
	new_node->p = p;
	new_node->next = NULL;
	prev->next = new_node;
	s->size++;
}
