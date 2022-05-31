CC=gcc
CFLAGS=-Wall -g

all: app

app: leak.o
	$(CC) $(CFLAGS) leak.o -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm *.o app
