CFLAGS = -Wall
C_SOURCES := $(shell find -name '*.c')

c: $(C_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) 

CPP_SOURCES := $(shell find -name '*.cpp')

cpp: $(CPP_SOURCES)
	$(CXX) -o $@ $^ $(CFLAGS) 
