#for C
CFLAGS = -Wall -Wextra -lm -lgraph -lpthread
C_SOURCES := $(shell find code -name '*.c')

c: $(C_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) 
