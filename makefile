#for C
CFLAGS = -Wall -Wextra -lm 
C_SOURCES := $(shell find -name '*.c')

c: $(C_SOURCES)
	$(CC) -o $@ $^ $(CFLAGS) 


#for cpp
CXXFLAGS = -Wall
CPP_SOURCES := $(shell find -name '[^test_]*.cpp')
CPP_TEST_SOURCES := $(shell find -name 'test_*.cpp')
CATCH_MAIN_CONFIG_SOURCE = 'test/c++/catch_pch.cpp'

cpp:
	@echo '---compiling source files---'
	@$(foreach CPP_SOURCE,$(CPP_SOURCES),echo $(CXX) -c $(CXXFLAGS) $(CPP_SOURCE); \
											  $(CXX) -c $(CXXFLAGS) $(CPP_SOURCE);)
	@echo '---compiling test files---'
	@$(foreach CPP_TEST_SOURCE,$(CPP_TEST_SOURCES),echo $(CXX) $(CXXFLAGS) $(CATCH_MAIN_CONFIG_SOURCE) $(CPP_TEST_SOURCE); \
														$(CXX) $(CXXFLAGS) $(CATCH_MAIN_CONFIG_SOURCE) $(CPP_TEST_SOURCE);)