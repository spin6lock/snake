all:
	gcc main.c -o main -lncursesw -std=gnu99
	./main

test:
	gcc snake.c snake_test.c -o snake_test -std=gnu99 -g
	./snake_test

memcheck:
	gcc snake.c snake_test.c -o snake_test -std=gnu99 -g
	valgrind -q ./snake_test
