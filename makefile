CFLAGS = -Wall

SOURCES := $(shell find -name '*.c')

test: $(SOURCES)
	gcc -o $@ $^ $(CFLAGS) 
