BINARY=bin
CODEDIRS=. lib
INCDIRS=. ./include/ # can be list

CC=gcc
# generate files that encode `make` rules for the .h dependencies
DEPFLAGS=-MP -MD
OPT=-O0
# D = directories in INCDIRS generate (-I) it with flags
# e.g. -I. -I./include/
CFLAGS=-Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D) $(OPT) $(DEPFLAGS))

# wildcard expands * because % is used otherwise?
# ./geom.c ./lib/gd.c
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
# regexp replacement -- pattern substitution
# ./geom.o ./lib/gd.o
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
# ./gd.c ./lib/gd.d
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

#
# target: dependencies
#(\t)action

all: $(BINARY)

$(BINARY): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $^ -lm # only needed for math library

# only want the .c file dependencies here, thus $< instead of $^
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

distribute: clean
	@tar zcvf dist.tgz *

# @ silences the printing of the command
# # $(info...) prints output
diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git diff --stat

-include $(DEPFILES)
