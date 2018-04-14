#for C
CFLAGS = -Wall -Wextra -lm -lgraph
C_SOURCES := $(shell find code -name '*.c')

c: $(C_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) 