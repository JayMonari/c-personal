CC=gcc
CFLAGS=-Wall -g

all: mainapp

mainapp: pointers.o
	$(CC) $(CFLAGS) pointers.o -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm *.o mainapp
