all:
	clang snake.c main.c -o main -lncursesw -std=gnu99 -g
	./main

test:
	clang snake.c snake_test.c -o snake_test -std=gnu99 -g
	./snake_test

memcheck:
	clang snake.c snake_test.c -o snake_test -std=gnu99 -g
	valgrind -q ./snake_test

clean:
	rm -f *core*
	rm -f main
	rm -f snake_test
