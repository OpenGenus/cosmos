#for C
CFLAGS=-Wall -Wextra
sources := $(shell find code/ -name \*.c)
objects := $(sources:.c=.o)

c: $(objects)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@
	$(RM) $@
