#for C
CFLAGS = -Wall -Wextra -lm 
C_SOURCES := $(shell find -name '*.c')

c: $(C_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) 

