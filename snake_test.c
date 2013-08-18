#include <stdlib.h>
#include <assert.h>
#include "snake.h"

void test_point() {
	point a = {1, 2};
	assert(a.x == 1);
	assert(a.y == 2);
}

void test_snake_append_body() {
	snake s[1];
	snake_init(s);
	point p1 = {1, 2};
	snake_append_body(s, p1);
	assert(s->size == 1);
	assert(point_compare(&(s->head->p), &p1));

	point p2 = {3, 4};
	snake_append_body(s, p2);
	assert(s->head->p.x == 3);	// (3, 4) -> (1, 2)
	assert(s->head->p.y == 4);
	linked_node *next = s->head->next;
	assert(next->p.x == 1);
	assert(next->p.y == 2);

	printf("test append body:\n");
	snake_print(s);
	printf("\n");
}

void test_snake_remove_body() {
	snake s[1];
	snake_init(s);
	point p1 = {3, 4};
	point p2 = {1, 2};
	snake_append_body(s, p1);
	snake_append_body(s, p2);

	snake_remove_body(s);
	assert(s->head->p.x == 3);
	assert(s->head->p.y == 4);
	assert(s->size == 1);
	assert(s->head->next == NULL);

	printf("test remove body:\n");
	snake_print(s);
	printf("\n");
}

void test_snake() {
	snake s[1];
	snake_init(s);
	assert(s->head == NULL);
	assert(s->size == 0);
	assert(s->direction == NULL);

	test_snake_append_body();
	test_snake_remove_body();

	snake_destroy(s);
	assert(s->head == NULL);
	assert(s->size == 0);
	assert(s->direction == NULL);
}

int main() {
	test_point();
	test_snake();
	return 0;
}
