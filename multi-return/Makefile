CC=clang

CFLAGS=-Wall -g
BINS=example1

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -r $(BINS) *.dSYM
