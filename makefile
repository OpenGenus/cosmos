#for C
CFLAGS = -Wall -Wextra -lm -lgraph
C_SOURCES := $(shell find -name 'code/*.c')

c: $(C_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) 