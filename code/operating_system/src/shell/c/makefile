all: Shell

B013040049_Shell: Shell.o
	gcc -o Shell Shell.o

B013040049_Shell.o:
	gcc -c Shell.c

dep:
	gcc -M *.c > .depend

clean:
	rm -f *.o Shell .depend
