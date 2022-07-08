CC=gcc
CFLAGS=-Wall -g

all: vocals

vocals: replacevocals.o
	$(CC) $(CFLAGS) replacevocals.o -o vocals

replacevocals.o: replacevocals.c
	$(CC) $(CFLAGS) -c replacevocals.c

clean:
	rm *.out *.o vocals
