
CC = gcc

all:
	$(CC) main.c linked_list.c stack.c -o a

clean:
	rm -rf *.o
	rm -rf a

