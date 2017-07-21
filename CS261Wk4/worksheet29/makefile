CC=gcc
CFLAGS=-Wall -std=c99

all: prog

prog: worksheet29.o worksheet29main.o
	gcc -g -Wall -std=c99 -o prog worksheet29.o worksheet29main.o
worksheet29.o: worksheet29.c worksheet29.h
	gcc -g -Wall -std=c99 -c worksheet29.c
worksheet29main.o: worksheet29main.c worksheet29.h
	gcc -g -Wall -std=c99 -c worksheet29main.c

clean:
	-rm *.o

cleanall: clean
	-rm prog