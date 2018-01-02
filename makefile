#for C
CFLAGS = -Wall -Wextra
C_SOURCES := $(shell find -name '*.c')

c: $(C_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) 


#for cpp
CXXFLAGS = -Wall
CPP_SOURCES := $(shell find -name '*.cpp')

cpp:
	@$(foreach CPP_SOURCE,$(CPP_SOURCES),$(CXX) -c $(CPP_SOURCE) $(CXXFLAGS);)  
