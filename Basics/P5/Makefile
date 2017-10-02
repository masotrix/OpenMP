CC= gcc
CFLAGS= -g -pg -fopenmp -O3

all: run1 run2

run1: main1.o
		$(CC) $^ -o $@ $(CFLAGS)

run2: main2.o
		$(CC) $^ -o $@ $(CFLAGS)

main1.o: main.c
		$(CC) $< -c -o  $@ $(CFLAGS)

main2.o: main2.c
		$(CC) $< -c -o $@ $(CFLAGS)
