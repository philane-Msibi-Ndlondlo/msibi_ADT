
CC = gcc
FLAGS = -ggdb3

all:
	$(CC) main.c map.c linked_list.c stack.c -o a

build:
	$(CC) $(FLAGS)  main.c map.c linked_list.c stack.c -o a



clean:
	rm -rf *.o
	rm -rf a

