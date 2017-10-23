

c:
	CFLAGS = -Wall
	SOURCES := $(shell find -name '*.c')
	$(CC) -o $@ $^ $(CFLAGS) 

cpp:
	CFLAGS = -Wall
	SOURCES := $(shell find -name '*.cpp')
	$(CC) -o $@ $^ $(CFLAGS) 
