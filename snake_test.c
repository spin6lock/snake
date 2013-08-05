#include <stdlib.h>
#include <assert.h>
#include "snake.h"

void test_point() {
	point a = {1, 2};
	assert(a.x == 1);
	assert(a.y == 2);
}

void test_snake() {
	snake s[1];
	snake_init(s);
	assert(s->head == NULL);
	assert(s->size == 0);
	assert(s->direction == NULL);

	point p1 = {1, 2};
	snake_append_body(s, p1);
	assert(s->size == 1);
	assert(point_compare(&(s->head->p), &p1));

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
