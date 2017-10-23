CFLAGS = -Wall

SOURCES := $(shell find -name '*.c')

test: $(SOURCES)
	CC -o $@ $^ $(CFLAGS) 
