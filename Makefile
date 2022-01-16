
CC = gcc

all:
	$(CC) main.c stack.c -o a

clean:
	rm -rf *.o
	rm -rf a

