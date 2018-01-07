#for C
CFLAGS = -Wall -Wextra 
LINKER_FLAGS = -lSDL
C_SOURCES := $(shell find -name '*.c')

c: $(C_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) 


#for cpp
CXXFLAGS = -Wall -Wextra
CPP_SOURCES := $(shell find -name '*.cpp')

cpp: $(CPP_SOURCES)
	$(CXX) -o $@ $^ $(CXXFLAGS)  
