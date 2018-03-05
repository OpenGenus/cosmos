#for C
CFLAGS = -Wall -Wextra -lm -lgraph
C_SOURCES := $(shell find -name '*.c')

c: $(C_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) 

