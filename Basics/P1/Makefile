CC= gcc
CFLAGS= -g -pg -fopenmp -Wall

all: run runO3

run: main1.o
		$(CC) $^ -o $@ $(CFLAGS)

runO3: main2.o
		$(CC) $^ -o $@ $(CFLAGS)

main1.o: main.c
		$(CC) $< -c -o  $@ -O0 $(CFLAGS)

main2.o: main.c
		$(CC) $< -c -o $@ -O3 $(CFLAGS)
