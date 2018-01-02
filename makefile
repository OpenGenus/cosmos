#for C
CFLAGS = -Wall -Wextra
C_SOURCES := $(shell find -name '*.c')

c: $(C_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) 


#for cpp
CXXFLAGS = -Wall
CPP_SOURCES := $(shell find -name '[^test_]*.cpp')
CPP_TEST_SOURCES := $(shell find -name 'test_*.cpp')
CATCH_PCH_SOURCE = 'test/c++/catch_pch.o'

cpp:
	@echo '---compiling source files---'
	@$(foreach CPP_SOURCE,$(CPP_SOURCES),echo $(CPP_SOURCE);$(CXX) -c $(CPP_SOURCE) $(CXXFLAGS);echo $(CPP_SOURCE);)
	@echo '---compiling test files---'
	@$(foreach CPP_SOURCE,$(CPP_TEST_SOURCES),echo $(CATCH_PCH_SOURCE) $(CPP_TEST_SOURCE);$(CXX) $(CATCH_PCH_SOURCE) $(CPP_SOURCE))
