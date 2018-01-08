 #for C		 #for C
-CFLAGS = -Wall -Wextra		+CFLAGS = -Wall -Wextra 
+LINKER_FLAGS = -lSDL
 C_SOURCES := $(shell find -name '*.c')		 C_SOURCES := $(shell find -name '*.c')
 		 
 c: $(C_SOURCES)		 c: $(C_SOURCES)
 	$(CC) -o $@ $^ $(CFLAGS) 		 	$(CC) -o $@ $^ $(CFLAGS) 
 		 
 		 
 #for cpp		 #for cpp
 CXXFLAGS = -Wall -Wextra		 CXXFLAGS = -Wall -Wextra
 CPP_SOURCES := $(shell find -name '*.cpp')		 CPP_SOURCES := $(shell find -name '*.cpp')
 		 
 cpp: $(CPP_SOURCES)		 cpp: $(CPP_SOURCES)
 	$(CXX) -o $@ $^ $(CXXFLAGS)  