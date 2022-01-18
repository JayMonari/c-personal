
CC=gcc
CFLAGS=-Wall -g

all: mainapp

mainapp: main.c %.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm a.out *.o mainapp
