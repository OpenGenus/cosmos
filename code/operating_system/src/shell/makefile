#Example written by Guillermo Garrido

#A macro allows you to define "variables" which are substituted into the makefile. 
#It is recommended that you use them, especially in large makefiles. 

#This macro is used to call the object files associated with your project.
OBJS = a.o b.o c.o

#The name of the compiler is 'CC'. The keyword 'g++' shows that it will compile C++ code.
#Likewise, using the keyword 'gcc' shows that would compile C code.
CC = g++

#This allows you to include debugging information into your executable file (in this case, p1), in order for you
#to access certain utilities (e.g. gdb) to debug your code.
DEBUG = -g

#This flag is responsible for compiling and creating object files. 
#The '-Wall' keyword tells your compiler to print all the warnings associated with your code.
CFLAGS = -Wall -c $(DEBUG)

#This flag is used for linking.
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

a.o : a.h a.cpp c.h
	$(CC) $(CFLAGS) a.cpp

b.o : b.h b.cpp c.h
	$(CC) $(CFLAGS) b.cpp

c.o : c.h c.cpp
	$(CC) $(CFLAGS) c.pp

clean:
	\rm  *.o *~  p1
  
tar:
	tar cfv p1.tar b.h b.cpp c.h c.cpp 
