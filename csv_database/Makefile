CC=gcc
CFLAGS=-Wall -g

all: sbrief

sbrief: sb.o
	$(CC) $(CFLAGS) sb.o -o sbrief

sb.o: sb.c
	$(CC) $(CFLAGS) sb.c -c

clean:
	rm *.o a.out sbrief
