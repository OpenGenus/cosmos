#for C
CFLAGS = -Wall -Wextra
C_SOURCES := $(shell find -name '*.c')

c: $(C_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) 


#for cpp
CXXFLAGS = -Wall
CPP_SOURCES := $(shell find -name '[^test_]*.cpp')

cpp:
	@echo '---compiling source files---'
	@$(foreach CPP_SOURCE,$(CPP_SOURCES),echo $(CPP_SOURCE);$(CXX) -c $(CPP_SOURCE) $(CXXFLAGS);echo $(CPP_SOURCE);)
