CC=gcc
CFLAGS=-c -Wall
ATTR=-O3 -Ofast -funroll-loops -ffp-contract=fast

all: start
start: sort.o main.o
	$(CC) $(ATTR) sort.o main.o

sort.o: sort.c
	$(CC) $(CFLAGS) $(ATTR) sort.c

main.o: main.c
	$(CC) $(CFLAGS) $(ATTR) main.c

clean:
	rm -rf *.o *.out